#include<iostream>
#include<string>
int n;
std::string deal(std::string s,int &e){
	int k =0;
	while(s.length() >0 && s[0] == '0'){
		s.erase(s.begin());
	}
	if(s.length()>0&&s[0]=='.'){
		s.erase(s.begin());
		while(s.length()>0&&s[0]=='0'){
			s.erase(s.begin());
			--e;
		}
	}else{
		while(k<s.length()&&s[k]!='.'){
			++k;
			++e;
		}
		if(k<s.length())
			s.erase(s.begin()+k);
	}
	if(s.length()==0)
		e =0;
	int num=0;
	k=0;
	std::string res;
	while(num<n){
		if(k<s.length())
			res+=s[k++];
		else res+='0';
		num++;
	}
	return res;
}
int main(){
	std::string s1,s2,s3,s4;
	std::cin >> n >> s1 >> s2;
	int e1=0,e2=0;
	s3 = deal(s1,e1);
	s4 = deal(s2,e2);
	if(s3==s4&&e1==e2)
		std::cout <<"YES 0."<<s3<<"*10^"<<e1<<std::endl;
	else
		std::cout <<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<std::endl;
	return 0;
}
