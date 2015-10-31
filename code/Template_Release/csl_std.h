// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_
#define CSL_STD_H_VERSION 20150930L
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int>   vi;
typedef std::vector<vi>    vvi;
typedef std::vector<ll>    vll;
typedef std::vector<pii>   vpii;
template <class _Tp>
bool uin(_Tp &a, _Tp b) { return a > b ? (a = b, true) : false; }
template <class _Tp>
bool uax(_Tp &a, _Tp b) { return a < b ? (a = b, true) : false; }
#define rep(i,a,n)  for (int i = (a); i < (n); ++i)
#define rrep(i,a,n) for (int i = (n) - 1; i >= (a); --i)
#endif /* CSL_STD_H_ */
