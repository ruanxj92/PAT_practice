#include <cstdio>
int hash[256] = {0};
int main(){
	char str1[81], str2[81];
	scanf("%s",str1);
	scanf("%s",str2);
	int i = -1,j=-1;
	while(str2[++i]){
		if(str2[i]>='a'&&str2[i]<='z'){
			hash[str2[i]+'A'-'a'] = 1;
		}else{
			hash[str2[i]] = 1;
		}
	}
	while(str1[++j]){
		if(str1[j]>='a'&&str1[j]<='z'){
			if(hash[str1[j]+'A'-'a'] == 0){
				printf("%c",str1[j]+'A'-'a');
				hash[str1[j]+'A'-'a'] = 1;
			}
		}else{
			if(hash[str1[j]] == 0){
				printf("%c",str1[j]);
				hash[str1[j]] = 1;
			}
		}
	}
	return 0;
}