#include <cstdio>
#include <string>
#include <vector>
using namespace std;
struct node {
	string team;
	string password;
	node(string _tm,string _pwd){
		team = _tm;
		password = _pwd;
	}
	node(){
	}
};
char tempnm[16],tempwd[16];
vector<node> seq;
bool confusing(char a[]){
	bool flag = false;
	for(int i = 0;a[i] != '\0';++i){
		switch(a[i]){
		case '1':
			a[i] = '@';
			flag = true;
			continue;
		case 'l':
			a[i] = 'L';
			flag = true;
			continue;
		case '0':
			a[i] = '%';
			flag = true;
			continue;
		case 'O':
			a[i] = 'o';
			flag = true;
			continue;
		}
	}
	return flag;
}
bool findcopy(string a){
	for(auto i = seq.begin();i!=seq.end();++i){
		if(a == i->password)
			return true;
	}
	return false;
}
int main(){
	int n,mod = 0;
	scanf("%d",&n);
	string tempstr;
	for(int i = 0 ;i<n;++i ){
		scanf("%s %s",tempnm,tempwd);
		if(confusing(tempwd) && !findcopy(string(tempwd)))
				seq.push_back(node(string(tempnm),string(tempwd)));
	}
	if(seq.empty()){
		if(n == 1){
			printf("There is 1 account and no account is modified");
		}else{
			printf("There are %d accounts and no account is modified",n);
		}
	}else{
		printf("%u\n",seq.size());
		for(auto i = seq.begin();i!=seq.end();++i){
			printf("%s %s\n",i->team.c_str(),i->password.c_str());
		}
	}
	return 0;
}