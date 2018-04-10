#include<cstdio>
#include<vector>
#include<algorithm>
int main(){
    int n;
    std::vector<int> seq1,seq2;
    scanf("%d",&n);
    for(int i = 0;i<n;++i){
        int tmp;
        scanf("%d",&tmp);
        seq1.push_back(tmp);
    }
    scanf("%d",&n);
    for(int i = 0;i<n;++i){
        int tmp;
        scanf("%d",&tmp);
        seq2.push_back(tmp);
    }
    std::sort(seq1.begin(),seq1.end());
    std::sort(seq2.begin(),seq2.end());
    int sum = 0;
    for(auto i = seq1.begin(),j = seq2.begin();
        !(i==seq1.end()||j==seq2.end());
        ++i,++j){
            if( *i<0 && *j<0){                
                int k = *i * *j;
                sum += k;
            }else{
                break;
            }
    }
    for(auto i = seq1.rbegin(),j = seq2.rbegin();
        !(i==seq1.rend()||j==seq2.rend());
        ++i,++j){
            if( *i>0 && *j>0){                
                int k = *i * *j;
                sum += k;
            }else{
                break;
            }
    }
    printf("%d\n",sum);
    return 0;
}