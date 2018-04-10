#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
int main(){
	int num;
	scanf("%d\n",&num);
	std::map<std::string,std::set<int> > datalist[5];
	for(int i=0;i<num;++i){
		int id;
		scanf("%d\n",&id);
		char tmp[1024];
		for(int j =0;j<5;++j){
			gets(tmp);
			if(j == 2){
				std::string str(tmp);
				int head=0,tail=0;
				while(head<str.size()){
					while(head<str.size() && str[head]==' ') head++;
					tail = 0;
					while(head+tail<str.size() && str[head+tail]!=' ') tail++;
					if(str.substr(head,tail)!="")
						datalist[j][str.substr(head,tail)].insert(id);	
					head +=tail;
				}
			}else{
				datalist[j][tmp].insert(id);			
			}			
		}
	}
	scanf("%d\n",&num);
	for(int i = 0;i<num;++i){
		int equery;
		char keyword[1024];
		scanf("%d: ",&equery);
		gets(keyword);
		printf("%d: %s\n",equery,keyword);
		std::map<std::string,std::set<int> >::iterator j = datalist[--equery].find(keyword);
		if(j!=datalist[equery].end()){
			for(auto k = j->second.begin();k!=j->second.end();++k){
				printf("%07d\n",*k);
			}
		}else{
			printf("Not Found\n");
		}
	}
	return 0;
}