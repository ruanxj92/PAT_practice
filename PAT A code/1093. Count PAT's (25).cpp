#include <iostream>
#include <vector>
#include <string>
using namespace std;
const long mod = 1000000007;
int main(){
	string patstr;
	cin >> patstr;
	long long p=0,pa=0,pat=0;
	for(auto i = patstr.begin();i!=patstr.end();++i){
		switch(*i){
		case 'P':
			++p;break;
		case 'A':
			pa+=p;break;
		case  'T':
			pat+=pa;
		}
	}
	cout << pat%mod;
	return 0;
}