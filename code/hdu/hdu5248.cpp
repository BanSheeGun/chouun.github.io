//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5248.cpp
 *  Date : 2015年8月5日 下午10:07:15
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */
#define maxn 100010
int n, a[maxn];

bool judge(int k) {
  int now = a[0] - k;
  rep(i, 1, n) {
    now = max(now + 1, a[i] - k);
    if (now > a[i] + k) return false;
  }
  return true;
}

//@ Main Function
int main() {
  int _, __ = 0;
  //for (; scanf("%d", &_) != EOF; ) {
  for (scanf("%d", &_); _; _--) {
    printf("Case #%d:\n", ++__);
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a+i);

	int l = 0, r = 2000000;
	while (l < r) {
	  int m = (l + r) >> 1;
	  if (judge(m)) r = m; else l = m + 1;
	}
	printf("%d\n", l);
  }
  return 0;
}
