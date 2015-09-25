// Name : Matrix 矩阵
// Copyright : fateud.com

#ifndef MATRIX_H_
#define MATRIX_H_
#define MATRIX_H_VERSION 20150912L

#include <vector>
#include <ostream>

namespace csl
{
  template <typename _Tp>
  class matrix
  {
  public :
    // template parameter.
    typedef _Tp  value_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;

    typedef std::size_t size_type;
    typedef csl::matrix<_Tp> _Self;

    // constructor & destructor.
    matrix() : m_data(), m_h(), m_w() { }

    matrix(const _Self& __x)
    { *this = __x; }

    matrix(size_type __h, size_type __w)
    : m_data(__h * __w), m_h(__h), m_w(__w) { }

    static _Self
    identity(size_type __n)
    {
      _Self __res(__n, __n);
      for (size_type i = 0; i < __n; ++i)
        __res[i][i] = value_type(1);
      return __res;
    }

    inline static _Self
    identity(const _Self& __x)
    { return identity(__x.height()); }

    // capacity.
    inline size_type
    height() const
    { return m_h; }

    inline size_type
    width() const
    { return m_w; }

    // element access.
    inline value_type*
    operator [] (size_type __x)
    { return &m_data[__x * m_w]; }

    inline const value_type*
    operator [] (size_type __x) const
    { return &m_data[__x * m_w]; }

    // operator overloading.
    _Self&
    operator += (const _Self& b)
    {
      size_type __n = height() * width();
      for (size_type i = 0; i < __n; ++i)
        m_data[i] += b.m_data[i];
      return *this;
    }

    _Self&
    operator *= (const _Self& b)
    {
      size_type n = height();
      size_type p = width();
      size_type m = b.width();
      _Self c(n, m);
      for (size_type i = 0; i < n; ++i)
        for (size_type k = 0; k < p; ++k)
        {
          value_type __tmp = (*this)[i][k];
          if (!__tmp) continue;
          for (size_type j = 0; j < m; ++j)
            c[i][j] += __tmp * b[k][j];
        }
      std::swap(m_data, c.m_data);
      m_h = c.m_h;
      m_w = c.m_w;
      return *this;
    }

    _Self
    operator + (const _Self& b) const
    { return _Self(*this) += b; }

    _Self
    operator * (const _Self& b) const
    { return _Self(*this) *= b; }

    friend std::ostream&
    operator << (std::ostream &o, const _Self& a)
    {
      size_type n = a.height();
      size_type m = a.width();
      for (size_type i = 0; i < n; ++i) {
        for (size_type j = 0; j < m; ++j)
          o << a.m_data[i][j] << " ";
        o << std::endl;
      }
      return o;
    }

  private :
    // member variable.
    std::vector<_Tp> m_data;
    size_type m_h;
    size_type m_w;

  };

} // namespace csl

#endif /* MATRIX_H_ */
