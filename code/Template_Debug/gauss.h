// Name : Gaussian Elimination 高斯消元法
// Copyright : fateud.com

#ifndef GAUSS_H_
#define GAUSS_H_
#define GAUSS_H_VERSION 20151007L

#include <vector>

#ifndef CSL_ALGO_H_
#pragma message("need : csl_algo.h");
#include <csl_algo.h>
#endif

#ifndef MATRIX_H_
#pragma message("need : matrix.h");
#include <matrix.h>
#endif

namespace csl
{
  class gauss
  {
  public :
    typedef std::size_t size_type;

    std::vector<bool> free;
    std::vector<double> ans;
    size_type dim;

    void
    build(csl::matrix<double> p_data)
    {
      m_size = p_data.height();
      dim = 0;
      free.assign(m_size, false);
      ans.resize(m_size);

      size_type r = 0;
      for (size_type i = 0; i < m_size; ++i) {
        for (size_type j = r; j < m_size; ++j)
          if (csl::sgn(p_data[j][i]))
          {
            for (size_type k = i; k <= m_size; ++k)
              std::swap(p_data[j][k], p_data[r][k]);
            break;
          }

        if (!csl::sgn(p_data[r][i]))
        {
          ++dim;
          continue;
        }
        for (size_type j = 0; j < m_size; ++j)
          if (j != r && csl::sgn(p_data[j][i]))
          {
            double tmp = p_data[j][i] / p_data[r][i];
            for (size_type k = i; k <= m_size; ++k)
              p_data[j][k] -= tmp * p_data[r][k];
          }
        free[i] = true;
        ++r;
      }
      for (size_type i = 0; i < m_size; ++i)
        if (free[i])
          for (size_type j = 0; j < m_size; ++j)
            if (csl::sgn(p_data[j][i]))
              ans[i] = p_data[j][m_size] / p_data[j][i];
    }

  private :
    size_type m_size;
  };

} // namespace csl

#endif /* GAUSS_H_ */
