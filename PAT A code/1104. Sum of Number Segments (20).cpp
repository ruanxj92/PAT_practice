#include <cstdio>
#include <vector>
int main(){
	int N;
	scanf("%d",&N);
	double sum=0,tmp;
	for(int i = 0;i<N;++i){
		scanf("%lf",&tmp);
		sum+=tmp*(N-i)*(i+1);
	}
	printf("%.2lf\n",sum);
}
