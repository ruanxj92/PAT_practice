#include <cstdio>
#include <algorithm>
#include <vector>
struct node{
	char name[11];
	char id[11];
	int grade;
	
bool operator < (node &b){
	return grade>b.grade;
}
};
int main(){
	int n;
	scanf("%d",&n);
	std::vector<node> list;
	list.resize(n);
	for(int i = 0;i!=n;++i){
		scanf("%s %s %d",&list[i].name,&list[i].id,&list[i].grade);
	}
	std::sort(list.begin(),list.end());
	int grade1,grade2,pos1=0,pos2=n;
	scanf("%d %d",&grade1,&grade2);
	bool printed = false;
	for(int i =0;i<n;++i){
		if(list[i].grade>=grade1 && list[i].grade<=grade2){
			printf("%s %s\n",list[i].name,list[i].id);
			printed = true;
		}else if(list[i].grade<grade1){
			break;
		}
	}
	if(!printed){
		printf("NONE\n");
	}
	return 0;
}