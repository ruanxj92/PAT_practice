#include <cstdio>
#include <cmath>
typedef long long LL;
struct frac{
	LL top,bottom;
	frac(LL t,LL b){
		top = t;
		bottom = b;
	}
	frac(){
		top = 0;
		bottom = -1;
	}
};
LL gcd(LL a,LL b){
	LL temp;
	while(b>0){
		temp = a %b;
		a = b;
		b = temp;
	}
	return a;
}
frac add(frac a,frac b);
frac minus(frac a,frac b);
frac multi(frac a,frac b);
frac div(frac a,frac b);
frac reduce(frac a);
void show(frac a);
frac add(frac a,frac b){
	return reduce(frac(a.top * b.bottom + a.bottom * b.top,a.bottom * b.bottom));
}
frac minus(frac a,frac b){
	b.top = -b.top;
	return add(a,b);
}
frac multi(frac a,frac b){
	return reduce(frac(a.top*b.top,a.bottom*b.bottom));
}
frac div(frac a,frac b){
	return reduce(frac(a.top*b.bottom,a.bottom*b.top));
}
frac reduce(frac a){
	bool neg = false;
	if(a.bottom == 0) return frac(1,0);
	if(a.top == 0) return frac(0,1);
	if((a.bottom<0 && a.top>0)||(a.bottom>0 && a.top<0)){
		neg = true;
	}
	if(a.top < 0) a.top = -a.top;
	if(a.bottom < 0) a.bottom = -a.bottom;
	LL gcdnum = gcd(a.top,a.bottom);
	a.top/=gcdnum;
	a.bottom /= gcdnum;
	if(neg){
		a.top = -a.top;
	}
	return a;
}
void show(frac a){
	bool neg = false;
	if(a.bottom == 0){
		printf("Inf" );
		return;
	}
	if(a.top <0){
		neg = true;
		if(neg) printf("(");
		printf("-");
		a.top = -a.top;
	}else if(a.top == 0){
		printf("0");
		return;
	}
	if(a.top%a.bottom == 0){
		printf("%lld",a.top/a.bottom);
		if(neg) printf(")");
		return;
	}else{
		if(a.top>a.bottom){
			printf("%lld ",a.top/a.bottom );
			a.top%=a.bottom;
		}
		printf("%lld/%lld",a.top,a.bottom);
	}	
	if(neg) printf(")");
	return;
}

int main(){
	frac a,b;
	scanf("%lld/%lld %lld/%lld",&a.top,&a.bottom,&b.top,&b.bottom);
	a = reduce(a);
	b = reduce(b);
	show(a); printf(" + ");show(b); printf(" = "); show(add(a,b)); printf("\n");
	show(a); printf(" - ");show(b); printf(" = "); show(minus(a,b));printf("\n");
	show(a); printf(" * ");show(b); printf(" = "); show(multi(a,b));printf("\n");
	show(a); printf(" / ");show(b); printf(" = "); show(div(a,b));printf("\n");
	return 0;
}