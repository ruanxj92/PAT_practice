#include <cstdio>
#include <vector>
int main(){
	int N,b;
	std::vector<int> palindrome;
	scanf("%d %d",&N,&b);
	do{
		palindrome.push_back(N%b);
		N/=b;
	}while(N>=b);
	if(N) {
		palindrome.push_back(N);
	}
	bool flag = true;
	auto itl = palindrome.begin();
	auto itr = palindrome.end()-1;
	for(;itl < itr;++itl,--itr){
			if(*itl != *itr){ 
				flag = false;
				break;
			}
	}
	if(flag){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for(auto i = palindrome.rbegin();i!=palindrome.rend();++i){
		printf("%d",*i);
		if(i!=palindrome.rend()-1)
			printf(" ");
	}
	return 0;
}