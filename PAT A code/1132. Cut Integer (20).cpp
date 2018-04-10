#include <cstdio>
void check( int z){
	int A=z,dig = 1,count = 0;
	while(A){
		A/=10;
		count++;
		if(count % 2) dig*=10;
	}
	int B = z%dig;
	A = z/dig;
	A*=B;
	if(A && z%A==0){
			printf("Yes\n");
	}else{
			printf("No\n");
	}
	
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int z;
		scanf("%u",&z);
		check(z);
	}
	return 0;
}
