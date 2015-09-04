/*
 *	Name : bigint_exam.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年5月5日 下午7:00:52
 *	Copyright : www.fateud.com
 *	Description : None
 */

//@ Including Header
#include <csl_std.h>
#include <bigint.h>
//@ Program Begin

//@ Main Function
int main() {
  int _;
  std::cin >> _;
  while (_--) {
    csl::BigInt<300> n;
    std::cin >> n;
    if (n % 2 == 1)
      std::cout << (n / 2) << std::endl;
    else if (n % 4 > 0)
      std::cout << (n / 2 - 2) << std::endl;
    else
      std::cout << (n / 2 - 1) << std::endl;
    if (_) std::cout << std::endl;
  }
  return 0;
}
