#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
struct stationNode{
	int id;
	int time;
	stationNode(int _id,int _time){
		id = _id;
		time = _time;
	}
};
std::vector<std::vector<stationNode> > roadmap;
std::vector<std::vector<int> >prev;
std::vector<int> bike,path,tempath,dis;
std::vector<bool> vis;
const int inf = 0x3fffffff;
int cmax,station_num,index_station,road_num,minNeed = inf,minRemain = inf;
void djikstra(int start){
	dis.assign(roadmap.size(),inf);//距离初始化最大
	vis.assign(roadmap.size(),false);//全部定点未访问
	prev.resize(roadmap.size());//前置顶点初始化
	dis[start] = 0;//起点距离胃0
	for(int i = 0;i<roadmap.size();++i){//遍历每一个顶点
		int mindis = inf,u;
		for(int j = 0;j!=roadmap.size();++j){//遍历未访问顶点
			if(!vis[j] && dis[j] < mindis){
				mindis = dis[j] ;
				u = j;
			}
		}
		vis[u] = true;
		for(auto j = roadmap[u].begin();j!=roadmap[u].end();++j){//遍历最短距离的顶点相连的边
			if(!vis[j->id]){
				if(dis[u]+j->time < dis[j->id]){
					dis[j->id] = dis[u]+j->time;
					prev[j->id].clear();
					prev[j->id].push_back(u);
				}else if (dis[j->id] == dis[u]+j->time){
					prev[j->id].push_back(u);
				}
			}
		}
	}
}
void dfs(int v){
	if(v==0){//递归边界
		tempath.push_back(v);
		int need = 0,remain = 0;
		for(int i = tempath.size() - 1;i>=0;--i){
			int id = tempath[i];
			if(bike[id]>0){
				remain+=bike[id];
			}else{
				if(remain > std::abs(bike[id])){
					remain -=std::abs(bike[id]);
				}else{
					need += std::abs(bike[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain = remain;
			path = tempath;
		}else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			path = tempath;
		}
		tempath.pop_back();
	}else{
		tempath.push_back(v);//一般递归项 
		for (int i = 0; i < prev[v].size(); ++i)
		{
			dfs(prev[v][i]);//遍历所有分叉上可能的路径
		}
		tempath.pop_back();
	}
	return;
}
int main(){
	scanf("%d %d %d %d",&cmax,&station_num,&index_station,&road_num);
	roadmap.resize(station_num+1);
	bike.assign(station_num+1,0);
	for(int i = 1;i<=station_num;++i){
		scanf("%d",&bike[i]);
		bike[i] -= cmax/2;
	}
	for(int i  = 0;i<road_num;++i){
		int si,sj,time;
		scanf("%d %d %d",&si,&sj,&time);
		roadmap[si].push_back(stationNode(sj,time));
		roadmap[sj].push_back(stationNode(si,time));
	}
	djikstra(0);
	dfs(index_station);
	printf("%d ",minNeed);
	for(int i = path.size()-1;i>=0;--i){
		printf("%d",path[i]);
		if(i>0) printf("->");
	}
	printf(" %d",minRemain);
	return 0;
}