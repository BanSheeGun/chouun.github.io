// Name : Discretization 离散化
// Copyright : fateud.com
#ifndef DISCRETE_H_
#define DISCRETE_H_
#define DISCRETE_H_VERSION 20150822L
#include <vector>
#include <bits/stl_algo.h>
namespace csl {
  template <typename _Tp>
  struct discrete {
    typedef std::size_t size_type;
    std::vector<_Tp> m_data;
    void build() {
      std::sort(m_data.begin(), m_data.end());
      m_data.resize(std::unique(m_data.begin(), m_data.end()) - m_data.begin());
    }
    void clear()
    { m_data.clear(); }
    size_type size() const
    { return m_data.size(); }
    void reserve(size_type __n)
    { m_data.reserve(__n); }
    size_type query(const _Tp& __x) const
    { return std::lower_bound(m_data.begin(), m_data.end(), __x) - m_data.begin() + 1; }
    inline void insert(_Tp __x)
    { m_data.push_back(__x); }
    template <typename _InputIterator>
    inline void insert(_InputIterator first, _InputIterator last)
    { m_data.insert(m_data.end(), first, last); }
  };
} // namespace csl
#endif /* DISCRETE_H_ */
