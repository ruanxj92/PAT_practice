#include <cstdio>
#include <stack>
char towords[10][8] = {
	{"zero"},
	{"one"},
	{"two"},
	{"three"},
	{"four"},
	{"five"},
	{"six"},
	{"seven"},
	{"eight"},
	{"nine"}
}; 
int main(){
	char a;
	int sum = 0;
	std::stack<int> st;
	while(scanf("%c",&a),(a<='9'&&a>='0')){
		sum+=a-'0';
	}
	if(sum == 0){
		printf("%s",towords[0]);
		return 0;
	}
	while(sum>0){
		st.push(sum%10);
		sum/=10;
	}
	while(!st.empty()){
		if(st.size()>1){
			printf("%s ",towords[st.top()]);
		}
		else
			printf("%s",towords[st.top()]);
		st.pop();
	}
	return 0;
}
/*
be aware of zero
*/