// Name : Mathematical Computation 数学计算
// Copyright : fateud.com

#ifndef CSL_MATH_H_
#define CSL_MATH_H_ 20151008L

#include <functional>

namespace csl {
  /*
   * greatest common divisor
   */
  template<typename _Tp>
  inline _Tp gcd(_Tp a,_Tp b) {
    for(_Tp c = _Tp(); b;)
      c = a % b, a = std::move(b), b = std::move(c);
    return a;
  }
  /*
   * extended Euclidean algorithm
   * solve ax + by = gcd(a,b)
   */
  template<typename _Tp>
  _Tp gcd(_Tp a,_Tp b,_Tp& x,_Tp& y) {
    if(b) {
      _Tp r = gcd(b, a % b, y, x);
      return y -= a / b * x, r;
    }
    return x = 1, y = 0, a;
  }

  /**
   * least common multiple
   */
  template<typename _Tp>
  inline _Tp lcm(_Tp a,_Tp b) {
    return a / gcd(a, b) * b;
  }

  /**
   * divide and conquer algorithms (with modulo operation)
   */
  template<typename _Val,typename _Key,typename _Mod,typename _Op1,typename _Op2>
  inline _Val dnc(_Val c,_Val n,_Key k,_Mod m,const _Op1& op1,const _Op2& op2) {
    for(n = op2(n, m); k; n = op2(op1(n, n), m), k >>= 1)
      if(k & 1) c = op2(op1(c, n), m);
    return std::move(c);
  }

  /**
   * divide and conquer algorithms
   */
  template<typename _Val,typename _Key,typename _Op>
  inline _Val dnc(_Val c,_Val n,_Key k,const _Op& op) {
    for(; k; n = op(n, n), k >>= 1)
      if(k & 1) c = op(c, n);
    return std::move(c);
  }

  /**
   * return a * b (mod m)
   */
  template<typename _Val>
  inline _Val mul(_Val a,_Val b,_Val m) {
    return dnc(_Val(), a, b, m, std::plus<_Val>(), std::modulus<_Val>());
  }

  /**
   * return c * n ^ k
   */
  template<typename _Val,typename _Key>
  inline _Val pow(_Val c,_Val n,_Key k) {
    return dnc(c, n, k, std::multiplies<_Val>());
  }

  /**
   * return c * n ^ k (mod m)
   */
  template<typename _Val,typename _Key>
  inline _Val pow(_Val c,_Val n,_Key k,_Val m) {
    return dnc(c, n, k, m, std::multiplies<_Val>(), std::modulus<_Val>());
  }

  /**
   * return 1 / x (mod m)
   */
  template<typename _Val>
  inline _Val inv(_Val x,_Val m) {
    _Val p, q;
    return gcd(x, m, p, q), (p % m + m) % m;
  }

} // namespace csl

#endif /* CSL_MATH_H_ */
