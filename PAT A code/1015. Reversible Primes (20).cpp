#include <cstdio>
int reverse(int N,int D){
	int temp = 0;
	while(N){
		temp = temp * D + N % D;
		N /= D;
	}
	return temp;
}
bool prime(int N){
	if(N<2) return false;
	for(long long  i = 2;i*i<=(long long)N;i++){
		if((long long)N%i == 0)
			return false;
	}
	return true;
}
bool judge(int N,int D){
	//printf("ori:%d reverse:%d D;\n",N,reverse(N,D));
	return prime(N)&&prime(reverse(N,D));
}
int main(){
	int N,radix;
	while(true){
		scanf("%d",&N);
		if(N<0) break;
		scanf("%d",&radix);
		if(judge(N,radix)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}