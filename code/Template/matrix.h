// Name : Matrix 矩阵
// Copyright : fateud.com
#ifndef MATRIX_H_
#define MATRIX_H_ 20150912L
#include <vector>
#include <iostream>
namespace csl {
  template<typename _Tp>
  class matrix {
  public:
    typedef _Tp value_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;

    typedef std::size_t size_type;
    typedef csl::matrix<_Tp> _Self;

    matrix() :
        data(), h(), w() {
    }
    matrix(const _Self& x) {
      *this = x;
    }
    matrix(_Self&& x) {
      *this = std::move(x);
    }
    matrix(size_type h,size_type w) :
        data(h * w), h(h), w(w) {
    }

    static _Self identity(size_type n) {
      _Self res(n, n);
      for(size_type i = 0; i < n; ++i)
        res[i][i] = value_type(1);
      return std::move(res);
    }
    inline static _Self identity(const _Self& x) {
      return identity(x.h);
    }

    inline size_type height() const {
      return h;
    }
    inline size_type width() const {
      return w;
    }
    inline value_type* operator [](size_type x) {
      return &data[x * w];
    }
    inline const value_type* operator [](size_type x) const {
      return &data[x * w];
    }

    _Self& operator +=(const _Self& b) {
      for(size_type i = 0, n = height() * width(); i < n; ++i)
        data[i] += b.data[i];
      return *this;
    }
    _Self& operator *=(const _Self& b) {
      _Self c(h, b.w);
      for(size_type i = 0; i < h; ++i) {
        for(size_type k = 0; k < w; ++k) {
          value_type tmp = (*this)[i][k];
          if(!tmp) continue;
          for(size_type j = 0; j < b.w; ++j)
            c[i][j] += tmp * b[k][j];
        }
      }
      return (*this) = std::move(c);
    }
    _Self operator +(const _Self& b) const {
      return _Self(*this) += b;
    }
    _Self operator *(const _Self& b) const {
      return _Self(*this) *= b;
    }

    friend std::ostream& operator <<(std::ostream &os,const _Self& a) {
      size_type n = a.height();
      size_type m = a.width();
      for(size_type i = 0; i < n; ++i) {
        for(size_type j = 0; j < m; ++j)
          os << a[i][j] << " ";
        os << std::endl;
      }
      return os;
    }
  private:
    std::vector<_Tp> data;
    size_type h, w;
  };
} // namespace csl
#endif /* MATRIX_H_ */
