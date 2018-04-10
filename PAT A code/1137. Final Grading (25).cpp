#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
struct grade{
    int p,mid,fin,all;
	std::string name;
    grade(int _p=-1):p(_p){
        mid=fin = -1;
    }
	bool operator<(const grade &b)const{
		if(all!=b.all) return all>b.all;
		return name<b.name;
	}
};
std::map<std::string,grade> gradelist;
int main() {
    int p,m,n,tmpg;
    scanf("%d %d %d",&p,&m,&n);
    char name[21];
	std::string str;
    for(int i = 0;i<p;++i){
        scanf("%s %d",name,&tmpg);
		str = name;
        if(tmpg>=200) 
			gradelist[str] = grade(tmpg);
    }
    for(int i = 0;i<m;++i){
        scanf("%s %d",name,&tmpg);
		str = name;
        if(gradelist.count(str))
			gradelist[str].mid = tmpg;
    }
	//std::set<grade> ans;
	std::vector<grade> ans;
	auto i = gradelist.begin();
    for(int j = 0;j<n;++j){
        scanf("%s %d",name,&tmpg);
		str = name;
        if(tmpg>=60&&(i = gradelist.find(str))!=gradelist.end()){
			i->second.fin = tmpg;	
			i->second.name = str;
			if(i->second.mid>i->second.fin){
				i->second.all = i->second.mid*.4+i->second.fin*.6+.5;
			}else{
				i->second.all = i->second.fin;
			}
			//ans.insert(i->second);
			ans.push_back(i->second);
		}
    }
	std::sort(ans.begin(),ans.end());
	for(auto i = ans.begin();i!=ans.end();++i){
		printf("%s %d %d %d %d\n",
			i->name.c_str(),i->p,i->mid,i->fin,i->all);
	}
	return 0;
}