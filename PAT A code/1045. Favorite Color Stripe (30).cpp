#include <cstdio>
#include <vector>
int main(){
	int N,M,L,len=0;
	scanf("%d%d",&N,&M);
	std::vector<int> A(M+1,0);
	for(int i = 1;i<=M;++i){
		scanf("%d",&A[i]);
	}
	scanf("%d",&L);
	std::vector<int> B(L+1,0);
	for(int i = 1;i<=L;++i){
		scanf("%d",&B[i]);
	}
	std::vector<std::vector<int> > dp(M+1);
	for(int i = 0;i<=M;++i){
		dp[i].assign(L+1,0);//关键在第0行，第0列清零
	}
	for(int i =1;i<=M;++i){
		for(int j = 1;j<=L;++j){//由0行0列拓展开
			int max = dp[i-1][j] > dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			if(A[i] == B[j]){
				dp[i][j] = max+1;
			}else{
				dp[i][j] = max;
			}
		}
	}
	printf("%d\n", dp[M][L]);
	return 0;
}