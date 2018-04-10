#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> chnnum;
void initial(){
	chnnum.push_back("ling");
	chnnum.push_back("yi");
	chnnum.push_back("er");
	chnnum.push_back("san");
	chnnum.push_back("si");
	chnnum.push_back("wu");
	chnnum.push_back("liu");
	chnnum.push_back("qi");
	chnnum.push_back("ba");
	chnnum.push_back("jiu");
}
using namespace std;
string res(""),num;
bool final(string::iterator ){
	return false;
}
int main(){
	initial();
	cin >> num;
	if(num == "0"){
		cout << "ling";
		return 0;
	}
	if(num[0] == '-'){
		num.erase(num.begin());
		res+="Fu ";
	}
	bool iszero=false,printed = false;
	for(int i = 0;num.begin()+i!=num.end();++i){
		if((num.size()-i)%4 == 0){
			printed = false;
		}
		if(num[i]>'0'&&num[i]<='9'){
			if(iszero){
				res+=" ling";
				iszero = false;
			}
			if(i) 
				res+=" ";
			res += string(chnnum[num[i]-'0']);
			printed = true;
			switch((num.size()-i)%4){
			case 0:
				res+=" Qian";
				break;
			case 2:
				res+=" Shi";
				break;
			case 3:
				res+=" Bai";
				break;
			}
		}else if(num[i] == '0'){
			iszero = true;
		}
		if(printed){
			switch(num.size()-i){
			case 9:
				res+=" Yi";
				break;
			case 5:
				res+=" Wan";
				break;
			}
		}
	}
	cout << res;
//	getchar();getchar();
	return 0;
}