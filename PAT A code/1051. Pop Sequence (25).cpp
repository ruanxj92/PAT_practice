#include <stack>
#include <cstdio>
#include <vector>
int main(){
	int M,N,K;
	scanf("%d %d %d\n",&M,&N,&K);
	std::stack<int> stk;
	std::vector<int> seq(N,0);
	for(int i = 0;i<K;++i){
		while(!stk.empty()) stk.pop();
		int maxsize = 0,current = 0;
		for(int j = 0;j<N;++j){
			scanf("%d",&seq[j]);
		}
		for(int j = 0;j<N;++j){
			stk.push(j+1);
			if(stk.size()>maxsize) 
				maxsize = stk.size();
			while(!stk.empty() && stk.top() == seq[current]){
				stk.pop();
				current++;
			}
		}
		if(maxsize>M || !stk.empty()) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}