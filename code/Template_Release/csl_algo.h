// Name : Algorithm 算法
// Copyright : fateud.com
#ifndef CSL_ALGO_H_
#define CSL_ALGO_H_
#define CSL_ALGO_H_VERSION 20150917L
#include <vector>
#include <functional>
namespace csl {
  static double M_EPS = 1e-8;
  inline int sgn(double __x)
  { return fabs(__x) < M_EPS ? 0 : (__x < 0 ? -1 : 1); }
  inline int cmp(double a, double b)
  { return sgn(a - b); }
  template <typename _Tp>
  struct less : public std::binary_function<_Tp, _Tp, _Tp> {
    _Tp operator () (const _Tp& __x, const _Tp& __y) const
    { return __x < __y ? __x : __y; }
  };
  template <typename _Tp>
  struct greater : public std::binary_function<_Tp, _Tp, _Tp> {
    _Tp operator () (const _Tp& __x, const _Tp& __y) const
    { return __x > __y ? __x : __y; }
  };
  namespace prime {
    std::vector<std::size_t> phi, mu, div, prm;
    void build(std::size_t __n) {
      phi.assign(__n, 0); mu.assign(__n, 0); div.assign(__n, 0);
      prm.reserve(__n >> 3); prm.clear(); phi[1] = 1; mu[1] = 1;
      for (std::size_t i = 2; i < __n; ++i) {
        if (!div[i]) phi[i]=i-1,mu[i]=-1,div[i]=i,prm.push_back(i);
        for (std::size_t j = 0, m = prm.size(); j < m; ++j) {
          if (double(i) * prm[j] >= __n) break;
          div[i*prm[j]]=prm[j];
          if (i % prm[j] == 0)
          { phi[i*prm[j]]=phi[i]*prm[j]; mu[i*prm[j]]=0; break; }
          else
          { phi[i*prm[j]]=phi[i]*(prm[j]-1); mu[i*prm[j]]=-mu[i]; }
        }
      }
    }
  } // namespace prime
  template <typename _Tp, typename _Comp >
  std::size_t isomorph_min(_Tp* data, std::size_t size, _Comp comp) {
    std::size_t i = 0, j = 1;
    for (std::size_t k; i < size && j < size;) {
      for (k = 0; data[i+k] == data[j+k] && k < size; ++k);
      if (k == size) return i;
      if (!comp(data[i+k], data[j+k])) std::swap(i, j);
      j = std::max(j + k + 1, i + 1);
    }
    return i;
  }
  template <typename _Tp, typename _Comp >
  std::size_t isomorph_max(_Tp* data, std::size_t size, _Comp comp) {
    std::size_t i = 0, j = 1;
    for (std::size_t k; i < size && j < size;) {
      for (k = 0; data[i+k] == data[j+k] && k < size; ++k);
      if (k == size) i = std::max(i, j), j = i + 1;
      else {
        if (!comp(data[i+k], data[j+k])) std::swap(i, j);
        j = std::max(j + k + 1, i + 1);
      }
    }
    return i;
  }
} // namespace csl
#endif /* CSL_ALGO_H_ */
