#include <cstdio>
#include <algorithm>
#include <vector>
int main()
{
	int N,n,m,tmp;
	scanf("%d",&N);
	std::vector<int> ori(N);
	for(m = 0;m*m <= N;++m){//i do not want to use sqrt() in <cmath>,so it is for m = ceil(sqrt(N))
		if (m*m == N){
			break;
		}
	}
	while(N%m != 0){
		++m;//row
	}
	n = N/m;//col
	for(int i = 0;i < N;++i)
	{
		scanf("%d",&ori[i]);
	}
	std::sort(ori.begin(), ori.end(),std::greater<int>());
	std::vector<std::vector<int> > matrix(m);
	for (int i = 0; i < m; ++i)
	{
		matrix[i].assign(n,0);
	}
	int num = 0,i=0,j=0,direction = 0;
	while(num != N){
		matrix[i][j] = ori[num++];
		switch(direction){
		case 0://right
			if(j == n-1 || matrix[i][j+1] >0){
				++i;
				direction++;
				direction%=4;
			}else{
				++j;
			}
			break;
		case 1://down
			if(i == m-1 || matrix[i+1][j] >0){
				--j;
				direction++;
				direction%=4;
			}else{
				++i;
			}
			break;
		case 2://left
			if(j == 0 || matrix[i][j-1] >0){
				--i;
				direction++;
				direction%=4;
			}else{
				--j;
			}
			break;
		case 3://up
			if(matrix[i-1][j] >0){
				++j;
				direction++;
				direction%=4;
			}else{
				--i;
			}
			break;
		}
	}
	for(int i = 0;i!=m;++i){
		for(int j = 0;j!=n;++j){
			printf("%d",matrix[i][j] );
			if (j!=matrix[i].size()-1)
			{
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}