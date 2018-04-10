#include <cstdio>
int main(){
	int n,now=0,next,second=0;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&next);
		if(next > now){
			second += 6 * (next - now);
		}else if(next < now){
			second += 4 * (now - next);
		}
		second+=5;
		now = next;
	}
	printf("%d",second);
	return 0;
}