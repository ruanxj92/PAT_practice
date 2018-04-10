#include <cstdio>
#include <vector>
#include <algorithm>
int main(){
	int N,sum = 0;
	scanf("%d",&N);
	std::vector<int> seq(N);
	for(int i = 0;i!=N;++i){
		scanf("%d",&seq[i]);
		sum+=seq[i];
	}
	std::sort(seq.begin(),seq.end());
	if(N%2){
		printf("%d ",1);
	}else{		
		printf("%d ",0);
	}
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i!=N/2;++i){
		sum2+=seq[i];
	}
	sum1 = sum - sum2;
	int maxed = sum1 - sum2;
	if(maxed < 0) maxed = -maxed;
	printf("%d",maxed);
	return 0;
}