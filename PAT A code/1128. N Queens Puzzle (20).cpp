#include <cstdio>
#include <vector>
bool judge(std::vector<int> &input){
	std::vector<bool> row(input.size(),false);
	std::vector<bool> leftdig(input.size()*2,false);
	std::vector<bool> rightdig(input.size()*2,false);
	for(int i = 1;i<input.size();++i){
		if(row[input[i]]) 
			return false;
		else 
			row[input[i]] = true;
		if(leftdig[i-input[i]+input.size()]) 
			return false;
		else 
			leftdig[i-input[i]+input.size()] = true;
		if(rightdig[input[i]+i]) 
			return false;
		else 
			rightdig[input[i]+i] = true;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int len;
		scanf("%d",&len);
		std::vector<int> queen(len+1);
		for(int i = 1;i<queen.size();++i){
			scanf("%d",&queen[i]);
		}
		if(judge(queen)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}