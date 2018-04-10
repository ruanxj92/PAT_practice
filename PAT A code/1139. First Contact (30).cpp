#include <cstdio>
#include <vector>
struct pair{
    int first,second;
}tmpp;
const int maxn = 10000;
bool G[maxn][maxn] = {false};
int gender[maxn] = {0};
int chat2int(char a[]){
    bool neg = false;
    int i = 0;
    if(a[i] == '-'){
        neg = true;
        i++;
    }
    int ans = 0;
    while(a[i]){
        ans = ans*10 + a[i]-'0';
        ++i;        
    }
    if(neg) return -ans;
    else return ans;
}
bool cmp(pair a,pair b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main() {
    int n,m,a,b,ga,gb;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;++i){
        char tmp[8];
        scanf("%s",tmp);
        a = chat2int(tmp);
        if(tmp[0] == '-'){
            ga = -1;
            a = -a;
        }else{
            ga = 1;
        }
        scanf("%s",tmp);
        b = chat2int(tmp);
        if(tmp[0] == '-'){
            gb = -1;
            b = -b;
        }else{
            gb = 1;
        }
        gender[a] = ga;gender[b] = gb;
        G[a][b] = G[b][a] = true;
    }
    int query;
    scanf("%d",&query);
    std::vector<pair> ans;
    for(int k = 0;k<query;++k){
        int start,end;
        scanf("%d %d",&start,&end);
        ans.clear();
        if(start<0) start = -start;
        if(end<0) end = -end;
        for(int i = 0;i<maxn;++i){
            if(G[start][i]&&gender[start]==gender[i]&&i!=end){
                for(int j = 0;j<maxn;++j){
                    if(G[end][j]&&gender[end]==gender[j]&&j!=start){
                        if(G[i][j]){
                            tmpp.first = i;
                            tmpp.second = j;
                            ans.push_back(tmpp);
                        }
                    }
                }                
            }
        }
        printf("%u\n",ans.size());
        if(ans.size()){
            for(int i = 0;i<ans.size();++i){
               printf("%04d %04d\n",ans[i].first,ans[i].second);
            }    
        }        
    }
}