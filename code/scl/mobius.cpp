// BZOJ 2301 对于给出的 n个询问
// 每次求有多少数对(x,y)满足 a≤x≤b，c≤y≤d，且 gcd(x,y) = k
// gcd(x,y)函数为 x和 y的最大公约数
// 1≤n≤50000 1≤a≤b≤50000 1≤c≤d≤50000 1≤k≤50000
const int MAXN = 100000;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
void Moblus()
{
  memset(check,false,sizeof(check));
  mu[1] = 1;
  int tot = 0;
  for(int i = 2; i <= MAXN; i++)
  {
    if( !check[i] )
    {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for(int j = 0; j < tot; j ++)
    {
      if( i * prime[j] > MAXN) break;
      check[i * prime[j]] = true;
      if( i % prime[j] == 0)
      {
        mu[i * prime[j]] = 0;
        break;
      }
      else
      {
        mu[i * prime[j]] = -mu[i];
      }
    }
  }
}
int sum[MAXN+10];
//找[1,n],[1,m]内互质的数的对数
long long solve(int n,int m)
{
  long long ans = 0;
  if(n > m)swap(n,m);
  for(int i = 1, la = 0; i <= n; i = la+1)
  {
    la = min(n/(n/i),m/(m/i));
    ans += (long long)(sum[la] - sum[i-1])*(n/i)*(m/i);
  }
  return ans;
}
int main()
{
  Moblus();
  sum[0] = 0;
  for(int i = 1;i <= MAXN;i++)
    sum[i] = sum[i-1] + mu[i];
  int a,b,c,d,k;
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    long long ans = solve(b/k,d/k) - solve((a-1)/k,d/k) - solve(b/k,(c-1)/k) + solve((a-1)/k,(c-1)/k);
    printf("%lld\n",ans);
  }
  return 0;
}
