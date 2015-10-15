template<typename T>
struct fraction{
  T n,d;
  fraction(const T &_n=0,const T &_d=1):n(_n),d(_d)
  { T t=std::__gcd(n,d); n/=t,d/=t; if(d<0)n=-n,d=-d; }
  inline const fraction operator-()const
  { return fraction(-n,d); }¡¡ 
  inline const fraction operator+(const fraction &b)const
  { return fraction(n*b.d+b.n*d,d*b.d); }
  inline const fraction operator-(const fraction &b)const
  { return fraction(n*b.d-b.n*d,d*b.d); }
  inline const fraction operator*(const fraction &b)const
  { return fraction(n*b.n,d*b.d); }
  inline const fraction operator/(const fraction &b)const
  { return fraction(n*b.d,d*b.n); }
  inline const fraction operator+=(const fraction &b)
  { return *this=fraction(n*b.d+b.n*d,d*b.d); }
  inline const fraction operator-=(const fraction &b)
  { return *this=fraction(n*b.d-b.n*d,d*b.d); }
  inline const fraction operator*=(const fraction &b)
  { return *this=fraction(n*b.n,d*b.d); }
  inline const fraction operator/=(const fraction &b)
  { return *this=fraction(n*b.d,d*b.n); }
  inline bool operator <(const fraction &b)const
  { return n*b.d<b.n*d; }
  inline bool operator >(const fraction &b)const
  { return n*b.d>b.n*d; }
  inline bool operator ==(const fraction &b)const
  { return n*b.d==b.n*d; }
  inline bool operator <=(const fraction &b)const
  { return n*b.d<=b.n*d; }
  inline bool operator >=(const fraction &b)const
  { return n*b.d>=b.n*d; }
};
