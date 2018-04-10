#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
int main(){
	std::vector<std::set<int> > group;
	int N,M,K,gp1,gp2;
	scanf("%d",&N);
	group.resize(N);
	for(int i = 0;i!=N;++i){
		scanf("%d",&M);
		for(int j = 0;j!=M;++j){
			int tmp;
			scanf("%d",&tmp);
			group[i].insert(tmp);
		}
	}
	scanf("%d",&K);
	for(int i =0;i!=K;++i){
		scanf("%d%d",&gp1,&gp2);
		gp1--;
		gp2--;
		int common = 0;
		for(auto j = group[gp1].begin();j!=group[gp1].end();++j){
			if(group[gp2].find(*j)!=group[gp2].end()){
				++common;
			}
		}
		printf("%.1lf%%\n", 100.0*common/(group[gp1].size()+group[gp2].size()-common));
	}
	return 0;
}