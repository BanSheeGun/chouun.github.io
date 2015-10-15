struct P{
    int data,id;
    P(int d=0,int i=0):data(d),id(i){}
    inline friend bool operator<(const P &a,const P &b){
        return a.id<b.id;
    }
};
int n,now;
std::vector<P >tree[100005];
inline void init(){
    now=0;
    for(int i=1;i<=n;++i)tree[i].clear(),tree[i].push_back(P());
}
inline void modify(int x,int d){
    for(;x<=n;x+=x&(-x))tree[x].push_back(P(tree[x].back().data+d,now));
    ++now; 
}
inline int query(int x,int id){/*查詢第id次操作的區間和，id從0開始計算*/
    int ans=0;
    std::vector<P >::iterator a;
    for(;x;x-=x&(-x)){
        a=std::upper_bound(tree[x].begin(),tree[x].end(),P(id))-1;
        ans+=a->data;
    }
    return ans;
}
