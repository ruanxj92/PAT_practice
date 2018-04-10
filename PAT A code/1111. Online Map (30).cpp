#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
struct node{
	int id,length,time;
	bool operator<(node next){
		return id < next.id;
	}
	bool operator<(int next){
		return id < next;
	}
}tmp;
bool cmplength(node a,node b){
	if(a.length!=b.length)
		return a.length < b.length;
	else
		return a.time < b.time;
}
bool cmptime(node a,node b){
	return a.time < b.time;
}
const int inf = 1<<30;
std::vector<std::vector<int> > prev;
std::vector<int> tmpath,pathD,pathT;
int total1T = inf,total1D = inf,total2T = inf,total2D = inf;
void dikstraD(const std::vector<std::vector<node> > &roadmap,const int source){
	prev.clear();
	prev.resize(roadmap.size());
	tmpath.clear();
	pathD.clear();
	std::vector<bool> vis(roadmap.size(),false);
	std::vector<int> dis(roadmap.size(),inf);
	dis[source] = 0;
	for(int i = 0;i<roadmap.size();++i){
		int mindis = inf,u = -1;
		for(int j = 0;j<roadmap.size();++j){
			if(!vis[j] && dis[j]<mindis){
				u = j;
				mindis = dis[j];
			}
		}
		vis[u] = true;
		for(int j = 0;j<roadmap[u].size();++j){
			int cur = roadmap[u][j].id;
			if(!vis[cur]){
				if(dis[u] + roadmap[u][j].length < dis[cur]){
					dis[cur] = dis[u] + roadmap[u][j].length;
					prev[cur].clear();
					prev[cur].push_back(u);
				}else if(dis[u] + roadmap[u][j].length == dis[cur]){
					prev[cur].push_back(u);
				}
			}
		}
	}
	return ;
}
void dikstraT(const std::vector<std::vector<node> > &roadmap,const int source){
	prev.clear();
	prev.resize(roadmap.size());
	tmpath.clear();
	pathT.clear();
	std::vector<bool> vis(roadmap.size(),false);
	std::vector<int> dis(roadmap.size(),inf);
	dis[source] = 0;
	for(int i = 0;i<roadmap.size();++i){
		int mindis = inf,u = -1;
		for(int j = 0;j<roadmap.size();++j){
			if(!vis[j] && dis[j]<mindis){
				u = j;
				mindis = dis[j];
			}
		}
		vis[u] = true;
		for(int j = 0;j<roadmap[u].size();++j){
			int cur = roadmap[u][j].id;
			if(!vis[cur]){
				if(dis[u] + roadmap[u][j].time < dis[cur]){
					dis[cur] = dis[u] + roadmap[u][j].time;
					prev[cur].clear();
					prev[cur].push_back(u);
				}else if(dis[u] + roadmap[u][j].time == dis[cur]){
					prev[cur].push_back(u);
				}
			}
		}
	}
	return ;
}
void dfsD(std::vector<std::vector<node> > &roadmap,int now){
	if(prev[now].size() == 0){
		tmpath.push_back(now);
		int tmpT = 0,tmpD=0;
		for(int i = tmpath.size()-1;i>0;--i){
			int from = tmpath[i];
			auto ptr = std::lower_bound(roadmap[from].begin(), roadmap[from].end(),tmpath[i-1]);
			tmpT+=ptr->time;
			tmpD+=ptr->length;
		}
		if(tmpD < total1D){
			total1D = tmpD;
			total1T = tmpT;
			pathD = tmpath;
		}else if(tmpD == total1D && tmpT<total1T){
			total1T = tmpT;
			pathD = tmpath;
		}
		tmpath.pop_back();
	}else{
		tmpath.push_back(now);
		for(int i = 0;i<prev[now].size();++i){
			dfsD(roadmap,prev[now][i]);
		}
		tmpath.pop_back();
	}
}
void dfsT(std::vector<std::vector<node> > &roadmap,int now){
	if(prev[now].size() == 0){
		tmpath.push_back(now);
		int tmpT = 0,tmpD=0;
		for(int i = tmpath.size()-1;i>0;--i){
			int from = tmpath[i];
			auto ptr = std::lower_bound(roadmap[from].begin(), roadmap[from].end(),tmpath[i-1]);
			tmpT+=ptr->time;
			tmpD+=ptr->length;
		}
		if(tmpT < total2T){
			total2D = tmpD;
			total2T = tmpT;
			pathT = tmpath;
		}else if( tmpT==total2T && tmpath.size() < pathT.size()){
			total2D = tmpD;
			pathT = tmpath;
		}
		tmpath.pop_back();
	}else{
		tmpath.push_back(now);
		for(int i = 0;i<prev[now].size();++i){
			dfsT(roadmap,prev[now][i]);
		}
		tmpath.pop_back();
	}
}
int main(){
	int N_intersections,M_streets;
	scanf("%d %d",&N_intersections,&M_streets);
	std::vector<std::vector<node> > roadmap(N_intersections);
	for (int i = 0; i < M_streets; ++i)
	{
		int vertex1,vertex2,one_way;
		scanf("%d %d %d %d %d",&vertex1,&vertex2,&one_way,&tmp.length,&tmp.time);
		tmp.id = vertex2;
		roadmap[vertex1].push_back(tmp);
		if(one_way == 0){
			tmp.id = vertex1;
			roadmap[vertex2].push_back(tmp);
		}
	}
	for(int i = 0;i<roadmap.size();++i){
		if(roadmap[i].size()>1) std::sort(roadmap[i].begin(), roadmap[i].end());
	}
	int source,destination;
	scanf("%d %d",&source,&destination);
	dikstraD(roadmap,source);	
	dfsD(roadmap,destination);	
	dikstraT(roadmap,source);	
	dfsT(roadmap,destination);
	printf("Distance = %d",total1D);
	if(pathD !=pathT){
		printf(": ");
		for(int i = 0;i<pathD.size();++i){
			if(i) printf(" -> ");
			printf("%d", pathD[pathD.size()-1-i]);
		}
		printf("\n");
	}else{
		printf("; ");
	}
	printf("Time = %d",total2T);
	printf(": ");
	for(int i = 0;i<pathT.size();++i){
		if(i) printf(" -> ");
		printf("%d", pathT[pathT.size()-1-i]);
	}
	printf("\n");
	return 0;
}