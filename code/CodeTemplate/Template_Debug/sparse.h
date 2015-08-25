// Name : Sparse Table 稀疏表
// Copyright : fateud.com

#ifndef SPARSE_H_
#define SPARSE_H_
#define SPARSE_H_VERSION 20150808L
#include <vector>
#include <functional>
namespace csl
{
  static std::vector<std::size_t> msb(2, 0);
  void
  msb_build(std::size_t p_data) {
    for (std::size_t i = msb.size(), t = msb[i-1]; i <= p_data; ++i)
      msb.push_back(t += (i & (i-1) ? 0 : 1));
  }

  template <typename _Tp, typename _Compare = std::less<_Tp> >
  class sparse_table
  {
  public :
    // template parameter.
    typedef std::size_t size_t;

  private :
    // member variable.
    std::vector< std::vector<_Tp*> > m_data;
    _Compare m_comp;

  public : 
    // constructor & destructor.
    sparse_table(const _Compare& p_comp = _Compare()) : m_data(), m_comp(p_comp) { }

  public : 
    // capacity.
    void
    clear()
    { m_data.clear(); }

    size_t
    size() const
    { return m_data.empty() ? 0 : m_data.at(0).size(); }

  public : 
    // element access.
    _Tp
    query(size_t first, size_t last) const
    {
      size_t k = msb[last-first+1]; last = last + 1 - (1<<k);
      return m_comp(*m_data[k][first], *m_data[k][last]) ?
          *m_data[k][first] : *m_data[k][last];
    }

  public : 
    // modifiers.
    void
    build(_Tp* p_data, size_t p_size)
    {
      msb_build(p_size);
      m_data.clear();
      m_data.push_back(std::vector<_Tp*>(p_size));
      for (size_t i = 0; i < p_size; ++i)
        m_data[0][i] = p_data + i;
      for (size_t k = 1, d = 2, t = 1; d <= p_size; ++k, d <<= 1, t <<= 1)
      {
        m_data.push_back(std::vector<_Tp*>(p_size - d + 1));
        for (size_t i = 0, j = p_size + 1 - d; i < j; ++i)
          m_data[k][i] = m_comp(*m_data[k-1][i], *m_data[k-1][i+t]) ?
              m_data[k-1][i] : m_data[k-1][i+t];
      }
    }

  };
} // namespace csl

#endif /* SPARSE_H_ */
