//@ Including Header
#include <csl_std.h>
#include <csl_algo.h>
#include <sparse.h>

/*
 *  Name : hdu5247.cpp
 *  Date : 2015年8月5日 下午7:41:50
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
int a[maxn], b[maxn];

//@ Main Function
int main() {
  int _, __ = 0;
  //for (; scanf("%d", &_) != EOF; ) {
  for (_ = 1; _; _--) {
    printf("Case #%d:\n", ++__);
    int n, m; scanf("%d%d", &n, &m);
    rep(i, 0, n) scanf("%d", a+i);

    map<int, int> p;
    map<int, int>::iterator it;
    rep(i, 0, n) {
      it = p.find(a[i]);
      b[i] = (it == p.end()) ? -1 : it->second;
      p[a[i]] = i;
    }

    csl::sparse_table< int, csl::less<int> > st1; st1.build(a, n);
    csl::sparse_table< int, csl::greater<int> > st2; st2.build(a, n);
    csl::sparse_table< int, csl::greater<int> > st3; st3.build(b, n);

    while (m--) {
      int k; scanf("%d", &k);
      int ans = 0;
      rep(i, 0, n-k+1) {
        int x = st1.query(i, i+k-1);
        int y = st2.query(i, i+k-1);
        if (y - x + 1 != k) continue;
        int z = st3.query(i, i+k-1);
        if (z >= i) continue;
        ++ans;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
