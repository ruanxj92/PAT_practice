#include <cstdio>
const int maxn = 1e6+1;
int couple[maxn],has[maxn];
int main(){
	for(int i = 0;i<maxn;couple[i] = 1e6,++i)
		;
	for(int i = 0;i<maxn;has[i] = 0,++i)
		;
	int n,count=0;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		couple[a] = b;
		couple[b] = a;
	}
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		int id;
		scanf("%d",&id);
		int other = couple[id];
		if(has[id] == 0){
			count++;
			has[id] = 1;
			has[other] = -1;
		}else if(has[id] == -1){
			has[other] = -1;
			count--;
		}
	}
	printf("%d\n",count);
	for(int i = 0;i<maxn;++i){
		if(has[i] == 1){
			printf("%05d",i);
			if(--count){
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}