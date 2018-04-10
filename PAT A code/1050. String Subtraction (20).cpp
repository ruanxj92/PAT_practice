/*https://www.patest.cn/contests/pat-a-practise/1050
*/
#include<cstdio>
#include<string>
#include<iostream>
int main(){
	std::string s1,s2;
	bool remove[256] = {false};
	std::getline(std::cin,s1);
	std::getline(std::cin,s2);
	for(std::string::iterator i = s2.begin();i!=s2.end();i++){
		remove[*i] = true;
	}
	for(std::string::iterator i = s1.begin();i!=s1.end();i++){
		if(!remove[*i])
			printf("%c",*i);
	}
	printf("\n");
	return 0;
}