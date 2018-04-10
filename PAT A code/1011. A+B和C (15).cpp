#include<cstdio>
int main(){
	int t,testcase=1;
	long long a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case #");
		if(a+b>c){
			printf("%d: true\n",testcase++);
		}else{
			printf("%d: false\n",testcase++);
		}
	}
	return 0;
}