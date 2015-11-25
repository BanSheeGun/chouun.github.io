// Name : Sparse Table 稀疏表
// Copyright : fateud.com
#ifndef SPARSE_H_
#define SPARSE_H_ 20151124L
#include <vector>
#ifndef CSL_ALGO_H_
#pragma message("need : csl_algo.h");
#include <csl_algo.h>
#endif
namespace csl {
  static std::vector<std::size_t> msb(2, 0);
  void msb_build(std::size_t p_data) {
    for(std::size_t i = msb.size(), t = msb[i - 1]; i <= p_data; ++i)
      msb.push_back(t += !(i & (i - 1)));
  }

  template<typename _Tp,typename _Compare = csl::min<_Tp>>
  class sparse_table {
  public:
    typedef std::size_t size_type;

    sparse_table(const _Compare& p_comp = _Compare()) :
        m_data(), m_comp(p_comp) {
    }

    void clear() {
      m_data.clear();
    }
    size_type size() const {
      return m_data.empty() ? 0 : m_data.at(0).size();
    }

    _Tp query(size_type first,size_type last) const {
      size_type k = csl::msb[last - first + 1];
      return m_comp(m_data[k][first], m_data[k][last + 1 - (1 << k)]);
    }
    void build(_Tp* p_data,size_type p_size) {
      msb_build(p_size);
      m_data.clear();
      m_data.push_back(std::vector<_Tp>(p_data, p_data + p_size));
      for(size_type k = 1, d = 2, t = 1; d <= p_size; ++k, d <<= 1, t <<= 1) {
        m_data.push_back(std::vector<_Tp>(p_size - d + 1));
        for(size_type i = 0, j = p_size + 1 - d; i < j; ++i)
          m_data[k][i] = m_comp(m_data[k - 1][i], m_data[k - 1][i + t]);
      }
    }
  private:
    std::vector<std::vector<_Tp>> m_data;
    _Compare m_comp;
  };
} // namespace csl
#endif /* SPARSE_H_ */
