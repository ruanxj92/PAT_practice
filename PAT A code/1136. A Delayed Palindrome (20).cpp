#include <iostream>
#include <string>
#include <algorithm>
void rev(std::string A, std::string &B ){
	B = A;
	std::reverse(B.begin(),B.end());
}
void stradd(std::string const &A,  std::string const &B ,std::string &C){
	C.clear();
	int carry = 0;
	auto i = A.rbegin(),j = B.rbegin();
	while(i!=A.rend()||j!=B.rend()||carry){
		int sum =carry;
		if(i!=A.rend()) sum+=*i++-'0';
		if(j!=B.rend()) sum+=*j++-'0';
		char head = sum%10+'0';
		C = head+C;
		carry = sum/10;		
	}
}
int main(){
	int count = 0;
	std::string A,B,C;
	std::cin >> A;
	while(count++<10){
		rev(A,B);
		if(A==B){
			break;
		}else{
			stradd(A,B,C);
			std::cout << A <<" + "<< B <<" = " << C << std::endl;
			A = C;
		}
	}
	if(count>=10){
		std::cout << "Not found in 10 iterations." << std::endl;
	}else{		
		std::cout << A <<" is a palindromic number."<<std::endl;
	}
}