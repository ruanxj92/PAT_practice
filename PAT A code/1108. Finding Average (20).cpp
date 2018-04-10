#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
double ans;
bool legal(const string& input){
	int dotcount = 0,dotpos = -1;
	ans = 0;
	bool neg = false;
	for (int i = 0; i < input.size(); ++i)
	{
		if(input[i] == '-'){
			neg = true;
			if(i != 0 )
				return false;
			else
				continue;
		}
		if(input[i] == '.'){
			dotpos = i;
			dotcount++;
			if(dotcount>1){
				return false;
			}else{
				continue;
			}
		}
		if(input[i]<='9'&&input[i]>='0'){
			if(dotcount == 1 && i-dotpos >2){//too many decimal places
				return false;
			}
			if(dotcount == 0){//integer
				ans = ans*10+input[i]-'0';
			}else{//decimal
				ans += (input[i]-'0') * pow(0.1,double(i-dotpos));
			}
			if(ans > 1000 || ans < -1000){//out of range
				return false;
			}
		}else{//not a number or . or -
			return false;
		}
	}
	if(neg) ans = -ans;
	return true;
}
int main(){
	int n,num=0;
	double sum = 0;
	scanf("%d",&n);
	char buffer[1024];
	for(int i = 0;i<n;++i){
		scanf("%s",buffer);
		string tmp(buffer);
		if(legal(tmp)){
			sum+=ans;
			num++;
		}else{
			printf("ERROR: %s is not a legal number\n",tmp.c_str());
		}
	}
	if(num == 0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(num == 1){
		printf("The average of 1 number is %.2lf\n",sum);
	}else {
		printf("The average of %d numbers is %.2lf\n",num,sum/num);
	}
	return 0;
}