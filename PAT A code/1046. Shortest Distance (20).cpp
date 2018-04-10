#include<cstdio>
int main(){
	const int MAXN = 100005;
	int N,D[MAXN]={0},dis[MAXN]={0},sum=0,M;
	int source,target;
	scanf("%d",&N);
	for(int i = 1;i<=N;++i){
		scanf("%d",D+i);
		sum+=D[i];
		dis[i] = sum;
	}
	scanf("%d",&M);
	for(int i = 0;i<M;++i){
		scanf("%d %d",&source,&target);
		int distance = dis[source-1] - dis[target-1];
		if(distance<0)
			distance = - distance;
		distance = distance < (sum - distance)?distance:(sum - distance);
		printf("%d\n",distance);
	}
	return 0;
}