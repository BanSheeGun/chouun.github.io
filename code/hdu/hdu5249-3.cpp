//@ Including Header
#include <csl_std.h>
#include <rb_tree.h>

/*
 *  Name : hdu5249-3.cpp
 *  Date : 2015年8月8日 上午9:53:05
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef csl::rb_tree<int, __gnu_pbds::null_type, less<int>,
    __gnu_pbds::tree_order_statistics_node_update> rb_tree;

//@ Main Function
int main() {
  int __ = 0;
  for (int n; scanf("%d", &n) != EOF; ) {
    printf("Case #%d:\n", ++__);
    rb_tree p;
    std::queue<int> q;
    while (n--) {
      char s[10]; scanf("%s", s); int x;
      switch (s[0]) {
        case 'i' :
          scanf("%d", &x), q.push(x), p.insert(x); break;
        case 'o' :
          if (!q.empty()) x = q.front(), q.pop(), p.erase(x); break;
        case 'q' :
          if (!p.empty()) x = *p.find_by_order(p.size() / 2); printf("%d\n", x); break;
      }
    }
  }
  return 0;
}
