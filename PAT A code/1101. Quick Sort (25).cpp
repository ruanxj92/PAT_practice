#include <cstdio>
#include <vector>
#include <algorithm>
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int> seq(n,0),rightmin(n,0),leftmax(n,0),pistol;
	for(int i =0;i!=n;++i){
		scanf("%d",&seq[i]);
	}
	rightmin[n-1] = seq[n-1];
	for (int i  = n-2;i>=0;--i){
		rightmin[i] = std::min(rightmin[i+1],seq[i]);
	}
	leftmax[0] = seq[0];
	if(seq[0] <=rightmin[0])
		pistol.push_back(seq[0]);
	for (int i  = 1;i<n;++i){
		leftmax[i] = std::max(leftmax[i-1],seq[i]);
		if(seq[i] <= rightmin[i] && seq[i] >= leftmax[i]){
			pistol.push_back(seq[i]);
		}
	}
	printf("%d\n",pistol.size() );
	for(int i = 0;i<pistol.size();++i){
		if (i) printf(" ");
		printf("%d",pistol[i] );
	}
	printf("\n");
	return 0;
}