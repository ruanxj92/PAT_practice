#include <cstdio>
const int maxn = 10001;
int root[maxn];
bool vis[maxn];
int findroot(int x){
	vis[x] = true;
	int rt = x;
	while(rt!=root[rt]){
		rt = root[rt];
	}
	while(rt != root[x]){
		int z = x;
		x = root[x];
		root[z] = rt;
	}
	return rt;
}
void merge(int a,int b){
	int ra = findroot(a);
	int rb = findroot(b);
	if(ra!=rb){
		root[ra] = rb;
	}
	return ;
}
int main(){
	for(int i = 0;i<maxn;++i){
		root[i] = i;
		vis[i] = false;
	}
	int N;
	scanf("%d",&N);
	for(int i = 0; i<N;++i){
		int k,rt,b;
		scanf("%d",&k);
		if(k) scanf("%d",&rt);
		rt = findroot(rt);
		for(int j = 1;j<k;++j){
			scanf("%d",&b);
			merge(rt,b);
		}
	}
	for(int i = 0;i<maxn;++i){
		if(vis[i]){
			findroot(i);
		}
	}
	int treenum = 0,birdnum = 0;
	for(int i = 0;i<maxn;++i){
		if(vis[i]){
			if(root[i] == i){
				treenum++;
			}
			birdnum++;
		}
	}
	printf("%d %d\n",treenum,birdnum);
	int Q;
	scanf("%d",&Q);
	for(int i = 0;i<Q;++i){
		int b1,b2;
		scanf("%d %d",&b1,&b2);
		if(root[b1] == root[b2]){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}