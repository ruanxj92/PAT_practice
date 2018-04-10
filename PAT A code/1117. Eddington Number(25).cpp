#include <cstdio>
#include <vector>
#include <algorithm>
int main(){
	int n,count = 0;
	scanf("%d",&n);
	std::vector<int> riding;
	for(int i = 1;i<=n;++i){
		int today;
		scanf("%d",&today);
		riding.push_back(today);
	}
	std::sort(riding.begin(), riding.end(),std::greater<int>());//complecity nlogn , afraid of overtiming.luckly, its chache friendly
	for(int i =0;i<n;++i){
		if(riding[i]<=i+1){
			break;
		}else{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}