#include <cstdio>
#include <vector>
#include <algorithm>
struct node{
	double maxprice;
	int count;
	std::vector<int> child;
};
std::vector<node> network;
double p,r;
double price(int root){
	if(network[root].child.size()==0){
		network[root].maxprice = 1.0;
		network[root].count = 1;
		return 1.0;
	}
	double max = 0,tmp;
	for(int i = 0;i<network[root].child.size();++i){
		tmp = price(network[root].child[i]);
		if(tmp>max){
			max = tmp;
			network[root].count = network[network[root].child[i]].count ;
		}else if(tmp == max){
			network[root].count += network[network[root].child[i]].count;
		}
	}
	tmp = r*max;
	network[root].maxprice = tmp;
	return network[root].maxprice;
}
int main(){
	int n;
	scanf("%d %lf %lf\n",&n,&p,&r);
	r = r/100.0+1.0;
	int root;
	network.resize(n);
	for(int i = 0;i<n;++i){
		int ki;
		scanf("%d",&ki);
		if(ki==-1){//suppliers			
			root = i;
		}else{//retailer
			network[ki].child.push_back(i);
		}
	}
	price(root);
	printf("%.2lf %d",network[root].maxprice*p,network[root].count);
	return 0;
}