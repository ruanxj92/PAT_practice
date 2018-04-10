#include <cstdio>
#include <vector>
#include <map>
#include <string>
struct route{
	int id;
	int cost;
	route(int a,int b){
		id = a;
		cost = b;
	}
};
std::map<std::string, int> name2id;
std::vector<std::string> id2name;
std::vector<int> happiness,tmppath,path;
std::vector<std::vector<route> > costmap;
std::vector<std::vector<int> > pre;
std::vector<int> dis;
const int inf = 0x3fffffff;
int mincost = inf,maxhappy = 0,minpathlen = inf,numpath = 0;
void dijkstra(int start){
	std::vector<bool> vis(costmap.size(),false);
	dis.assign(costmap.size(),inf);
	dis[start] = 0;
	for(int i = 0;i<costmap.size();++i){
		int min = inf,u = -1;
		for (int j = 0; j < costmap.size(); ++j)
		{
			if(!vis[j] && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		vis[u] = true;
		for (auto j = costmap[u].begin(); j != costmap[u].end(); ++j)
		{
			int next = j->id;
			if (dis[next]> j->cost + dis[u] )
			{
				dis[next] = j->cost + dis[u];
				pre[next].clear();
				pre[next].push_back(u);
			}else if(dis[next] == j->cost + dis[u] ){
				pre[next].push_back(u);
			}
		}	
	}
	return;
}
void dfs(int v){
	if(v ==name2id["ROM"] ){//充分理解题意再开始编码，注意看懂对最后输出结果的要求
		tmppath.push_back(v);
		++numpath;
		int happyvalue=0;
		for(auto i = tmppath.begin()+1;i!=tmppath.end();++i){//一开始在这里吧路径全长又算了一遍，浪费时间,而且还不好算
			happyvalue+=happiness[*i];
		}
		if(happyvalue > maxhappy){			
			maxhappy = happyvalue;
			minpathlen = tmppath.size();
			path = tmppath;
		}else if(happyvalue == maxhappy && minpathlen > tmppath.size()){
			minpathlen = tmppath.size();
			path = tmppath;
		}
		tmppath.pop_back();
	}else{
		tmppath.push_back(v);
		for (int i = 0; i < pre[v].size(); ++i){
			dfs(pre[v][i]);
		}
		tmppath.pop_back();
	}
	return;
}
int main(){
	int citynum,routenum;
	scanf("%d %d",&citynum,&routenum);
	happiness.assign(citynum,0);
	id2name.resize(citynum);
	costmap.resize(citynum);
	pre.resize(citynum);
	char startcity[4];
	scanf("%s",startcity);
	for (int i = 0; i < citynum-1; ++i){
		char tmpname[4];
		int happyvalue;
		scanf("%s %d",tmpname,&happyvalue);
		name2id[tmpname] = i;
		id2name[i] = std::string(tmpname);
		happiness[i] = happyvalue;
	}
	name2id[startcity] = citynum-1;
	id2name[citynum-1] = std::string(startcity);		
	for (int i = 0; i < routenum; ++i)
	{
		char nm1[4],nm2[4];
		int cost,id1,id2;
		scanf("%s %s %d",nm1,nm2,&cost);
		id1 = name2id[nm1];
		id2 = name2id [nm2];
		costmap[id1].push_back(route(id2,cost));
		costmap[id2].push_back(route(id1,cost));
	}
	dijkstra(name2id["ROM"]);
	dfs(name2id[startcity]);
	printf("%d %d %d %d\n", numpath,dis[name2id[startcity]],maxhappy,maxhappy/(minpathlen-1));
	for(int i = 0;i<path.size();++i){
		if(i) printf("->");
		printf("%s", id2name[path[i]].c_str());
	}
	return 0;
}