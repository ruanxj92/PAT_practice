/*https://www.patest.cn/contests/pat-a-practise/1048
	*/
#include<cstdio>
#include<vector>
#include<algorithm>
const int MAXN = 1005;
int main(){
	int N,M;
	std::vector<int> coins;
	scanf("%d %d",&N,&M);
	int tmp;
	int hascoin[MAXN ] = {0};
	for(int i = 0;i!=N;++i){
		scanf("%d",&tmp);
		coins.push_back(tmp);
		++hascoin[tmp];
	}
	std::sort(coins.begin(),coins.end());
	int secondcoin ;
	for(std::vector<int>::reverse_iterator i = coins.rbegin();i!=coins.rend();++i){
		int secondcoin = M-*i;
		if(
			(secondcoin >= 0 && hascoin[secondcoin]&&secondcoin !=*i) ||
			(secondcoin == *i && hascoin[secondcoin]>1)
			){
			printf("%d %d\n",secondcoin,*i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}