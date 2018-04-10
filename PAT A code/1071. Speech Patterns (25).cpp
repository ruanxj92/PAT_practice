#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>
bool alphanumerical(char a){
	if(a>='0'&&a<='9') return true;
	if(a>='a'&&a<='z') return true;
	if(a>='A'&&a<='Z') return true;
	return false;
}
int main(){
	std::unordered_map<std::string,int> count;
	char tmp[64];
	std::string strin;
	std::string str;
	std::getline(std::cin,strin);
	int head = 0,tail = 0;
	while(head<strin.size()){
		while(head<strin.size()&&!alphanumerical(strin[head])) ++head;
		tail = 0;
		while(head+tail<strin.size()&&alphanumerical(strin[head+tail])) ++tail;	
		str = strin.substr(head,tail);
		head+=tail;
		std::transform(str.begin(),str.end(),str.begin(),::tolower);
		if(count.find(str)== count.end()&& str!=""){// not find
			count[str] = 1;
		}else{
			count[str]++;
		}
	}
	auto ans = count.begin();
	int max = 0;
	for(auto i = count.begin();i!=count.end();++i){
		if(i->second > max){
			max=i->second;
			ans = i;
		}
	}
	std::cout << ans->first << " " << ans->second << std::endl;
	return 0;
}