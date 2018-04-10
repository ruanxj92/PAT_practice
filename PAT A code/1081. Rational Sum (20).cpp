#include <cstdio>
typedef long long LL;
struct fraction{
	LL numerator;
	LL denominator;
	fraction(){
		numerator = 0;
		denominator = 1;
	}
}tmp,sum,tmp2;
LL gcd(LL a,LL b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
fraction add(fraction a,fraction b){
	LL top,bottom,gcdnum;
	top = a.numerator*b.denominator + b.numerator*a.denominator;
	bottom = a.denominator * b.denominator;
	gcdnum = gcd((top>0?top:-top),bottom);
	if(gcdnum!=1){
		top/=gcdnum;
		bottom/=gcdnum;
	}
	tmp2.numerator = top;
	tmp2.denominator = bottom;
	return tmp2;
}
void show(fraction ans){
	bool neg = false;
	if(ans.numerator < 0){
		neg = true;
		printf("-");
		ans.numerator = -ans.numerator;
	}
	if(ans.numerator == 0){
		printf("0");
		return;
	}
	if(ans.numerator>=ans.denominator){
		printf("%lld",ans.numerator/ans.denominator);
		if(ans.numerator % ans.denominator == 0) return;
		printf(" ");
		ans.numerator %= ans.denominator;
	}
	printf("%lld/%lld", ans.numerator,ans.denominator);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%lld/%lld",&tmp.numerator,&tmp.denominator);
		sum = add(sum,tmp);
	}
	show(sum);
	return 0;
}