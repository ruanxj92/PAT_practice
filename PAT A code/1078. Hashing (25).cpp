#include <cstdio>
#include <algorithm>
const int maxn = 100001;
bool hash[maxn] = {0};
bool prime(int a){
	if(a<2) return false;
	for(int i = 2;i*i<=a;i++){
		if(a%i == 0)
			return false;
	}
	return true;
}
int main(){
	int msize,N;
	scanf("%d %d",&msize,&N);
	int Tsize = msize;	
	while(!prime(Tsize))		Tsize++;
	int tmp,pos,step;
	for(int i = 0;i<N;++i){
		scanf("%d",&tmp);
		for(step =0;step<Tsize;++step){
			pos = (tmp+step*step)%Tsize;
			if(!hash[pos]){
				hash[pos] = true;
				break;
			}
		}
		if(i) printf(" ");
		if(step <Tsize)
			printf("%d",pos );
		else
			printf("-");
	}
	return 0;
}