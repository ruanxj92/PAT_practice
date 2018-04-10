#include <cstdio>
#include <cstring>
int main(){
	int check[256] = {0};
	char sell[1024],need[1024];
	int seln,neln;
	int extra = 0;
	scanf("%s\n%s",sell,need);
	seln = strlen(sell);
	neln = strlen(need);
	for(int i = 0;i<seln;++i){
		check[sell[i]]++;
	}
	bool yes = true;
	for(int i = 0;i<neln;++i){
		if(check[need[i]]>0){
			check[need[i]]--;
		}else{
			yes = false;
			extra++;
		}
	}
	if(yes){
		printf("Yes %d",seln-neln);
	}else{
		printf("No %d",extra);
	}
	return 0;
}