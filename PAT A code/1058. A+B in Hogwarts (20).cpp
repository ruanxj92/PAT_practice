#include <cstdio>
int main(){
	long long g,s,k,sum = 0;
	const  int a = 17,b = 29;
	scanf("%lld.%lld.%lld",&g,&s,&k);
	sum += g*a*b + s*b + k;
	scanf("%lld.%lld.%lld",&g,&s,&k);
	sum += g*a*b + s*b + k;
	printf("%lld.%lld.%lld",sum/b/a,(sum/b)%a,sum%b);
	return 0;
}