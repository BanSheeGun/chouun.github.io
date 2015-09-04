// Name : Mathematical Computation 数学计算
// Copyright : fateud.com

#ifndef CSL_MATH_H_
#define CSL_MATH_H_
#define CSL_MATH_H_VERSION 20150820L

namespace csl
{
  template <typename _Tp>
  inline _Tp
  gcd(_Tp a, _Tp b)
  {
    while (b) {
      _Tp t = a % b;
      a = b; b = t;
    }
    return a;
  }

  template <typename _Tp>
  _Tp
  gcd(_Tp a, _Tp b, _Tp& x, _Tp& y)
  {
    if (b) {
      _Tp r = gcd(b, a % b, y, x);
      return y = y - a / b * x, r;
    }
    return x = 1, y = 0, a;
  }

  template <typename _Tp, typename _Key>
  inline _Tp
  pow(_Tp c, _Tp n, _Key k)
  {
    for (; k; n = n * n, k >>= 1)
      if (k & 1) c = c * n;
    return c;
  }

  template <typename _Tp, typename _Key>
  inline _Tp
  pow(_Tp c, _Tp n, _Key k, _Tp m)
  {
    for (; k; n = n * n % m, k >>= 1)
      if (k & 1) c = c * n % m;
    return c % m;
  }

  template <typename _Tp>
  inline _Tp
  inv(_Tp x, _Tp m)
  {
    return csl::pow(_Tp(1), x, m - 2, m);
  }

} // namespace csl

#endif /* CSL_MATH_H_ */
