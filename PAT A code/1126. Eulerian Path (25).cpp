#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
bool bfs(std::vector<std::vector<int> > &G){//�Լ�д��bfs����һ�����Ե����ȥ,�������ڳ�ʼ���Ԫ�ء�
	std::vector<bool> vis(G.size(),false);
	int visited = 1;
	std::queue<int> Q;
	Q.push(1);//��ʼ���Ӧ������1��������G[1][0]����g[1][0]����ȱ��һЩֻ��1�����ĵ�
	vis[1] = true;
	visited++;
	while(!Q.empty()){
		int top = Q.front();
		Q.pop();
		for(int i = 0;i<G[top].size();++i){
			int now = G[top][i];
			if(!vis[now]){
				Q.push(now);
				vis[now] = true;
				visited++;
			}
		}
	}
	return  visited == G.size();
}
int main(){
	int vertex, edge;
	scanf("%d %d",&vertex, &edge);
	std::vector<std::vector<int> > G(vertex+1);
	for(int i = 0;i<edge;++i){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	int eve = 0;
	for (int i = 1; i < G.size(); ++i){
		if(i!=1) printf(" ");
		printf("%u", G[i].size());
		if(G[i].size()%2 == 0) eve++;
	}
	bool connected = bfs(G);
	//dfs(G,1);
	//bool connected  = (cnt == vertex);
	if(eve == vertex && connected){
		printf("\nEulerian\n");
	}else if(eve == vertex - 2 && connected){
		printf("\nSemi-Eulerian\n");
	}else {
		printf("\nNon-Eulerian\n" );
	}
	return 0;
}