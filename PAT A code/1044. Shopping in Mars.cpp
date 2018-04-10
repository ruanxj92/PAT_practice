#include <cstdio>
#include <vector>
int upper_bound(const std::vector<int> &cursum,int L,int R,const int &target){
	int mid;
	while(L<R){
		mid = L+(R-L)/2;
		if(cursum[mid] > target) R = mid;
		else L= mid+1;
	}
	return L;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input", "r", stdin);
#else
// online submission
#endif
	int N,M;
	int mincost = 100000000;
	scanf("%d %d",&N,&M);	
	std::vector<int> cursum(N+1,0);
	for(int i = 1;i<=N;++i){
		scanf("%d",&cursum[i]);
		cursum[i] += cursum[i-1] ;
	}
	int target,j;
	for(int i = 1;i<=N;++i){// binary search for M or mincost
		target = cursum[i-1]+M;
		j = upper_bound(cursum,i,N+1,target);
		if(cursum[j-1] - cursum[i-1] == M){
			mincost = M;
			break;
		}else if(j<=N && cursum[j] - cursum[i-1] < mincost){
			mincost = cursum[j] - cursum[i-1];
		}
	}
	for(int i = 1;i<=N;++i){// output the target value
		target = cursum[i-1] + mincost;
		j = upper_bound(cursum,i,N+1,target);
		if(cursum[j-1] - cursum[i-1] == mincost){			
			printf("%d-%d\n", i,j-1);
		}
	}
	return 0;
}