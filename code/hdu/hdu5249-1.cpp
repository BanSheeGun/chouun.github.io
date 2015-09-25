//@ Including Header
#include <csl_std.h>

/*
 *  Name : hdu5249-1.cpp
 *  Date : 2015年8月5日 下午10:18:37
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

struct channel {
private :
  set<int> head, tail;
  set<int>::iterator it;
  deque<int> order;
public :
  void clear() {
    head.clear();
    tail.clear();
    order.clear();
  }
  void insert(int x) {
    if (head.empty() || x > *head.rbegin()) tail.insert(x);
    else head.insert(x);
    order.push_back(x);
  }
  void erase() {
    if (order.empty()) return;
    int x = order.front(); order.pop_front();
    it = head.find(x); if (it != head.end()) head.erase(it);
    it = tail.find(x); if (it != tail.end()) tail.erase(it);
  }
  void query() {
    while (tail.size() < head.size()) {
      it = --head.end();
      tail.insert(*it);
      head.erase(it);
    }
    while (tail.size() > head.size() + 1) {
      it = tail.begin();
      head.insert(*it);
      tail.erase(it);
    }
    if (!tail.empty()) printf("%d\n", *tail.begin());
  }
} q;

//@ Main Function
int main() {
  int _, __ = 0;
  for (int n; scanf("%d", &n) != EOF; ) {
//  for (scanf("%d", &_); _; _--) {
    printf("Case #%d:\n", ++__);
    q.clear();
	while (n--) {
	  char s[10]; scanf("%s", s); int x;
	  switch (s[0]) {
	    case 'i' : scanf("%d", &x); q.insert(x); break;
	    case 'o' : q.erase(); break;
	    case 'q' : q.query(); break;
	  }
	}
  }
  return 0;
}
