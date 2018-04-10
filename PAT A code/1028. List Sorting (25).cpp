#include <cstdio>
#include <algorithm>
#include <cstring>
struct node{
	int id;
	char name[10];
	int grade;
}list[100000];
bool cmp1(node &a,node &b){
	return a.id<b.id;
}
bool cmp2(node &a,node &b){
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	return a.id<b.id;
}
bool cmp3(node &a,node &b){
	if(a.grade!=b.grade)
		return a.grade<b.grade;
	return a.id<b.id;
}
int main(){
	int N,C;
	scanf("%d %d",&N,&C);
	for(int i = 0;i<N;++i){
		scanf("%d %s %d",&list[i].id,&list[i].name,&list[i].grade);
	}
	switch(C){
	case 1:
		std::sort(list,list+N,cmp1);
		break;
	case 2:		
		std::sort(list,list+N,cmp2);
		break;
	case 3:		
		std::sort(list,list+N,cmp3);
		break;
	}
	for(int i = 0;i<N;++i){
		printf("%06d %s %d\n",list[i].id,list[i].name,list[i].grade);
	}
	return 0;
}