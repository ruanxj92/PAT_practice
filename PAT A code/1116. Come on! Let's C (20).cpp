#include <cstdio>
#include <cmath>
const int maxn = 10001;
int ranklist[maxn] = {0};
bool isprime(int data){
	int srqt = std::sqrt((double)data);
	if(data == 2) return true;
	for(int i = 2;i<=srqt;i++){
		if(data%i == 0)
			return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		int id;
		scanf("%d",&id);
		ranklist[id] = i+1;
	}
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		int check;
		scanf("%d",&check);
		printf("%04d: ", check);
		int rank = ranklist[check];
		if(rank == 0){
			printf("Are you kidding?\n");
		}else if(rank == -1){
			printf("Checked\n");
		}else {
			if(rank == 1){
				printf("Mystery Award\n");		
			}else if(isprime(rank)){
				printf("Minion\n");
			}else{
				printf("Chocolate\n");
			}
			ranklist[check] = -1;
		}
	}
	return 0;
}