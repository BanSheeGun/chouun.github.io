// Name : ModInt 自取余整型
// Copyright : fateud.com
#ifndef MODINT_H_
#define MODINT_H_ 20150912L
#include <iostream>
#ifndef CSL_MATH_H_
#pragma message("need : csl_math.h")
#include <csl_math.h>
#endif
namespace csl {
  template<typename _Tp,_Tp& _Mod>
  class modint {
  public:
    typedef _Tp value_type;
    typedef _Tp& reference;
    typedef modint<_Tp,_Mod> _Self;

    modint() :
        x() {
    }
    modint(value_type y) :
        x(y % _Mod) {
      if(x < 0) x = x + _Mod;
    }

    _Self& operator +=(_Self b) {
      if((x += b.x) >= _Mod) x -= _Mod;
      return *this;
    }
    _Self& operator -=(_Self b) {
      if((x += _Mod - b.x) >= _Mod) x -= _Mod;
      return *this;
    }
    _Self& operator *=(_Self b) {
      x = x * b.x % _Mod;
      return *this;
    }
    _Self& operator /=(_Self b) {
      x = x * csl::inv(b.x, _Mod) % _Mod;
      return *this;
    }

    _Self operator +(_Self b) {
      return _Self(*this) += std::move(b);
    }
    _Self operator -(_Self b) {
      return _Self(*this) -= std::move(b);
    }
    _Self operator *(_Self b) {
      return _Self(*this) *= std::move(b);
    }
    _Self operator /(_Self b) {
      return _Self(*this) /= std::move(b);
    }

    reference operator *() {
      return x;
    }
    bool operator !() const {
      return x == 0;
    }
    friend bool operator !=(const _Self& a,value_type _x) {
      return a.x != _x;
    }
    friend bool operator !=(value_type _x,const _Self& a) {
      return a.x != _x;
    }

    friend std::ostream& operator <<(std::ostream& os,const _Self& a) {
      return os << a.x;
    }
    friend std::istream& operator >>(std::istream& is,const _Self& a) {
      return is >> a.x;
    }

  private:
    value_type x;
  };
} // namespace csl
#endif /* MODINT_H_ */
