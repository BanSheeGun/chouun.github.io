// Name : Fenwick Tree 树状数组
// AKA : Binary Indexed Tree 二分索引树
// Copyright : fateud.com
#ifndef FENWICK_H_
#define FENWICK_H_
#define FENWICK_H_VERSION 20150928L
#include <vector>
#include <functional>
#ifndef lowbit
#define lowbit(x) ((x)&-(x))
#endif
namespace csl {
  template < typename _Tp, typename _Op = std::plus<_Tp> >
  struct fenwick_tree {
    typedef _Tp         value_type;
    typedef std::size_t size_type;
    fenwick_tree() : m_func() { }
    inline void build(size_type p_size)
    { m_data.assign(p_size + 1, 0); }
    void build(const value_type* p_data, size_type p_size) {
      m_data.resize(p_size + 1);
      for (int i = 1; i <= p_size; ++i) m_data[i] = p_data[i-1];
      for (int i = 1, j; i <= p_size; ++i)
        if ((j = i + lowbit(i)) <= p_size)
          m_data[j] = m_func(m_data[j], m_data[i]);
    }
    size_type size() const
    { return m_data.size(); }
    value_type query(size_type __x, value_type __res = value_type())  const {
      for (; __x > 0; __x -= lowbit(__x)) __res = m_func(__res, m_data[__x]);
      return __res;
    }
    void update(size_type __x, const value_type& __v) {
      for (; __x < m_data.size(); __x += lowbit(__x))
        m_data[__x] = m_func(m_data[__x], __v);
    }
    std::vector<value_type> m_data;
    const _Op               m_func;
  };
  std::size_t search(fenwick_tree<int>& f, int x) {
    if (f.query(f.size() - 1) < x) return -1;
    std::size_t res = 0;
    for (int i = 1 << 20; i > 0 && x > 0; i >>= 1) {
      if (res + i >= f.size()) continue;
      if (x > f.m_data[res + i]) x -= f.m_data[res += i];
    }
    return res + 1;
  }
} // namespace csl
#endif /* FENWICK_H_ */
