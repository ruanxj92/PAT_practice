#include <cstdio>
#include <vector>
#include <queue>
int citynum,waynum,checknum;
std::vector<std::vector<int> > citymap;
std::vector<bool> vis;
void dfs(int &v){
	if(vis[v]) return;
	vis[v] = true;
	for(int i = 0;i<citymap[v].size();++i){
		int next = citymap[v][i];
		if(!vis[next]){
			dfs(next);
		}
	}
	return;
}
void bfs(int &v){
	std::queue<int> q;
	q.push(v);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(vis[top]) continue;
		vis[top]=true;
		for(int i = 0;i<citymap[top].size();++i){
			if(!vis[citymap[top][i]]){
				q.push(citymap[top][i]);
			}
		}
	}
}
int main(){
	int city1,city2;
	scanf("%d%d%d",&citynum,&waynum,&checknum);
	citymap.resize(citynum+1);
	vis.resize(citynum+1);
	for(int i = 0;i<waynum;++i){
		scanf("%d%d",&city1,&city2);
		citymap[city1].push_back(city2);
		citymap[city2].push_back(city1);
	}
	int city;
	int block;
	for(int i = 0;i<checknum;++i){
		scanf("%d",&city);
		std::fill(vis.begin(),vis.end(),false);
		vis[city] = true;
		block = 0;
		for(int j = 0;j<citymap[city].size();++j){
			int next = citymap[city][j];
			if(!vis[next]){
				dfs(next);
				block++;
			}
		}
		printf("%d\n",--block);
	}
}//自己写dfs的代码总在2号测试点出错，不明原因，网上找的一样思路的代码就能通过
//dfs is much faster than BFS.