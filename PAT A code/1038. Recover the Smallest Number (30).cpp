#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
bool cmp(std::string a,std::string b){
    return a+b<b+a;
}
int main(){
    int n;
    scanf("%d",&n);
    char tmp[9];
    std::vector<std::string> seq;
    for(int i = 0; i < n ; ++i){
        scanf("%s",tmp);
        seq.push_back(tmp);
    }
    std::sort(seq.begin(),seq.end(),cmp);
    std::string ans;
    for(auto i = seq.begin();i!=seq.end();++i){
        ans+=*i;
    }
    while(ans.size()&&ans[0]=='0'){
        ans.erase(ans.begin());
    }
    if(ans.size()==0) printf("0");
    else printf("%s", ans.c_str());
    return 0;
}