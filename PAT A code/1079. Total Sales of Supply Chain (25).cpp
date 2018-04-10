#include <cstdio>
#include <vector>
#include <algorithm>
struct node{
	bool isretailer;
	int products;
	std::vector<int> child;
};
int n;
std::vector<node> network;
double p,r;
double price(int root){
	if(network[root].isretailer){
		return 1.0*network[root].products;
	}else{
		double sum = 0;
		for(int i = 0;i<network[root].child.size();++i){
			sum+=price(network[root].child[i]);
		}
		return r*sum;
	}
}
int main(){
	scanf("%d %lf %lf\n",&n,&p,&r);
	r = r/100.0+1.0;
	network.resize(n);
	for(int i = 0;i<n;++i){
		int ki;
		scanf("%d",&ki);
		if(ki){//suppliers			
			network[i].child.resize(ki);			
			network[i].isretailer = false;
			for(int j = 0;j<ki;++j){
				int id;
				scanf("%d",&id);
				network[i].child[j] = id;
			}
		}else{//retailer
			int pro;
			scanf("%d",&pro);
			network[i].products = pro;
			network[i].isretailer = true;
		}
	}
	printf("%.1lf",price(0)*p);
	return 0;
}