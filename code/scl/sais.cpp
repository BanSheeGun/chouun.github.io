#include<string.h>
#define MAGIC(XD){\
    memset(sa,0,sizeof(int)*n);\
    memcpy(x,c,sizeof(int)*z);\
    XD\
    memcpy(x+1,c,sizeof(int)*(z-1));\
    for(i=0;i<n;++i){\
        if(sa[i]&&!t[sa[i]-1])sa[x[s[sa[i]-1]]++]=sa[i]-1;\
    }\
    memcpy(x,c,sizeof(int)*z);\
    for(i=n-1;i>=0;--i){\
        if(sa[i]&&t[sa[i]-1])sa[--x[s[sa[i]-1]]]=sa[i]-1;\
    }\
}
void sais(int *s,int *sa,int *p,bool *t,int *c,int n,int z){
    bool neq=t[n-1]=1;
    int nn=0,nmxz=-1,*q=sa+n,*ns=s+n,*x=c+z,lst=-1,i,j;
    memset(c,0,sizeof(int)*z);
    for(i=0;i<n;++i)++c[s[i]];
    for(i=0;i<z-1;++i)c[i+1]+=c[i];
    for(i=n-2;i>=0;i--)t[i]=(s[i]==s[i+1]?t[i+1]:s[i]<s[i+1]);
    MAGIC(
        for(i=1;i<n;++i){
            if(t[i]&&!t[i-1])sa[--x[s[i]]]=p[q[i]=nn++]=i;
        }
    );
    for(i=0;i<n;++i)if((j=sa[i])&&t[j]&&!t[j-1]){
        neq=lst<0||memcmp(s+j,s+lst,(p[q[j]+1]-j)*sizeof(int));
        ns[q[lst=j]]=nmxz+=neq;
    }
    if(nmxz==nn-1)for(i=0;i<nn;++i)q[ns[i]]=i;
    else sais(ns,q,p+nn,t+n,c+z,nn,nmxz+1);
    MAGIC(
        for(i=nn-1;i>=0;--i)sa[--x[s[p[q[i]]]]]=p[q[i]];
    );
}
#undef MAGIC
/*****************這些是需要用到的陣列大小**************/
static const int MXN=10000000;
int s[MXN*2+5],sa[MXN*2+5],p[MXN+5],c[MXN*2+5];
bool t[MXN*2+5];