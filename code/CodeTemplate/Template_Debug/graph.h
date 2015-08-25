/*
 *  模板参数：
 *  成员变量：
 *  构造析构：
 *  成员函数：
 *  迭代器：
 *  职能：
 *  元素访问：
 *  修改符：
 *  运算符重载：
 *  专用算法：
 */

// Name : graph.h 中文名
// Copyright : www.fateud.com

#ifndef GRAPH_H_
#define GRAPH_H_
#define GRAPH_H_VERSION 20150610A

namespace csl
{
  struct null_class { };

  template <class _Tp>
  struct _Graph_node
  {
    int to;
    _Tp data;
  };

  template <class _Tp>
  struct _Graph_iterator_base
  {
    typedef _Graph_iterator_base<_Tp>   _Self;
    typedef _Graph_node<_Tp>            _Node;
    _Self* m_next;
    _Node m_data;
  };

  template <typename _Tp>
  struct _Graph_iterator
  {
    typedef _Graph_iterator<_Tp>        _Self;
    typedef _Graph_iterator_base<_Tp>   _Base;
    typedef _Graph_iterator_base<_Tp>*  _Link;
    typedef typename _Base::_Node       _Node;

    _Graph_iterator()
    : m_node()
    { }

    explicit
    _Graph_iterator(_Link p_node)
    : m_node(p_node)
    { }

    _Node&
    operator*() const
    { return m_node->m_data; }

    _Node*
    operator->() const
    { return std::__addressof(m_node->m_data); }

    _Self&
    operator++()
    {
      m_node = m_node->m_next;
      return *this;
    }

    _Self
    operator++(int)
    {
      _Self __tmp = *this;
      m_node = m_node->m_next;
      return __tmp;
    }

    bool
    operator==(const _Self& __x) const
    { return m_node == __x.m_node; }

    bool
    operator!=(const _Self& __x) const
    { return m_node != __x.m_node; }

  private :
    _Link m_node;

  };

  template <class _Tp = null_class>
  class Graph
  {
  public :
    // template parameter.
    typedef Graph<_Tp>                  _Self;
    typedef _Graph_iterator<_Tp>        iterator;
    typedef typename iterator::_Base    _Base;
    typedef typename iterator::_Link    _Link;
    typedef typename _Base::_Node       _Node;

    // constructor & destructor.
    Graph()
    : m_size(), m_head(), m_data(), m_tail()
    { }

    ~Graph()
    { }

    // iterators.
    iterator
    begin(int __x) const
    { return iterator(m_head[__x]); }

    iterator
    end() const
    { return iterator(0); }

    // capacity.
    void
    build(void* p_data, int p_size)
    {
      std::clog << "Template Graph : node needs " << sizeof(_Link) <<
          " bytes, edge needs " << sizeof(_Node) << " bytes." << std::endl;
      m_size = p_size;
      m_head = (_Link*)(p_data);
      m_data = (_Base*)(void*)(m_head + m_size);
      m_tail = m_data;
      memset(m_head, 0x00, sizeof(_Link) * m_size);
    }

    // element access.
    // modifiers.
    void
    add_edge(int u, int v, _Tp p_data = _Tp())
    {
      _add_edge(u, v, p_data);
    }

    void
    add_double_edge(int u, int v, _Tp p_data = _Tp())
    {
      _add_edge(u, v, p_data);
      _add_edge(v, u, p_data);
    }

    void
    add_couple_edge(int u, int v, _Tp p_data = _Tp())
    {
      _add_edge(u, v, p_data);
      _add_edge(v, u, ~p_data);
    }

    // operator overloading.
    // specialized algorithms.

  private :
    // member variable.
    int m_size;
    _Link* m_head;
    _Base* m_data;
    _Link m_tail;

    // member function.
    void
    _add_edge(int u, int v, _Tp p_data = _Tp())
    {
      m_tail->m_data.to = v;
      m_tail->m_data.data = p_data;
      m_tail->m_next = m_head[u];
      m_head[u] = m_tail++;
    }

  };
} // namespace csl

#endif /* GRAPH_H_ */
