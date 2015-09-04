// Name : graph.h 中文名
// Copyright : fateud.com

#ifndef GRAPH_H_
#define GRAPH_H_
#define GRAPH_H_VERSION

#include <vector>

namespace csl
{
  template <typename _Tp>
  struct _graph_node
  {
    typedef _Tp         value_type;
    typedef std::size_t size_type;

    typedef _graph_node<_Tp>* _Link;
    typedef _graph_node<_Tp>  _Self;

#ifdef GRAPH_USE_PREV
    _Link prev;
#endif
    _Link next;
    size_type from;
    size_type to;
    value_type data;
  };

  template <typename _Tp>
  struct graph
  {
    // template parameter.
    typedef _Tp  value_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;

    typedef _graph_node<_Tp>  _Node;
    typedef _graph_node<_Tp>* _Link;
    typedef graph<_Tp>        _Self;

    typedef std::size_t size_type;

    // member function.
    void
    m_add_edge(size_type from, size_type to, const value_type& data)
    {
      _Link node = m_data.data() + m_size++;
#ifdef GRAPH_USE_PREV
      node->prev = 0;
#endif
      node->next = m_impl[from];
      node->from = from;
      node->to   = to;
      node->data = data;
#ifdef GRAPH_USE_PREV
      if (m_impl[from]) m_impl[from]->prev = node;
#endif
      m_impl[from]       = node;
    }

    // constructor & destructor.
    explicit
    graph(size_type __v, size_type __e) : m_size()
    {
      m_impl.reserve(__v);
      m_data.reserve(__e);
    }

    // iterators.

    // capacity.
    void
    build(size_type __v, size_type __e)
    {
      m_impl.assign(__v, _Link());
      m_data.resize(__e);
      m_size = 0;
    }

    size_type
    size() const
    { return m_size; }

    // element access.
    _Link
    operator [] (size_type __x) const
    { return m_impl[__x]; }

    // modifiers.
    void
    add_edge(size_type from, size_type to, const value_type& data)
    {
      m_add_edge(from, to, data);
    }

    void
    add_double_edge(size_type from, size_type to, const value_type& data)
    {
      m_add_edge(from, to, data);
      m_add_edge(to, from, data);
    }

    void
    add_couple_edge(size_type from, size_type to, const value_type& data1,
                    const value_type& data2 = value_type())
    {
      m_add_edge(from, to, data1);
      m_add_edge(to, from, data2);
    }

    // operator overloading.

    // specialized algorithms.

    // member variable.
  private :
    std::vector<_Link> m_impl;
    std::vector<_Node> m_data;
    size_type          m_size;

  };

} // namespace csl

#endif /* GRAPH_H_ */
