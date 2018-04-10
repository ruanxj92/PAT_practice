#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
struct node{
	char name[16];
	int age,networth;
public: bool operator < (const node &b){
		if(networth!=b.networth)
			return networth > b.networth;
		if(age!=b.age)
			return age < b.age;
		return strcmp(name,b.name)<0;
	}
}temp;
int main(){
	int N,K;
	scanf("%d %d",&N,&K);	
	std::vector<node> ranking;
	ranking.resize(N);
	for(auto i = ranking.begin();i!=ranking.end();++i){
		scanf("%s %d %d",&(i->name),&(i->age),&(i->networth));
	}
	sort(ranking.begin(),ranking.end());
	if(ranking.size()>K*100)//对于单个年龄段不超过100，一共不超过K*100
		ranking.resize(K*100);
	for(int i = 0;i<K;++i){
		int maxoutput,minage,maxage,count = 0;
		scanf("%d %d %d",&maxoutput,&minage,&maxage);
		printf("Case #%d:\n",i+1);
		for(int i = 0;i<ranking.size();++i){
			if(ranking[i].age <= maxage && ranking[i].age >=minage&&count<maxoutput){
				++count;
				printf("%s %d %d\n",
					ranking[i].name,
					ranking[i].age,
					ranking[i].networth);
				if(count == maxoutput){
					break;
				}
			}
		}
		if(count == 0)
			printf("None\n");
	}
	return 0;
}