#include <iostream>
#include <string>
std::string reverse(std::string input){
	std::string output;
	while(input.size()>0){
		output += *input.rbegin();
		input.erase(input.end()-1);
	}
	return output;
}
bool Palindromic(std::string n){
	return n == reverse(n);
}
std::string add(std::string a1,std::string b1){
	std::string output;
	std::string a=a1,b=b1;
	int tmp=0;
	while(a.size()||b.size()||tmp){
		if(a.size()){
			tmp += *a.rbegin()-'0';
			a.erase(a.end()-1);
		}
		if(b.size()){
			tmp += *b.rbegin()-'0';
			b.erase(b.end()-1);
		}
		output = char(tmp%10+'0')+output;
		tmp/=10;
	}
	return output;
}
int main(){
	unsigned long long n,K,count = 0;
	std::cin >> n >> K;
	std::string N = std::to_string(n);
	for(count = 0;count<K;++count ){
		if(Palindromic(N)) 
			break;
		else 
			N = add(N,reverse(N));
	}
	std::cout << N <<std::endl;
	std::cout << count;
	return 0;
}