#include <cstdio>
#include <vector>
#include <algorithm>
struct node{
	double price;
	int level;
	std::vector<int> child;
};
int n,lowcount,lowlevel;
std::vector<node> network;
double p,r,lowprice;
void dfs(int root){
	if(network[root].child.size()){
		for(int i = 0;i<network[root].child.size();++i){
			network[network[root].child[i]].price = network[root].price*r;
			network[network[root].child[i]].level = network[root].level+1;
			dfs(network[root].child[i]);
		}
	}else{
		if(network[root].level < lowlevel){
			lowprice = network[root].price;
			lowcount = 1;
			lowlevel = network[root].level;
		}else if(network[root].level == lowlevel){
			lowcount++;
		}
	}
}
int main(){
	lowcount = 0;
	lowprice = 1e12;
	scanf("%d %lf %lf\n",&n,&p,&r);
	lowlevel = n;
	r = r/100.0+1.0;
	network.resize(n);
	network[0].price = p;
	network[0].level = 0;
	for(int i = 0;i<n;++i){
		int ki;
		scanf("%d",&ki);
		if(ki){//suppliers			
			network[i].child.resize(ki);
			for(int j = 0;j<ki;++j){
				int id;
				scanf("%d",&id);
				network[i].child[j] = id;
			}
		}
	}
	dfs(0);
	printf("%.4lf %d",lowprice,lowcount);
	return 0;
}