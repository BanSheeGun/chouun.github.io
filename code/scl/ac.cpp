#include<queue>
#include<vector>
template<char L='a',char R='z'>
class ac_automaton{
    private:
        struct joe{
            int next[R-L+1],fail,cnt;
            joe():fail(-1),cnt(0){
                for(int i=0;i<=R-L;++i)next[i]=0;
            }
        };
        std::vector<joe> S;
    public:
        ac_automaton():S(1){}/*root為0*/
        inline void clear(){
            S.resize(1);
            for(int i=0;i<=R-L;++i)S[0].next[i]=0;
        }
        inline void insert(const char *s){
            int o=0;
            for(int i=0,id;s[i];++i){
                id=s[i]-L;
                if(!S[o].next[id]){
                    S.push_back(joe());
                    S[o].next[id]=S.size()-1;
                }
                o=S[o].next[id];
            }
            ++S[o].cnt;
        }
        inline void build(){
            std::queue<int > q;
            q.push(0);
            while(q.size()){
                int pa=q.front(),id;
                q.pop();
                for(int i=0;i<=R-L;++i){
                    if(!S[pa].next[i])continue;
                    id=S[pa].fail;
                    while(~id&&!S[id].next[i])id=S[id].fail;
                    S[S[pa].next[i]].fail=~id?S[id].next[i]:0;
                    q.push(S[pa].next[i]);
                }
            }
        }
        /*傳回所有字串被匹配成功的次數*/
        inline int find(const char *s){
            int ans=0,id,p=0,t;
            for(int i=0;s[i];++i){
                id=s[i]-L;
                while(!S[p].next[id]&&p)p=S[p].fail;
                if(!S[p].next[id])continue;
                t=p=S[p].next[id];
                while(t){
                    ans+=S[t].cnt;/*如果cnt>0則匹配成功*/ 
                    t=S[t].fail;
                }
            }
            return ans;
        }
};
