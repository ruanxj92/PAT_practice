#include <cstdio>
const int maxn = 4096;
const int maxn2 = maxn*2;
double a[maxn]={0.0},b[maxn2]={0.0};
int main(){
	int n1,n2,ex,maxaex=0,maxbex=0,minaex=maxn,minbex=maxn2;
	double co;
	scanf("%d",&n1);
	for(int i = 0;i<n1;++i){
		scanf("%d",&ex);
		if(ex>maxaex) maxaex = ex;
		if(ex<minaex) minaex = ex;
		scanf("%lf",a+ex);
	}
	scanf("%d",&n2);
	for(int i = 0;i<n2;++i){
		scanf("%d %lf",&ex,&co);
		if(co == 0.0) continue;
		for(int j = minaex;j<=maxaex;++j){
			if(a[j]*co!=0.0){
				b[ex+j] += a[j]*co;
				if(ex+j>maxbex) maxbex = ex+j;
				if(ex+j<minbex) minbex = ex+j;
			}
		}
	}
	int count = 0;
	for(int i = minbex;i<=maxbex ;++i){
		if(b[i]!=0.0) ++count;
	}
	printf("%d",count);
	for(int i = maxbex;i>=minbex ;--i){
		if(b[i]!=0.0){
			if(count--) printf(" ");
			printf("%d %.1lf",i,b[i]);
		}
	}
	return 0;
}
