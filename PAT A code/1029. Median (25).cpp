#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long LL;
const LL inf = ((LL)1<<63)-1;
int main(){
	unsigned int len1,len2,mid;
	std::vector<LL> sq1,sq2,sq;
	scanf("%d",&len1);
	sq1.resize(len1);
	for(int i = 0;i<len1;++i){
		scanf("%lld",&sq1[i]);
	}
	scanf("%d",&len2);
	sq2.resize(len2);
	sq.resize(len1+len2);
	for(int i = 0;i<len2;++i){
		scanf("%lld",&sq2[i]);
	}
	mid = (len1+len2-1)/2;
	std::merge(sq1.begin(),sq1.end(),sq2.begin(),sq2.end(),sq.begin());
	printf("%lld",sq[mid]);
	return 0;
}