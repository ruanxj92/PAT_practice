#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
const int maxn = 100000;
struct Node{
	int addr,key,next;
	bool operator< (Node a){
	}
}chain[maxn];
int count[maxn] = {0};
int main(){
	int begin,n;
	scanf("%d %d",&begin,&n);
	for(int i = 0;i<n;++i){
		int addr,key,next;
		scanf("%d %d %d",&addr,&key,&next);
		chain[addr].addr=addr;
		chain[addr].key=key;
		chain[addr].next=next;
	}
	std::vector<Node> res,remov;
	int i,j;
	for(i = begin,j=0;i!=-1;i = chain[i].next,j++){
		if(count[std::abs(chain[i].key)]++){//find duplication
			remov.push_back(chain[i]);
		}else{
			res.push_back(chain[i]);
		}
	}
	for(auto i = res.begin();i!=res.end();++i){
		printf("%05d %d",i->addr,i->key);
		if(i!=res.end()-1)
			printf(" %05d\n",(i+1)->addr);
		else
			printf(" -1\n");
	}
	for(auto i = remov.begin();i!=remov.end();++i){
		printf("%05d %d",i->addr,i->key);
		if(i!=remov.end()-1)
			printf(" %05d\n",(i+1)->addr);
		else
			printf(" -1\n");
	}
	return 0;
}