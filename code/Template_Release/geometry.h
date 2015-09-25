// Name : Computational Geometry 计算几何
// Copyright : fateud.com
#ifndef GEOMETRY_H_
#define GEOMETRY_H_
#define GEOMETRY_H_VERSION 20150924L
#include <algorithm>
#include <vector>
#ifndef CSL_ALGO_H_
#pragma message("need : csl_algo.h");
#include <csl_algo.h>
#endif
namespace csl {
  struct point {
    point(double __x = 0, double __y = 0) : x(__x), y(__y) { }
    double x, y;
  };
  point operator - (const point& a, const point& b)
  { return point(a.x - b.x, a.y - b.y); }
  double operator ^ (const point& a, const point& b)
  { return a.x * b.y - a.y * b.x; }
  double operator * (const point& a, const point& b)
  { return a.x * b.x + a.y * b.y; }
  bool operator < (const point& a, const point& b)
  { return sgn(a.x - b.x) ? a.x < b.x : a.y < b.y; }
  inline point rotate(const point& p, double r)
  { return point(p.x * cos(r) - p.y * sin(r), p.x * sin(r) + p.y * cos(r)); }
  inline double dist(const point& a, const point& b)
  { return sqrt((a - b) * (a - b)); }
  struct line {
    line() : s(), e() { }
    line(point __s, point __e) : s(__s), e(__e) { }
    point s, e;
  };
  std::pair<int, point> operator & (const line& a, const line& b) {
    if(sgn((a.s - a.e) ^ (b.s - b.e)) == 0)
      return std::make_pair((sgn((a.s - b.e) ^ (b.s - b.e)) != 0), point());
    double t = ((a.s - b.s) ^ (b.s - b.e)) / ((a.s - a.e) ^ (b.s - b.e));
    return std::make_pair(2,point(a.s.x+(a.e.x-a.s.x)*t,a.s.y+(a.e.y-a.s.y)*t));
  }
  bool inter_ss(const line& a, const line& b) {
    return
        std::max(a.s.x, a.e.x) >= std::min(b.s.x, b.e.x) &&
        std::max(b.s.x, b.e.x) >= std::min(a.s.x, a.e.x) &&
        std::max(a.s.y, a.e.y) >= std::min(b.s.y, b.e.y) &&
        std::max(b.s.y, b.e.y) >= std::min(a.s.y, a.e.y) &&
        sgn((b.s - a.e) ^ (a.s - a.e)) * sgn((b.e - a.e) ^ (a.s - a.e)) <= 0 &&
        sgn((a.s - b.e) ^ (b.s - b.e)) * sgn((a.e - b.e) ^ (b.s - b.e)) <= 0;
  }
  inline bool inter_ls(const line& a, const line& b)
  { return sgn((b.s-a.e)^(a.s-a.e)) * sgn((b.e-a.e)^(a.s-a.e)) <= 0; }
  point p2line(const point& p, const line& l) {
    double t = ((p - l.s) * (l.e - l.s)) / ((l.e - l.s) * (l.e - l.s));
    return point(l.s.x + (l.e.x - l.s.x) * t, l.s.y + (l.e.y - l.s.y) * t);
  }
  point p2seg(const point& p, const line& l) {
    double t = ((p - l.s) * (l.e - l.s)) / ((l.e - l.s) * (l.e - l.s));
    if (t >= 0 && t <= 1)
      return point(l.s.x + (l.e.x - l.s.x) * t, l.s.y + (l.e.y - l.s.y) * t);
    else return dist(p, l.s) < dist(p, l.e) ? l.s : l.e;
  }
  double ploy_area(const point p[], int n) {
    double res = 0;
    for (int i = 0; i < n; ++i) res += (p[i] ^ p[(i+1)%n]) / 2;
    return fabs(res);
  }
  inline bool ponseg(const point& p, const line& l) {
    return
        sgn((l.s - p) ^ (l.e - p)) == 0 &&
        sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0 &&
        sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
  }
  int pincploy(point x, const point p[], int n) {
    for (int i = 0; i < n; ++i) {
      if (sgn((p[i] - x) ^ (p[(i+1)%n] - x)) < 0) return -1;
      if (ponseg(x, line(p[i], p[(i+1)%n]))) return 0;
    }
    return 1;
  }
  int pinploy(point x, const point p[], int n) {
    line ray(x, point(x.y, -1e11));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      line side = line(p[i], p[(i+1)%n]);
      if (ponseg(x, side)) return 0;
      if (sgn(side.s.y - side.e.y) == 0) continue;
      if (ponseg(side.s, ray))
      { if (sgn(side.s.y - side.e.y) > 0) cnt++; }
      else if (ponseg(side.e, ray))
      { if (sgn(side.e.y - side.s.y) > 0) cnt++; }
      else if (inter_ss(ray, side)) cnt++;
    }
    return cnt & 1 ? 1 : -1;
  }
  bool iscpoly(const point p[], int n) {
    bool s[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i) {
      s[sgn((p[(i+1)%n]-p[i]) ^ (p[(i+2)%n]-p[i]))+1] = true;
      if (s[0] && s[2]) return false;
    }
    return true;
  }
  static point graham_T;
  bool graham_cmp(point p1, point p2) {
    double tmp = (p1 - graham_T) ^ (p2 - graham_T);
    if (sgn(tmp) > 0) return true;
    else if (sgn(tmp) == 0 && sgn(dist(p1, graham_T) - dist(p2, graham_T)) <= 0)
      return true;
    else return false;
  }
  std::vector<point> graham(const point p[], int n) {
    std::vector<point> res(p, p + n);
    for (int i = res.size() - 1; i; --i)
      if (res[0] < res[i]) std::swap(res[0], res[i]);
    graham_T = res[0];
    std::sort(res.begin() + 1, res.end(), graham_cmp);
    int m = 2;
    for (int i = 2; i < n; ++i) {
      while (m > 1 && sgn((res[m-1] - res[m-2]) ^ (res[i] - res[m-2])) <= 0) --m;
      res[m++] = res[i];
    }
    res.resize(m); return res;
  }
  double bound_rect(const point p[], int n) {
    double res = 1e30;
    for (int i = 0; i < n; ++i) {
      point p1 = p[i+1] - p[i];
      double min1 = 1e30, max1 = -1e30, min2 = 1e30, max2 = -1e30;
      for (int j = 0; j < n; ++j) {
        point p2 = p[j]; double tmp1 = + (p1 ^ p2), tmp2 = - (p1 * p2);
        if (min1 > tmp1) min1 = tmp1; if (max1 < tmp1) max1 = tmp1;
        if (min2 > tmp2) min2 = tmp2; if (max2 < tmp2) max2 = tmp2;
      }
      double tmp = (max1 - min1) * (max2 - min2) / (p1.x* p1.x + p1.y * p1.y);
      if (res > tmp) res = tmp;
    }
    return res;
  }
} // namespace csl
#endif /* GEOMETRY_H_ */
