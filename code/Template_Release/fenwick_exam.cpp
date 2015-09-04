//@ Including Header
#include <csl_std.h>
#include <fenwick.h>

/*
 *  Name : fenwick_exam.cpp
 *  Date : 2015年5月5日 下午7:51:37
 *  Copyright : fateud.com
 */

//@ Main Function
int main() {
  csl::fenwick_tree<int> ft;
  ft.build(6);
  ft.update(1, +3);     // 第1个元素增加3 : +3 +0 +0 +0 +0 +0
  ft.update(2, -5);     // 第2个元素减少5 : +3 -5 +0 +0 +0 +0
  printf("sum of [1,2] = %d\n", ft.query(2));
  ft.update(6, +1);     // 第6个元素增加1 : +0 +0 +0 +0 +0 +1
  ft.update(2, -4);     // 第2个元素减少4 : +0 -4 +0 +0 +0 +1
  printf("sum of [1,6] = %d\n", ft.query(6));
  return 0;
}
