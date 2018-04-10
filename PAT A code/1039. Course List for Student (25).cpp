#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200000;
int numid(char *A){
	return (A[0] - 'A') * 26 * 26 * 10 + (A[1] - 'A') * 26 * 10 + (A[2] - 'A') * 10 + A[3] - '0';
}
vector<int> courselist[maxn];
int main(){
	int K,N,nameid;
	char name[5];
	scanf("%d%d",&N,&K);
	for(int i = 0;i<K;++i){
		int course,num;
		scanf("%d%d",&course ,&num);
		for(int j = 0;j<num;++j){
			scanf("%s",name);
			nameid = numid(name);
			courselist[nameid].push_back(course);
		}
	}
	for(int i = 0;i<N;++i){
		scanf("%s",name);
		nameid = numid(name);
		printf("%s ",name);
		if(courselist[nameid].size()){
			printf("%d",courselist[nameid].size());
			sort(courselist[nameid].begin(),courselist[nameid].end());
			for(auto j = courselist[nameid].begin();j!=courselist[nameid].end();++j){
				printf(" %d",*j);
			}
			printf("\n");
		}else{
			printf("0\n");
		}
	}
	return 0;
}