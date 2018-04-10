#include <cstdio>
int main(){
	int n,order = 1,ans = 0;
	int left,now,right;
	scanf("%d",&n);
	while(n/order){
		left = n/(order*10);//higher digit
		now = n/order%10;//current digit
		right = n%order;//lower digit
		if(now == 0)
			ans+=left*order;
		else if(now == 1)
			ans+=left*order+right+1;
		else
			ans+=(left+1)*order;
		order*=10;
	}
	printf("%d",ans);
	return 0;
}