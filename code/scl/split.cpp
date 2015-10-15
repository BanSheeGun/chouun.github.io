//HDU 4651
const int MOD = 1e9+7;
int dp[100010];
void init()
{
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  for(int i = 1;i <= 100000;i++)
  {
    for(int j = 1, r = 1; i - (3 * j * j - j) / 2 >= 0; j++, r *= -1)
    {
      dp[i] += dp[i -(3 * j * j - j) / 2] * r;
      dp[i] %= MOD;
      dp[i] = (dp[i]+MOD)%MOD;
      if( i - (3 * j * j + j) / 2 >= 0 )
        {
        dp[i] += dp[i - (3 * j * j + j) / 2] * r;
        dp[i] %= MOD;
        dp[i] = (dp[i]+MOD)%MOD;
        }
    }
  }
}
int main()
{
  int T;
  int n;
  init();
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    printf("%d\n",dp[n]);
  }
  return 0;
}
//HDU 4658
//数 n(<=10^5)的划分，相同数重复不能超过k个的划分
const int MOD = 1e9+7;
int dp[100010];
void init()
{
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  for(int i = 1;i <= 100000;i++)
  {
    for(int j = 1, r = 1; i - (3 * j * j - j) / 2 >= 0; j++, r *= -1)
    {
      dp[i] += dp[i -(3 * j * j - j) / 2] * r;
      dp[i] %= MOD;
      dp[i] = (dp[i]+MOD)%MOD;
      if( i - (3 * j * j + j) / 2 >= 0 )
      {
        dp[i] += dp[i - (3 * j * j + j) / 2] * r;
        dp[i] %= MOD;
        dp[i] = (dp[i]+MOD)%MOD;
      }
    }
  }
}
int solve(int n,int k)
{
  int ans = dp[n];
  for(int j = 1, r = -1; n - k*(3 * j * j - j) / 2 >= 0; j++, r *= -1)
  {
    ans += dp[n -k*(3 * j * j - j) / 2] * r;
    ans %= MOD;
    ans = (ans+MOD)%MOD;
    if( n - k*(3 * j * j + j) / 2 >= 0 )
    {
      ans += dp[n - k*(3 * j * j + j) / 2] * r;
      ans %= MOD;
      ans = (ans+MOD)%MOD;
    }
  }
  return ans;
}
int main()
{
  init();
  int T;
  int n,k;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&k);
    printf("%d\n",solve(n,k));
  }
  return 0;
}
