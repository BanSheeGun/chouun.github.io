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
    typedef _Tp  value_type;
    typedef _Tp* pointer;
    std::vector<value_type> m_data;
    void build() {
      std::sort(m_data.begin(), m_data.end());
      m_data.resize(std::unique(m_data.begin(), m_data.end()) - m_data.begin());
    }
    void clear()
    { m_data.clear(); }
    std::size_t size()
    { return m_data.size(); }
    std::size_t query(value_type __x)
    { return std::lower_bound(m_data.begin(), m_data.end(), __x) - m_data.begin() + 1; }
    void insert(value_type __x)
    { m_data.push_back(__x); }
    template <typename _InputIterator>
    void insert(_InputIterator first, _InputIterator last)
    { m_data.insert(m_data.end(), first, last); }
  };
} // namespace csl
#endif /* DISCRETE_H_ */
