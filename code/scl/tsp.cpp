#include<limits.h>
#include<algorithm>
#define MAXN 16
int n;/*點數*/ 
int dp[MAXN][1<<MAXN];/*DP陣列*/
int g[MAXN][MAXN];/*圖*/ 
int dfs(int s,int d){
    if(dp[d][s])return dp[d][s];
    if((1<<d)==s)return g[0][d];
    dp[d][s]=INT_MAX;
    for(int i=0;i<n;++i){
        if(((1<<i)&s)&&i!=d){
            dp[d][s]=std::min(dp[d][s],dfs(s^(1<<d),i)+g[i][d]);
        }
    }
    return dp[d][s];
}