#include <cstdio>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
int main()
{
	int M,N,S;
	scanf("%d %d %d",&M,&N,&S);
	char str[21];
	std::unordered_set<std::string> has;
	int target = S;
	bool flag = true;
	for(int i = 1;i<=M;++i){
		scanf("%s",str);
		auto k = has.find(str);
		if(k!=has.end()) target++;
		if(i == target && k == has.end()){//any duplication affect all the latter followers
				has.insert(str);
				printf("%s\n",str);
				target+=N;
				flag = false;
		}
	}
	if(flag)
		printf("Keep going...\n");	
	return 0;
}