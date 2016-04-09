// Name : Fast Fourier Transform 快速傅里叶变换
// Copyright : fateud.com
#ifndef FFT_H_
#define FFT_H_ 20160328L

#include <vector>
#include <complex>

#ifndef CSL_MATH_H_
#pragma message("need : csl_math.h");
#include <csl_math.h>
#endif

namespace csl {
  template< typename _Tp = std::complex<double> >
  class fft {
  public:
    typedef _Tp value_type;
    typedef std::size_t size_type;
    typedef std::vector<value_type> container;

    container operator () (container u, container v) const {
      size_type n = StripLeadingZero(u), m = StripLeadingZero(v);
      size_type d = n + m - 1, s = 1;
      while (s < d) s <<= 1;
      u.resize(s), this->operator()(u, 0);
      v.resize(s), this->operator()(v, 0);
      for (size_type i = 0; i < s; ++i) u[i] *= v[i];
      this->operator()(u, 1), u.resize(d);
      for (auto &ui : u) ui = std::round(ui.real());
      return std::move(u);
    }

    void operator () (container& a, bool inv) const {
      int n = a.size();
      for (int i = 1, j, t, k; i < n; ++i) {
        for (j = 0, t = i, k = n >> 1; k; k >>= 1, t >>= 1) j = (j << 1) | (t & 1) ;
        if (i < j) swap(a[i], a[j]) ;
      }
      for (int s = 2, ds = 1; s <= n; ds = s, s <<= 1) {
        typename value_type::value_type wo = (inv ? -1 : 1) * 2 * M_PI / s;
        value_type wn(std::cos(wo), std::sin(wo)), w(1, 0), t;
        for (int k = 0; k < ds; ++k, w = w * wn)
          for (int i = k; i < n; i += s)
            a[i + ds] = a[i] - (t = w * a[i + ds]), a[i] += t;
      }
      if (inv) for (auto &ai : a) ai /= n;
    }

    static size_type StripLeadingZero(container& value) {
      size_type n = value.size();
      while (n > 1 && norm(value[n - 1]) < .5) --n;
      return value.resize(n), n;
    }
  };
} // namespace csl
#endif /* FFT_H_ */
