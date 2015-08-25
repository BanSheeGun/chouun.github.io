// Name : Algorithm 算法
// Copyright : fateud.com

#ifndef CSL_ALGO_H_
#define CSL_ALGO_H_
#define CSL_ALGO_H_VERSION 20150820L

#include <vector>

namespace csl
{
  namespace euler
  {
    std::vector<int> phi;
    std::vector<int> div;
    std::vector<int> prm;

    void
    build(int __n)
    {
      phi.resize(__n);
      div.resize(__n);
      prm.clear();
      phi[1] = 1;
      for (int i = 2; i < __n; i++)
      {
        if (!div[i])
        {
          phi[i] = i-1;
          div[i] = i;
          prm.push_back(i);
        }
        for (int j = 0; j < (int)prm.size(); j++)
        {
          if (i * prm[j] >= __n) break;
          div[i * prm[j]] = prm[j];
          if (i % prm[j] == 0)
          {
            phi[i * prm[j]] = phi[i] * prm[j];
            break;
          }
          else
          {
            phi[i * prm[j]] = phi[i] * (prm[j] - 1);
          }
        }
      }
    }
  } // namespace euler

} // namespace csl

#endif /* CSL_ALGO_H_ */
