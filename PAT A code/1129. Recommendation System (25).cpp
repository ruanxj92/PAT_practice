#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
std::vector<int> present;
std::vector<int> rec;
std::vector<bool> inrec;
bool cmp(int a,int b){
	if(present[a] != present[b])
	return present[a] > present[b];
	else return a < b;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	present.assign(n+1,0);
	inrec.assign(n+1,false);
	for(int i = 0;i<n;++i){
		int now;
		scanf("%d",&now);
		if(i){
			printf("%d:",now);
			for(int j = 0;j<rec.size();++j){				
				printf(" %d",rec[j]);			
			}
			printf("\n");
		}
		present[now]++;
		if(!inrec[now]) {
			rec.push_back(now);
			inrec[now] = true;
		}
		std::sort(rec.begin(),rec.end(),cmp);
		if(rec.size()>k){
			inrec[rec[k]] = false;
			rec.pop_back();
		}
	}
	return 0;
}