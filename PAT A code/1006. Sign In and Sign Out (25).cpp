#include <cstdio>
#include <cstring>
int main(){
	char ID_number[16],ID_number_in[16],ID_number_out[16];
	int time,hh,mm,ss,n,timein = 235959,timeout=000000;
	scanf("%d",&n);
	for(int i =0;i<n;++i){
		scanf("%s %d:%d:%d",ID_number,&hh,&mm,&ss);
		time = hh*10000+mm*100+ss;
		if(time < timein){
			timein = time;
			strcpy(ID_number_in,ID_number);
		}
		scanf("%d:%d:%d",&hh,&mm,&ss);
		time = hh*10000+mm*100+ss;
		if(time > timeout){
			timeout = time;
			strcpy(ID_number_out,ID_number);
		}
	}
	printf("%s %s",ID_number_in,ID_number_out);
	return 0;
}