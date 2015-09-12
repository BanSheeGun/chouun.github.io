// Name : ModInt 自取余整型
// Copyright : fateud.com

#ifndef MODINT_H_
#define MODINT_H_
#define MODINT_H_VERSION 20150912L

#include <ostream>

namespace csl
{
  template <unsigned _Mod>
  class modint
  {
  public :
    // template parameter.
    typedef unsigned  value_type;

    typedef modint<_Mod> _Self;

  public : 
    // constructor & destructor.
    modint() : x() { }

    modint(long long __y)
    {
      register int __z = __y % _Mod;
      if (__z < 0) __z += _Mod;
      x = __z;
    }

  public : 
    // iterators.
  public :
    // capacity.
  public :
    // element access.
  public :
    // modifiers.
  public :
    // operator overloading.
    value_type&
    operator * ()
    { return x; }

    _Self&
    operator += (_Self b)
    {
      if ((x += b.x) >= _Mod) x -= _Mod;
      return *this;
    }

    _Self&
    operator -= (_Self b)
    {
      if ((x += _Mod - b.x) >= _Mod) x -= _Mod;
      return *this;
    }

    _Self&
    operator *= (_Self b)
    {
      x = (unsigned long long)x * b.x % _Mod;
      return *this;
    }

    _Self
    operator + (_Self b)
    { return _Self(*this) += b; }

    _Self
    operator - (_Self b)
    { return _Self(*this) -= b; }

    _Self
    operator * (_Self b)
    { return _Self(*this) *= b; }

    bool
    operator ! () const
    { return x == 0; }

    friend std::ostream&
    operator << (std::ostream& o, const _Self& a)
    {
      return o << a.x;
    }

  private :
    // member variable.
    value_type x;
  };

} // namespace csl

#endif /* MODINT_H_ */
