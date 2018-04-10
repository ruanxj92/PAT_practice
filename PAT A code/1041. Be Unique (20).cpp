/*4.2 hash
*/
#include<cstdio>
#include<vector>
const int MAXN = 100000;
int main(){
	int N,bet,hashtable[MAXN] = {0};
	std::vector<int> rec;
	scanf("%d",&N);
	for(int i = 0;i!=N;++i){
		scanf("%d",&bet);
		rec.push_back(bet);
		hashtable[bet]++;
	}
	int account = N;
	for(std::vector<int>::iterator k = rec.begin();k!=rec.end();++k){
		if(hashtable[*k]==1){//found the unique one
			printf("%d\n",*k);		
			return 0;
		}
	}
	printf("None\n");
	return 0;
}