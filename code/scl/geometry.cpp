// 5.1 半平面交
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
  if(fabs(x) < eps) return 0;
  if(x < 0) return -1;
  else return 1;
}
struct Point
{
  double x,y;
  Point(){}
  Point(double _x,double _y)
  {
    x = _x; y = _y;
  }
  Point operator -(const Point &b)const
  {
    return Point(x - b.x, y - b.y);
  }
  double operator ^(const Point &b)const
  {
    return x*b.y - y*b.x;
  }
  double operator *(const Point &b)const
  {
    return x*b.x + y*b.y;
  }
};
struct Line
{
  Point s,e;
  double k;
  Line(){}
  Line(Point _s,Point _e)
  {
    s = _s; e = _e;
    k = atan2(e.y - s.y,e.x - s.x);
  }
  Point operator &(const Line &b)const
  {
    Point res = s;
    double t = ((s - b.s)^(b.s - b.e))/((s - e)^(b.s - b.e));
    res.x += (e.x - s.x)*t;
    res.y += (e.y - s.y)*t;
    return res;
  }
};
//半平面交，直线的左边代表有效区域
bool HPIcmp(Line a,Line b)
{
  if(fabs(a.k - b.k) > eps)return a.k < b.k;
  return ((a.s - b.s)^(b.e - b.s)) < 0;
}
Line Q[110];
void HPI(Line line[], int n, Point res[], int &resn)
{
  int tot = n;
  sort(line,line+n,HPIcmp);
  tot = 1;
  for(int i = 1;i < n;i++)
    if(fabs(line[i].k - line[i-1].k) > eps)
      line[tot++] = line[i];
  int head = 0, tail = 1;
  Q[0] = line[0];
  Q[1] = line[1];
  resn = 0;
  for(int i = 2; i < tot; i++)
  {
    if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s)) < eps || fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
      return;
    while(head < tail && (((Q[tail]&Q[tail-1]) - line[i].s)^(line[i].e-line[i].s)) > eps)
      tail--;
    while(head < tail && (((Q[head]&Q[head+1]) - line[i].s)^(line[i].e-line[i].s)) > eps)
      head++;
    Q[++tail] = line[i];
  }
  while(head < tail && (((Q[tail]&Q[tail-1]) - Q[head].s)^(Q[head].e-Q[head].s)) > eps)
    tail--;
  while(head < tail && (((Q[head]&Q[head-1]) - Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
    head++;
  if(tail <= head + 1)return;
  for(int i = head; i < tail; i++)
    res[resn++] = Q[i]&Q[i+1];
  if(head < tail - 1)
    res[resn++] = Q[head]&Q[tail];
}

// 5.2 普通半平面交写法 POJ 1750
const double eps = 1e-18;
int sgn(double x)
{
  if(fabs(x) < eps)return 0;
  if(x < 0)return -1;
  else return 1;
}
struct Point
{
  double x,y;
  Point(){}
  Point(double _x,double _y)
  {
    x = _x; y = _y;
  }
  Point operator -(const Point &b)const
  {
    return Point(x - b.x, y - b.y);
  }
  double operator ^(const Point &b)const
  {
    return x*b.y - y*b.x;
  }
  double operator *(const Point &b)const
  {
    return x*b.x + y*b.y;
  }
};
//计算多边形面积
double CalcArea(Point p[],int n)
{
  double res = 0;
  for(int i = 0;i < n;i++)
    res += (p[i]^p[(i+1)%n]);
  return fabs(res/2);
}
//通过两点，确定直线方程
void Get_equation(Point p1,Point p2,double &a,double &b,double &c)
{
  a = p2.y - p1.y;
  b = p1.x - p2.x;
  c = p2.x*p1.y - p1.x*p2.y;
}
//求交点
Point Intersection(Point p1,Point p2,double a,double b,double c)
{
  double u = fabs(a*p1.x + b*p1.y + c);
  double v = fabs(a*p2.x + b*p2.y + c);
  Point t;
  t.x = (p1.x*v + p2.x*u)/(u+v);
  t.y = (p1.y*v + p2.y*u)/(u+v);
  return t;
}
Point tp[110];
void Cut(double a,double b,double c,Point p[],int &cnt)
{
  int tmp = 0;
  for(int i = 1;i <= cnt;i++)
  {
    //当前点在左侧，逆时针的点
    if(a*p[i].x + b*p[i].y + c < eps)tp[++tmp] = p[i];
    else
    {
      if(a*p[i-1].x + b*p[i-1].y + c < -eps)
        tp[++tmp] = Intersection(p[i-1],p[i],a,b,c);
      if(a*p[i+1].x + b*p[i+1].y + c < -eps)
        tp[++tmp] = Intersection(p[i],p[i+1],a,b,c);
    }
  }
  for(int i = 1;i <= tmp;i++)
    p[i] = tp[i];
  p[0] = p[tmp];
  p[tmp+1] = p[1];
  cnt = tmp;
}
double V[110],U[110],W[110];
int n;
const double INF = 100000000000.0;
Point p[110];
bool solve(int id)
{
  p[1] = Point(0,0);
  p[2] = Point(INF,0);
  p[3] = Point(INF,INF);
  p[4] = Point(0,INF);
  p[0] = p[4];
  p[5] = p[1];
  int cnt = 4;
  for(int i = 0;i < n;i++)
    if(i != id)
    {
      double a = (V[i] - V[id])/(V[i]*V[id]);
      double b = (U[i] - U[id])/(U[i]*U[id]);
      double c = (W[i] - W[id])/(W[i]*W[id]);
      if(sgn(a) == 0 && sgn(b) == 0)
      {
        if(sgn(c) >= 0)return false;
        else continue;
      }
      Cut(a,b,c,p,cnt);
    }
  if(sgn(CalcArea(p,cnt)) == 0)return false;
  else return true;
}
int main()
{
  while(scanf("%d",&n) == 1)
  {
    for(int i = 0;i < n;i++)
      scanf("%lf%lf%lf",&V[i],&U[i],&W[i]);
    for(int i = 0;i < n;i++)
    {
      if(solve(i))printf("Yes\n");
      else printf("No\n");
    }
  }
  return 0;
}

// 6、三点求圆心坐标（角形外）
// 过三点求圆心坐标
Point waixin(Point a,Point b,Point c)
{
  double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;

  double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;
  double d = a1*b2 - a2*b1;
  return Point(a.x + (c1*b2 - c2*b1)/d, a.y + (a1*c2 -a2*c1)/d);
}

// 7、求两圆相交的面积
// 两个圆的公共部分面积

double Area_of_overlap(Point c1,double r1,Point c2,double r2)
{
  double d = dist(c1,c2);
  if(r1 + r2 < d + eps)return 0;
  if(d < fabs(r1 - r2) + eps)
  {
    double r = min(r1,r2);
    return PI*r*r;
  }
  double x = (d*d + r1*r1 - r2*r2)/(2*d);
  double t1 = acos(x / r1);
  double t2 = acos((d - x)/r2);
  return r1*r1*t1 + r2*r2*t2 - d*r1*sin(t1);
}
// 8、PickPick Pick公式
// 顶点坐标均是整点的简单多边形：面积=内部格点数目+边上格点数目/2-1
