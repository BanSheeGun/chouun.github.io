// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com

#ifndef CSL_STD_H_
#define CSL_STD_H_
#define CSL_STD_H_VERSION 20150930L

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef std::pair<int,int>  pii;
typedef long long           ll;
typedef unsigned long long  ull;

#ifdef _WIN32
#define i64         "%I64d"
#else
#define i64         "%lld"
#endif /* _WIN32 */

#define rep(i,a,n)  for (int i=a;i<n;++i)
#define rrep(i,a,n) for (int i=n-1;i>=a;--i)

#endif /* CSL_STD_H_ */
