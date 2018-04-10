#include <iostream>
#include <string>
int main(){
	using namespace std;
	string str,res,exp;
	cin >> str;
	string::iterator left = str.begin(),mid,right,dot;
	if(*left++=='-'){
		cout << '-';
	}
	while(*left!='E'){
		if(*left != '.'){
			res+=*left;
		}else{
			dot = left;
		}
		++left;
	}
	mid = left;
	exp = str.substr((mid+1-str.begin()),(str.end()-mid));
	int numexp = atoi(exp.c_str());
	if(numexp<0){
		string zeros = "0.";
		while(++numexp<0){
			zeros +='0';
		}
		res = zeros+res;
	}else{
		if(numexp<res.size()-1){
			res.insert(numexp+1,".");
		}else{
			for(int i = 0;i<res.size()-numexp-1;++i){
				res +='0';
			}
		}
	}
	cout << res;
	return 0;
}