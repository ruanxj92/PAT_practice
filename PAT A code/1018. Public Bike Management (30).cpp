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
	dis.assign(roadmap.size(),inf);//�����ʼ�����
	vis.assign(roadmap.size(),false);//ȫ������δ����
	prev.resize(roadmap.size());//ǰ�ö����ʼ��
	dis[start] = 0;//������θ0
	for(int i = 0;i<roadmap.size();++i){//����ÿһ������
		int mindis = inf,u;
		for(int j = 0;j!=roadmap.size();++j){//����δ���ʶ���
			if(!vis[j] && dis[j] < mindis){
				mindis = dis[j] ;
				u = j;
			}
		}
		vis[u] = true;
		for(auto j = roadmap[u].begin();j!=roadmap[u].end();++j){//������̾���Ķ��������ı�
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
	if(v==0){//�ݹ�߽�
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
		tempath.push_back(v);//һ��ݹ��� 
		for (int i = 0; i < prev[v].size(); ++i)
		{
			dfs(prev[v][i]);//�������зֲ��Ͽ��ܵ�·��
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