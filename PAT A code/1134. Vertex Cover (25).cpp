#include <cstdio>
#include <vector>
#include <map>
bool check(std::vector<bool> &hash,std::vector<std::pair<int,int>> &GE){
	for(int i = 0;i<GE.size();++i){
		if(hash[GE[i].first]||hash[GE[i].second]){
			continue;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	int ver,edg;
	scanf("%d %d",&ver,&edg);
	std::vector<std::pair<int,int>> GE(edg);
	for(int i= 0;i<edg;++i){
		scanf("%d %d",&GE[i].first,&GE[i].second);
	}
	int q;
	std::vector<bool> hash;
	scanf("%d",&q);
	for(int i = 0;i<q;++i){
		hash.assign(ver,false);
		int len;
		scanf("%d",&len);
		for(int j = 0;j<len;++j){
			int pos;
			scanf("%d",&pos);
			hash[pos] = true;
		}
		if(check(hash,GE)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}