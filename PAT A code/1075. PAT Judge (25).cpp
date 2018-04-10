#include <cstdio>
#include <vector>
#include <algorithm>
struct user{
	int id,sum,perfectcount,rank;
	std::vector<int> problem;
	bool valid;
}temp;
bool cmp(const user& a,const user& b){
		if(a.sum!=b.sum){
			return a.sum > b.sum;
		}
		if(a.perfectcount!=b.perfectcount){
			return a.perfectcount > b.perfectcount;
		}
		return a.id < b.id;	
}
int main(){
	int usersnum,problemsnum,submittionsnum;
	scanf("%d %d %d",
		&usersnum,&problemsnum,&submittionsnum);
	std::vector<user> list;
	list.resize(usersnum);
	for(int i = 0;i<usersnum;++i){//init
		list[i].id = i;
		list[i].sum=0;
		list[i].perfectcount=0;
		list[i].rank = 0;
		list[i].valid = false;
		list[i].problem.resize(problemsnum);
		std::fill(list[i].problem.begin(),list[i].problem.end(),-2);
	}
	std::vector<int> ref;	
	ref.resize(problemsnum);
	for(int i = 0;i<problemsnum;++i){
		scanf("%d",&ref[i]);
	}
	int user,pro,sco;
	for(int i = 0;i<submittionsnum;++i){
		scanf("%d %d %d",&user,&pro,&sco);
		--user;
		--pro;
		if(sco>list[user].problem[pro]){
			list[user].problem[pro] = sco>=0?sco:0;
		}
		if(sco>=0){
			list[user].valid = true;
		}
	}
	for(int i = list.size()-1;i>=0;--i){
		for(int j = 0;j!=list[i].problem.size();++j){
			if(list[i].problem[j]>0){
				list[i].sum += list[i].problem[j];
			}
			if(list[i].problem[j] == ref[j]){
				++(list[i].perfectcount);
			}
		}
		if(!list[i].valid){
			list.erase(list.begin()+i);
		}
	}
	sort(list.begin(),list.end(),cmp);
	for(int i = 0;i<list.size();++i){
		if(i !=0){//rank
			if(list[i].sum == list[i-1].sum){
				list[i].rank = list[i-1].rank;
			}else{
				list[i].rank = i;
			}
			printf("\n%d",list[i].rank+1);
		}
		else{
			printf("1");
		}
		printf(" %05d %d",list[i].id+1,list[i].sum);//sum
		for(int j = 0;j<list[i].problem.size();++j){
			if(list[i].problem[j]>=-1)
				printf(" %d",list[i].problem[j]>0?list[i].problem[j]:0);
			else
				printf(" -");
		}		
	}
	return 0;
}