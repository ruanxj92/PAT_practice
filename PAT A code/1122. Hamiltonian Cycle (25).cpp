#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
const int maxn = 201;
int N_vertex,M_edge;
std::vector<std::vector<bool> > G;
bool check(){
	bool res = true;
	int qlen;
	scanf("%d",&qlen);
	if(qlen != G.size())
		res = false;
	std::vector<int> vis(G.size(),false);
	int prev;
	scanf("%d",&prev);
	for (int i = 1; i < qlen; ++i){
		int next;
		scanf("%d",&next);
		if(!res) continue;
		if(!vis[next]){
			vis[next] = true;
		}else{
			res = false;
		}
		if(G[prev][next] == false) 
			res = false;
		prev = next;
	}
	return res;
}
int main(){
	scanf("%d %d",&N_vertex,&M_edge);
	G.resize(N_vertex+1);
	for(int i = 0;i<=N_vertex;++i){
		G[i].assign(N_vertex+1,false);
	}
	for (int i = 0; i < M_edge; ++i)
	{
		int va,vb;
		scanf("%d %d",&va,&vb);
		G[va][vb] = true;
		G[vb][va] = true;
	}
	int Q;
	scanf("%d",&Q);
	for (int i = 0; i < Q; ++i)
	{
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}