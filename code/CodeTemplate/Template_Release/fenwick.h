// Name : Fenwick Tree 树状数组
// AKA : Binary Indexed Tree 二分索引树
// Copyright : fateud.com
#ifndef FENWICK_H_
#define FENWICK_H_
#define FENWICK_H_VERSION 20150814L
#include <vector>
#ifndef lowbit
#define lowbit(x) ((x)&-(x))
#endif
namespace csl {
  template <typename _Tp>
  struct fenwick_tree {
    typedef _Tp         value_type;
    typedef std::size_t size_type;
    std::vector<value_type> m_data;
    void build(const value_type* p_data, size_type p_size) {
      m_data.resize(p_size + 1);
      for (int i = 1; i <= p_size; ++i) m_data[i] = p_data[i-1];
      for (int i = 1, j; i <= p_size; ++i)
        if ((j = i + lowbit(i)) <= p_size) m_data[j] += m_data[i];
    }
    void build(size_type p_size)
    { m_data.assign(p_size + 1, 0); }
    value_type query(size_type __x) const {
      value_type __res = value_type();
      for (; __x > 0; __x -= lowbit(__x)) __res += m_data[__x];
      return __res;
    }
    void update(size_type __x, const value_type& __v)
    { for (; __x < m_data.size(); __x += lowbit(__x)) m_data[__x] += __v; }
  };
} // namespace csl
#endif /* FENWICK_H_ */
