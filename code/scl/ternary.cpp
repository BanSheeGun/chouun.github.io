/*
f是傳入的函數，eps表示精準度，通常設為1e-5
l,r為邊界，所以必須先預估出極值點的位置 
*/
template<typename _F>
inline double ternary_search(_F f,double l,double r,double eps){
    static double m1,m2;
    while(r-l>eps){
        m1=l+(r-l)/3; m2=l+(r-l)*2/3;
        if(f(m1)>f(m2))l=m1;/*如果對象是倒U型函數，則改成 < */
        else r=m2;
    }
    return l;
}
inline double f(double x){
    return x*x-2*x+1;
}
printf("%.6f\n",ternary_search(f,-10,10,1e-6)); /*假設邊界為-10~10*/