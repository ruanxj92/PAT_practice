#include <cstdio>
int main(){
	const int N = 54;
	char color[][N] = {
		"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
		"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
		"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
		"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
		"J1","J2"
	};
	int K;
	int sequence[N],after[N];
	for(int i = 0;i<N;++i){
		sequence[i]= i;
	}
	scanf("%d",&K);
	int shuffle[N],tmp;
	for(int i = 0;i<N;++i){
		scanf("%d",&tmp);
		shuffle[i]= tmp;
	}
	while(K--){
		for(int i = 0;i<N;++i){
			after[shuffle[i]-1] = sequence[i];
		}
		for(int i = 0;i<N;++i){
			sequence[i] = after[i];
		}

	}
	for(int i = 0;i<N;++i){
		printf("%s",color[sequence[i]]);
		if(i<53)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}