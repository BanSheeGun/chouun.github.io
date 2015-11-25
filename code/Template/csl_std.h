// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ll> vll;
typedef std::vector<pii> vpii;

template<typename _Tp>
bool uin(_Tp &a,_Tp b) {
  return a > b ? (a = std::move(b), true) : false;
}
template<typename _Tp>
bool uax(_Tp &a,_Tp b) {
  return a < b ? (a = std::move(b), true) : false;
}

#define rep(i,a,b) for(auto i=a,i##_n=b;i!=i##_n;++i)
#define rrep(i,a,b) for(auto i=b,i##_n=a;i--!=i##_n;)

#endif /* CSL_STD_H_ */
