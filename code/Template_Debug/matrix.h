// Name : Matrix 矩阵
// Copyright : fateud.com

#ifndef MATRIX_H_
#define MATRIX_H_
#define MATRIX_H_VERSION 20150911L

#include <vector>

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
    typedef std::vector< std::vector<_Tp> > container;
    typedef csl::matrix<_Tp> _Self;

  public : 
    // constructor & destructor.
    matrix() { }

    matrix(size_type __n, size_type __m)
    : m_data(container(__n, std::vector<value_type>(__m))) { }

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

  public : 
    // capacity.
    inline size_type
    height() const
    { return m_data.size(); }

    inline size_type
    weight() const
    { return m_data[0].size(); }

  public : 
    // element access.
    inline std::vector<value_type>&
    operator [] (size_type __x)
    { return m_data[__x]; }

  public :
    // operator overloading.
    friend _Self&
    operator += (_Self& a, const _Self& b)
    {
      size_type n = a.height();
      size_type m = a.weight();
      for (size_type i = 0; i < n; ++i)
        for (size_type j = 0; j < m; ++j)
          a.m_data[i][j] += b.m_data[i][j];
      return a;
    }

    friend _Self&
    operator *= (_Self& a, const _Self& b)
    {
      size_type n = a.height();
      size_type m = b.weight();
      size_type p = a.weight();
      a.m_temp.assign(n, std::vector<value_type>(m));
      for (size_type i = 0; i < n; ++i)
        for (size_type k = 0; k < p; ++k)
        {
          value_type __tmp = a.m_data[i][k];
          if (!__tmp) continue;
          for (size_type j = 0; j < m; ++j)
            a.m_temp[i][j] += __tmp * b.m_data[k][j];
        }
      a.m_data.swap(a.m_temp);
      return a;
    }

    friend _Self
    operator + (const _Self& a, const _Self& b)
    { return _Self(a) += b; }


    friend _Self
    operator * (const _Self& a, const _Self& b)
    { return _Self(a) *= b; }

  private :
    // member variable.
    container m_data;
    container m_temp;
  };
} // namespace csl

#endif /* MATRIX_H_ */
