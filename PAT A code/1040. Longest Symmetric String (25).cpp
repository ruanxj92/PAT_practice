#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
int main(){
	int ans = 1;
	std::string str;
	std::getline(std::cin,str);
	std::vector<std::vector<int> > dp(str.size());
	for(int i = 0;i<dp.size();++i){
		dp[i].assign(str.size(),0);
	}
	for(int i = 0;i<dp.size();++i){
		dp[i][i] = 1;//自己单个字对称
		if(i < dp.size() -1){
			if(str[i] == str[i+1]){//查下一个字对称
				dp[i][i+1] = 1;
				ans = 2;
			}
		}
	}
	for(int L = 3;L<=str.size();++L){//按照回文串长度
		for(int i = 0;i + L - 1 < str.size();++i){//按照字串开头
			int j = i + L - 1;
			if(str[i] == str[j] && dp[i+1][j-1] == 1){
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	std::cout << ans;
	return 0;
}