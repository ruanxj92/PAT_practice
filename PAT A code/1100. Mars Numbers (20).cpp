#include <cstdio>
#include <cstring>
#include <map>
#include <string>
std::map<std::string,int> martoearth;
std::map<int,std::string> earthtomar;
char highearthtomar[13][12] = {
	{"tret"},
	{"tam"},
	{"hel"},
	{"maa"},
	{"huh"},
	{"tou"},
	{"kes"},
	{"hei"},
	{"elo"},
	{"syy"},
	{"lok"},
	{"mer"},
	{"jou"},
};
char lowearthtomar[13][12] = {
	{"tret"},
	{"jan"},
	{"feb"},
	{"mar"},
	{"apr"},
	{"may"},
	{"jun"},
	{"jly"},
	{"aug"},
	{"sep"},
	{"oct"},
	{"nov"},
	{"dec"},
};
void init(){
	for(int i = 0;i<13;++i){
		martoearth[lowearthtomar[i]] = i;
		earthtomar[i] = lowearthtomar[i];
		martoearth[highearthtomar[i]] = i*13;
		earthtomar[13*i] = highearthtomar[i];
	}
	for(int i = 1;i<13;++i){
		for(int j = 1;j<13;++j){
			std::string str(std::string(highearthtomar[i])+" "+std::string(lowearthtomar[j])); 
			martoearth[str] = i*13+j;
			earthtomar[ i*13+j] = str;
		}
	}
	return;
}
void tomar(char num[]){
	printf("%d\n",martoearth[num]);
	return;
}
void toearth(char a[]){
	int num;
	sscanf(a,"%d",&num);
	printf("%s\n",earthtomar[num].c_str());
	return;
}
int main(){
	init();
	int num;
	char tmp[12];
	scanf("%d\n",&num);
	for(int i = 0;i!=num;++i){
		gets(tmp);
		if(tmp[0]<='9'){
			toearth(tmp);
		}else{
			tomar(tmp);
		}
	}
}