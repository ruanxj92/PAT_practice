#include <cstdio>
#include <cstring>
#include <algorithm>
int main(){
	char ori[21]={0},dou[21]={0};
	int lenori,lendou,carry=0,tmp,i;
	int hash[10] = {0};
	bool permutation = true;
	scanf("%s",ori);
	for(lenori = 0;ori[lenori];++lenori){
		hash[ori[lenori]-'0']++;
	}
	lendou = lenori;
	std::reverse(ori,ori+lenori);
	for(i =0;i<lenori;++i){
		tmp = (ori[i]-'0')*2+carry;
		dou[i] = tmp%10+'0';
		carry = tmp/10;
		if(--hash[dou[i]-'0']<0)
			permutation = false;

	}
	if(carry){
		permutation = false;
		dou[i++] = '0'+carry;
		dou[i] = 0;
	}
	if(permutation)
		printf("Yes");
	else
		printf("No");
	std::reverse(dou,dou+i);
	printf("\n%s",dou);
	return 0;
}