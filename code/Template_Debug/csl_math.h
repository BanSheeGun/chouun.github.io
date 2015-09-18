// Name : Mathematical Computation 数学计算
// Copyright : fateud.com

#ifndef CSL_MATH_H_
#define CSL_MATH_H_
#define CSL_MATH_H_VERSION 20150918L

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

  template <typename _Tp>
  inline _Tp
  mul(_Tp a, _Tp b, const _Tp m)
  {
    _Tp c = 0;
    for (a %= m; b; b >>= 1, a = (a << 1) % m)
      if (b & 1) c = (c + a) % m;
    return c;
  }

  template <typename _Val, typename _Key>
  inline _Val
  pow(_Val c, _Val n, const _Key k)
  {
    for (; k; n = n * n, k >>= 1)
      if (k & 1) c = c * n;
    return c;
  }

  template <typename _Val, typename _Key>
  inline _Val
  pow(_Val c, _Val n, _Key k, const _Val m)
  {
    for (n %= m; k; n = n * n % m, k >>= 1)
      if (k & 1) c = c * n % m;
    return c;
  }

  template <typename _Val, typename _Key>
  inline _Val
  inv(_Val x, const _Key m)
  { return csl::pow(_Val(1), x, m - 2, m); }
} // namespace csl

#endif /* CSL_MATH_H_ */
