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
		dp[i][i] = 1;//�Լ������ֶԳ�
		if(i < dp.size() -1){
			if(str[i] == str[i+1]){//����һ���ֶԳ�
				dp[i][i+1] = 1;
				ans = 2;
			}
		}
	}
	for(int L = 3;L<=str.size();++L){//���ջ��Ĵ�����
		for(int i = 0;i + L - 1 < str.size();++i){//�����ִ���ͷ
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