#include <cstdio>
char week[7][4] = {
	{"MON"},
	{"TUE"},
	{"WED"},
	{"THU"},
	{"FRI"},
	{"SAT"},
	{"SUN"},
};
int main(){
	char str1[64],str2[64],str3[64],str4[64];
	int dd = 0;
	scanf("%s\n%s\n%s\n%s",str1,str2,str3,str4);
	for(int i = 0;str1[i]!='\0'&&str2[i]!='\0';++i){//
		if(str1[i] == str2[i]){
			if(dd == 0){
				if(str1[i] >='A' && str1[i] <= 'G'){
					printf("%s ",week[str1[i]-'A']);
					dd = 1;
				}
			}else{		
				if(str1[i] >='0' && str1[i] <= '9'){
					printf("%02d",str1[i]-'0');
					break;
				}else if(str1[i] >='A' && str1[i] <= 'N'){
					printf("%02d",str1[i]-'A'+10);
					break;
				}
			}
		}
	}
	for(int i = 0;str4[i]!='\0'&&str3[i]!='\0';++i){//
		if(str4[i] == str3[i]){
			if((str4[i] >='A' && str4[i] <= 'Z') 
			||(str4[i] >='a' && str4[i] <= 'z')){	
				printf(":%02d",i);
				break;
			}
		}	
	}		return 0;
}
//注意理解题意，输出格式，尤其是前补零和对齐等；