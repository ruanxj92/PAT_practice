#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	int n1,n2,N;
	string::iterator lit,rit;
	cin >> str;
	lit = str.begin();
	rit = str.end()-1;
	N = int(str.size());
	n1 =(N+2)/3;
	n2 = N+2-n1-n1;
	string blank(n2-2,' ');
	for(int i = 0;i<n1-1;++i){
		cout << *lit++ << blank << *rit-- << endl;
	}
	for(int i = 0;i<n2;++i){
		cout << *lit++ ;
	}
	return 0;
}