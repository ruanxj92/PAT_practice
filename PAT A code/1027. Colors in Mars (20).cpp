#include <cstdio>
char mars[16],color[8];
int num [3];
void initial(){
	for(int i = 0;i<10;++i){
		mars[i] = '0'+i;
	}
	for(int i = 10;i<16;++i){
		mars[i] = 'A'+i-10;
	}
}
int main(){
	initial();
	scanf("%d %d %d",num,num+1,num+2);
	color[0] = '#';
	color[7] = '\0';
	for(int i = 0;i<3;++i){
		color[i+i+1] = mars[num[i]/13];
		color[i+i+2] = mars[num[i]%13];
	}
	printf("%s",color);
	return 0;
}