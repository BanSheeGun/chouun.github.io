//@ Including Header
#include <csl_std.h>
#include <fenwick.h>
#include <discrete.h>

/*
 *  Name : hdu5249-2.cpp
 *  Date : 2015年8月5日 下午11:37:55
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
char op[maxn];

csl::fenwick_tree<int> ft;
size_t search(int k) {
  size_t res = 0; int cnt = 0;
  rrep(i, 0, 20) {
    size_t tmp = res + (1 << i);
    if (tmp >= ft.m_data.size()) continue;
    if (cnt + ft.m_data[tmp] >= k) continue;
    res = tmp; cnt += ft.m_data[tmp];
  }
  return res + 1;
}

//@ Main Function
int main() {
  int __ = 0;
  for (int n; scanf("%d", &n) != EOF; ) {
//  for (scanf("%d", &_); _; _--) {
    printf("Case #%d:\n", ++__);
    vector<int> u;
    csl::discrete<int> v;
    rep(i, 0, n) {
      char s[10]; scanf("%s", s); op[i] = s[0];
      if (s[0] == 'i') {
        int x; scanf("%d", &x);
        u.push_back(x); v.insert(x);
      }
    }
    v.build();

    ft.build(v.size());
    int l = -1, r = -1, pos;
    rep(i, 0, n)
      switch (op[i]) {
        case 'i' :
          pos = v.query(u[++r]); ft.update(pos + 1, +1); break;
        case 'o' :
          pos = v.query(u[++l]); ft.update(pos + 1, -1); break;
        case 'q' :
          pos = search((r - l) / 2 + 1); printf("%d\n", v[pos - 1]); break;
      }
  }
  return 0;
}
