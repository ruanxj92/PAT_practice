 #include <cstdio>
#include <vector>
#include <algorithm>
int main(){
	const int maxv = 128;
	int coin_num,price;
	scanf("%d %d",&coin_num,&price);
	std::vector<int> coins(coin_num+1,0),dp(maxv,0),flag(coin_num+1,0);
	std::vector<std::vector<bool> > choice(coin_num+1);
	choice[0].assign(maxv,false);
	for(int i = 1;i<=coin_num;++i){
		scanf("%d",&coins[i]);
		choice[i].assign(maxv ,false);
	}
	sort(coins.begin()+1, coins.end(),std::greater<int>());
	for (int i = 1; i < coins.size(); ++i){
		for (int v = price; v >= coins[i]; --v){
			if(dp[v] <= dp[v - coins[i]]+coins[i]){
				dp[v] = dp[v - coins[i]]+coins[i];
				choice[i][v] = true;
			}
		}
	}
	if (dp[price] != price){
		printf("No Solution\n");
	}else{
		int k = coin_num,num = 0,v = price;
		while(k>=0){
			if(choice[k][v]){
				flag[k] = true;
				v-=coins[k];
				num++;
			}
			else
				flag[k+1-1] = false;
			--k;
		}
		for (int i = coin_num; i >0; --i){
			if(flag[i]){
				printf("%d",coins[i] );
				num--;
				if(num)printf(" ");
			}
		}
	}
	return 0;
}