// Name : Algorithm 算法
// Copyright : fateud.com
#ifndef CSL_ALGO_H_
#define CSL_ALGO_H_
#define CSL_ALGO_H_VERSION 20150904L
#include <vector>
namespace csl {
  template <typename _Tp>
  struct less : public std::binary_function<_Tp, _Tp, _Tp> {
    _Tp operator () (const _Tp& __x, const _Tp& __y) const
    { return __x < __y ? __x : __y; }
  };
  template <typename _Tp>
  struct greater : public std::binary_function<_Tp, _Tp, _Tp> {
    _Tp operator () (const _Tp& __x, const _Tp& __y) const
    { return __x > __y ? __x : __y; }
  };
  namespace euler {
    std::vector<std::size_t> phi, div, prm;
    void build(int __n) {
      phi.assign(__n, 0); div.assign(__n, 0);
      prm.reserve(__n >> 3); prm.clear(); phi[1] = 1;
      for (std::size_t i = 2; i < __n; ++i) {
        if (!div[i]) { phi[i] = i - 1; div[i] = i; prm.push_back(i); }
        for (std::size_t j = 0, m = prm.size(); j < m; ++j) {
          if (i * prm[j] >= __n) break;
          div[i * prm[j]] = prm[j];
          if (i % prm[j] == 0) { phi[i * prm[j]] = phi[i] * prm[j]; break; }
          else { phi[i * prm[j]] = phi[i] * (prm[j] - 1); }
        }
      }
    }
  } // namespace euler
} // namespace csl
#endif /* CSL_ALGO_H_ */
