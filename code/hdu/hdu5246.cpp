//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5246.cpp
 *  Date : 2015年8月4日 下午8:29:04
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxn 10010
ll a[maxn];

//@ Main Function
int main() {
  //for (; scanf("%d", &_) != EOF; ) {
  int _, __ = 0;
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d:\n", ++__);
    int n; ll m, k; scanf("%d" i64 i64, &n, &m, &k);
    rep(i, 0, n) scanf(i64, a+i); sort(a, a+n);
    int idx = -1;
    rep(i, 0, n) if (a[i] > m) break; else idx = i;
    if (~idx) {
      for (int tmp = idx; k && idx != n-1; k--, idx = tmp) {
        rep(i, idx+1, n) if (a[i] > a[idx] + max(k, 0ll)) break; else tmp = i;
        if (tmp == idx) break;
      }
    }
    printf(idx != n-1 ? "madan!\n" : "why am I so diao?\n");
  }
  return 0;
}
