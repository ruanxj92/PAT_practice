#include <cstdio>
#include <string>
#include <vector>
#include <list>
int main(){
	std::vector<int> hash(256,-1);
	std::vector<bool> inlist(256,false);
	int n;
	scanf("%d",&n);
	char tmpsentences[1001];
	scanf("%s",tmpsentences);
	std::string sentence(tmpsentences);
	std::vector<int> duplicate(sentence.size(),1);
	std::list<char> sus;
	for(int i = 1;i<sentence.size();i++){//find possible char
		if(sentence[i] == sentence[i-1]){
			duplicate[i] = duplicate[i-1]+1; 
			if(duplicate[i]%n == 0){
				if(hash[sentence[i]] < duplicate[i]) hash[sentence[i]] = duplicate[i];
				if(!inlist[sentence[i]]){
					sus.push_back(sentence[i]);
					inlist[sentence[i]]=true;
				}
			}
			
		}
	}	
	for(int i = 0;i<sentence.size()-1;i++){//mark good char
		char cur = sentence[i];
		if(duplicate[i+1] == 1 && duplicate[i]% n != 0){
			hash[cur] = -1;
		}
	}
	if(duplicate[sentence.size()-1]%n!=0)
		hash[sentence[sentence.size()-1]] = -1;
	for(auto i = sus.begin();i!=sus.end();){
		if(hash[*i]  % n != 0)
			sus.erase(i++);
		else
			++i;
	}
	for(int i = sentence.size()-1;i!=-1;--i){
		if(hash[sentence[i]] %n == 0 && duplicate[i]%n != 1){
			sentence.erase(sentence.begin()+i);
		}
	}
	for(auto i = sus.begin();i!=sus.end();++i){
		printf("%c",*i);
	}
	printf("\n%s",sentence.c_str());
	return 0;
}