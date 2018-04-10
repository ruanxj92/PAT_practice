#include <cstdio>
#include <algorithm>
#include <vector>
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int> v(n);
	for(int i = 0;i<n;++i){
		scanf("%d",&v[i]);
	}
	std::sort(v.begin(),v.end());
	int res = v[0];
	for(int i = 1;i<n;++i){
		res = (v[i] + res)/2;
	}
	printf("%d",res);
	return 0;
}