#include <cstdio>
#include <algorithm>
#include <vector>
struct node {
	int add,data,next,order;
}list[100000];
std::vector<node> v;
void traversal(int addr){
	int order = 0;
	while(addr!=-1){
		list[addr].order = order++;
		v.push_back(list[addr]);
		addr = list[addr].next;
	}
	return;
}
int n,head,K;
bool cmp(node a,node b){
	bool nega = (a.data<0),negb = (b.data<0);
	if(nega!=negb) return nega > negb;
	bool lesa = (a.data<=K),lesb = (b.data<=K);
	if(lesa!=lesb) return lesa > lesb;
	return a.order < b.order;
}
int main(){
	scanf("%d %d %d",&head,&n,&K);
	for(int i = 0;i<n;++i){
		int ad;
		scanf("%d",&ad);
		list[ad].add = ad;
		scanf("%d %d",&list[ad].data,&list[ad].next);
	}
	traversal(head);
	std::sort(v.begin(),v.end(),cmp);
	for(int i = 0;i<v.size();++i){
		if(i == v.size()-1){
			printf("%05d %d -1\n",v[i].add,v[i].data);
		}else{
			printf("%05d %d %05d\n",v[i].add,v[i].data,v[i+1].add);
		}
	}
	return 0;
}