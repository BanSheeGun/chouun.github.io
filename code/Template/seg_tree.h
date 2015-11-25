// Name : segment tree 非递归线段树
// Copyright : fateud.com

#ifndef SEG_TREE_H_
#define SEG_TREE_H_ 20150927L

#include <vector>
#include <functional>

namespace csl {
  template<typename _Tp,typename _Op = std::plus<_Tp>>
  struct seg_tree {
    typedef _Tp value_type;
    typedef std::size_t size_type;

    // constructor & destructor.
    seg_tree() :
        m_size(), m_func() {
    }

    // capacity.
    void build(size_type p_size) {
      for(m_size = 1; m_size < p_size; m_size <<= 1)
        ;
      m_data.assign(m_size << 1, value_type());
    }

    template<typename _InputIterator>
    inline void build(_InputIterator first,_InputIterator last) {
      size_type p_size = last - first;
      for(m_size = 1; m_size < p_size; m_size <<= 1)
        ;
      m_data.assign(m_size << 1, value_type());
      copy(first, last, m_data[m_size]);
      for(size_type i = m_size - 1; i; --i)
        m_data[i] = m_func(m_data[i << 1], m_data[i << 1 ^ 1]);
    }

    value_type query(size_type l,size_type r,value_type res =
        value_type()) const {
      for(++r; l && l + (l & -l) <= r; l += l & -l)
        res = m_func(res, m_data[(m_size + l) / (l & -l)]);
      for(; l < r; r -= r & -r)
        res = m_func(res, m_data[(m_size + r) / (r & -r) - 1]);
      return res;
    }

    // element access.
    _Tp operator [](const size_type __x) const {
      return m_data[m_size + __x];
    }

    // modifiers.
    void update(size_type __x,const value_type& __v) {
      m_data[m_size + __x] = __v;
      for(size_type i = (m_size + __x) >> 1; i; i >>= 1)
        m_data[i] = m_func(m_data[i << 1], m_data[i << 1 ^ 1]);
    }

    // member variable.
    std::vector<_Tp> m_data;
    size_type m_size;
    const _Op m_func;
  };
} // namespace csl

#endif /* SEG_TREE_H_ */
