//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5437.cpp
 *  Date : 2015年9月13日 下午3:47:00
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

#define maxk 150010
struct node {
  char s[201];
  int v;
  int w;
};
node a[maxk];
pii c[maxk];

struct cmp {
  bool operator () (node* a, node* b) const {
    return a->v != b->v ? a->v < b->v : a->w > b->w;
  }
};

//@ Main Function
int main() {
  int _;
  for (scanf("%d", &_); _; _--) {
    int k, m, q; scanf("%d%d%d", &k, &m, &q);
    rep(i, 0, k) scanf("%s%d", a[i].s, &a[i].v), a[i].w = i;
    rep(i, 0, m) scanf("%d%d", &c[i].first, &c[i].second);
    sort(c, c + m);

    int cur = 0;
    priority_queue< node*, vector<node*>, cmp > p;
    vector<node*> ans; ans.reserve(k);
    rep(i, 0, m) {
      for (int x = c[i].first; cur < x; ++cur) p.push(a + cur);
      for (int x = c[i].second; x && !p.empty(); --x, p.pop())
        ans.push_back(p.top());
    }
    for (; cur < k; ++cur) p.push(a + cur);
    for (; !p.empty(); p.pop())
      ans.push_back(p.top());

    rep(i, 0, q) {
      int x; scanf("%d", &x);
      printf("%s%c", ans[x-1]->s, i == q-1 ? '\n' : ' ');
    }
  }
  return 0;
}
