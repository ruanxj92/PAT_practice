#include <cstdio>
#include <string>
#include <vector>
using namespace std;
char tmp[256];
std::vector<string> kuchiguse;
int main(){
	int n ;
	scanf("%d\n",&n);
	for(int i = 0;i<n;++i){
		gets(tmp);
		kuchiguse.push_back(string(tmp));
	}
	int minlng = 257,guselng = 0;
	for(auto i = kuchiguse.begin();i!=kuchiguse.end();++i){
		if(minlng > i->size()) 
			minlng = i->size();
	}
	bool uni = true;
	for(int i = 0;i!=minlng;++i){
		for(int j = 0;j != kuchiguse.size();++j){
			if(*(kuchiguse[0].rbegin()+i)!=*(kuchiguse[j].rbegin()+i)){
				uni = false;
				break;
			}
		}
		if(!uni) break;
		else guselng++;
	}
	if(guselng){
		printf("%s",string(kuchiguse[0].end()-guselng,kuchiguse[0].end()).c_str());
	}else{
		printf("nai");
	}
}