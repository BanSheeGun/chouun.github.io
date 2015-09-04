// Name : Big Positive Integer 高精度正整数
// Copyright : fateud.com
#ifndef BIGINT_H_
#define BIGINT_H_
#define BIGNUM_H_VERSION 20150529L
#include <iomanip>
namespace csl {
  static int BIGINT_BIT     = 5;
  static int BIGINT_BASE    = 1e5;
  template <int _Sz>
  class BigInt {
  public :
    int m_size, m_data[_Sz];
  public :
    BigInt() : m_size(1) { memset(m_data, 0x00, sizeof(m_data)); }
    BigInt(const int b) : m_size(1)
    {
      memset(m_data, 0x00, sizeof(m_data)); m_data[0] = b;
    }
    explicit BigInt(const char *p) {
      char *s = const_cast<char *>(p), *t = s;
      while (*t) t++;
      for (m_data[m_size=0] = 0; s < t; ) {
        m_data[m_size] = m_data[m_size] * 10 + (*s++) - '0';
        if ((t - s) % BIGINT_BIT == 0) m_data[++m_size] = 0;
      }
      std::reverse(m_data, m_data + m_size);
      while (m_size > 1 && !m_data[m_size - 1]) m_size--;
    }
    inline BigInt& operator = (const BigInt& b) {
      m_size = b.m_size;
      memcpy(m_data, b.m_data, m_size * sizeof(int));
      return *this;
    }
    BigInt& operator += (const BigInt& b) {
      int i = 0;
      for (int c = 0; i < m_size || i < b.m_size || c > 0; i++) {
        if (i < m_size) c += m_data[i];
        if (i < b.m_size) c += b.m_data[i];
        m_data[i] = c % BIGINT_BASE, c /= BIGINT_BASE;
      }
      m_size = i;
      return *this;
    }
    BigInt& operator -= (const BigInt& b) {
      int c = 0;
      for (int i = 0; i < m_size; i++) {
        m_data[i] -= c;
        if (i < b.m_size) m_data[i] -= b.m_data[i];
        if (m_data[i] < 0) c = 1, m_data[i] += BIGINT_BASE; else c = 0;
      }
      while (m_size > 1 && !m_data[m_size - 1]) m_size--;
      return *this;
    }
    BigInt& operator *= (const BigInt& b) {
      if (!b.m_size) return *this = BigInt();
      BigInt r;
      for (int i = 0; i < m_size; i++) {
        long long c = 0;
        for (int j = 0; j < b.m_size || c > 0; j++) {
          if (j < b.m_size) c += (long long)m_data[i] * b.m_data[j];
          if (i + j < r.m_size) c += r.m_data[i + j];
          if (i + j >= r.m_size) r.m_data[r.m_size++] = c % BIGINT_BASE;
          else r.m_data[i + j] = c % BIGINT_BASE;
          c /= BIGINT_BASE;
        }
      }
      return *this = r;
    }
    BigInt& operator /= (const BigInt& b) {
      BigInt r, c;
      for (int i = m_size - 1; i >= 0; i--) {
        c = c * BIGINT_BASE + BigInt(m_data[i]);
        int left = 0, right = BIGINT_BASE - 1;
        while (left < right) {
          int mid = (left + right + 1) / 2;
          if (cmp(b * mid, c) <= 0) left = mid; else right = mid - 1;
        }
        r.m_data[i] = left, c = c - b * left;
      }
      memcpy(m_data, r.m_data, sizeof(int) * m_size);
      while (m_size > 1 && !m_data[m_size - 1]) m_size--;
      return *this;
    }
    BigInt& operator %= (const BigInt& b) {
      BigInt r, c;
      for (int i = m_size - 1; i >= 0; i--) {
        c = c * BIGINT_BASE + BigInt(m_data[i]);
        int left = 0, right = BIGINT_BASE - 1;
        while (left < right) {
          int mid = (left + right + 1) / 2;
          if (cmp(b * mid, c) <= 0) left = mid; else right = mid - 1;
        }
        r.m_data[i] = left, c = c - b * left;
      }
      return *this = c;
    }
    inline BigInt operator + (const BigInt& b) const
    { return BigInt(*this) += b; }
    inline BigInt operator - (const BigInt& b) const
    { return BigInt(*this) -= b; }
    inline BigInt operator * (const BigInt& b) const
    { return BigInt(*this) *= b; }
    inline BigInt operator / (const BigInt& b) const
    { return BigInt(*this) /= b; }
    inline BigInt operator % (const BigInt& b) const
    { return BigInt(*this) %= b; }
    inline bool operator == (const BigInt& b) const
    { return cmp(*this, b) == 0; }
    inline bool operator != (const BigInt& b) const
    { return cmp(*this, b) != 0; }
    inline bool operator <= (const BigInt& b) const
    { return cmp(*this, b) <= 0; }
    inline bool operator >= (const BigInt& b) const
    { return cmp(*this, b) >= 0; }
    inline bool operator < (const BigInt& b) const
    { return cmp(*this, b) < 0; }
    inline bool operator > (const BigInt& b) const
    { return cmp(*this, b) > 0; }
    friend std::istream& operator >> (std::istream &i, BigInt& n)
    { std::string s; i >> s; n = BigInt(s.c_str()); return i; }
    friend std::ostream& operator << (std::ostream &o, const BigInt& n) {
      o << (n.m_size ? n.m_data[n.m_size - 1] : 0);
      for (int i = n.m_size - 2; i >= 0; i--)
        o << std::setfill('0') << std::setw(BIGINT_BIT) << n.m_data[i];
      return o << std::setfill(' ');
    }
    friend int cmp(const BigInt& a, const BigInt& b) {
      if (a.m_size ^ b.m_size) return a.m_size > b.m_size ? 1 : -1;
      for (int i = a.m_size; i --> 0;) if (a.m_data[i] ^ b.m_data[i])
        return a.m_data[i] > b.m_data[i] ? 1 : -1;
      return 0;
    }
  };
} // namespace csl
#endif /* BIGINT_H_ */
