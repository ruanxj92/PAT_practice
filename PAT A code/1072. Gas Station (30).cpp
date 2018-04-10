#include <cstdio>
#include <vector>
#include <algorithm>
struct node
{
	int id,len;
	node(int &_id,int &_len){
		id = _id;
		len = _len;
	}
};
int findid(char a[],int size){
	int i = 0,res = 0;
	int bia = 0;
	if(a[0] == 'G'){
		bia = size;
		++i;
	}
	while(a[i]){
		res = res*10+a[i++]-'0';//这里写错了好多次，本来是
	}
	return res+bia;
}
const int inf = 0x3fffffff;
	std::vector<int> distance;
	std::vector<bool> vis;
void dijkstra(const int start,const std::vector<std::vector<node> > &roadmap,int &house_num, 
	double &mindis,double &avgdis,int &respos,int &serve_range){
	distance.assign(roadmap.size(),inf);
	vis.assign(roadmap.size(),false);
	if(roadmap.size())distance[start] = 0;
	for(int i = 0;i<roadmap.size();++i){//shotest path;
		int min = inf,u=-1;
		for(int j = 0;j<roadmap.size();++j){
			if(!vis[j] && distance[j] < min){
				min = distance[j] ;
				u = j;
			}
		}
		if(u==-1) continue;
		vis[u]  = true;
		for(auto j =roadmap[u].begin();j!=roadmap[u].end();++j){
			if(!vis[j->id] && distance[u] +j->len< distance[j->id]){
				distance[j->id] = distance[u] + j->len;
			}
		}
	}
	double tempmin = inf,tempavg=0;
	bool allinrange = true;
	for(int i = 1;i<=house_num;++i){//update min && mean distance
		tempavg+=distance[i];
		tempmin = distance[i] < tempmin?distance[i] : tempmin;
		if(distance[i] > serve_range)
			allinrange = false;
	}
	tempavg/=1.0*house_num;
	if(allinrange ){
		if(tempmin > mindis || (tempmin == mindis &&  tempavg <= avgdis)){
			mindis = tempmin;
			avgdis = tempavg;
			respos = start;	
		}		
	}
	return ;
}
int testmain(){
	char k[6] ;
	while(scanf("%s",k)){
		printf("%d\n",findid(k,13));;
	}
	return 0;
}
int main(){
	int house_num,gas_num,road_num,serve_range,respos = -1;
	scanf("%d %d %d %d\n",&house_num,&gas_num,&road_num,&serve_range);
	std::vector<std::vector<node> > roadmap(house_num+gas_num+1);	
	for(int i = 0;i<road_num;++i){
		char tmp[16];
		int r1,r2,len;
		bool type1,type2;
		scanf("%s",tmp);
		r1 = findid(tmp,house_num);
		scanf("%s",tmp);
		r2 = findid(tmp,house_num);
		scanf("%d",&len);
		roadmap[r1].push_back(node(r2,len));
		roadmap[r2].push_back(node(r1,len));
	}
	double mindis(0) ,avgdis(inf);
	for(int i = house_num+gas_num;i>house_num;--i){
		dijkstra(i,roadmap,house_num,mindis,avgdis,respos,serve_range);
	}
	if(respos == -1){
		printf("No Solution\n");
	}else{
		printf("G%d\n", respos-house_num);
		printf("%.1lf %.1lf\n", mindis,avgdis);
	}
	return 0;
}