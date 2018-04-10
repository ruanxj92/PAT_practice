#include <cstdio>
int main(){
	char tochar[3] = {'W','T','L'};
	int select=0;
	double odds[3],results = 1;
	for(int i = 0;i<3;++i){
		scanf("%lf%lf%lf",odds,odds+1,odds+2);
		for(int j = 0;j<3;++j){
			if(odds[select] < odds[j])
				select = j;
		}
		results*=odds[select];
		printf("%c ",tochar[select]);
	}
	printf("%.2lf",(results*0.65-1)*2);
	return 0;
}