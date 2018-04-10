#include <cstdio>
#include <vector>
#include <queue>
struct node{
	int id,level;
	std::vector<int> child;
	node(){
		id = -1;
		level = 0;
		child.clear();
	}
};
int main(){// 有问题，两个点不过
	int N,M,maxlevel=0;
	scanf("%d %d",&N,&M);
	std::vector<node> tree;
	tree.resize(N);
	for(int i  =0;i<M;++i){
		int _id,k;
		scanf("%d %d",&_id,&k);
		--_id;
		tree[_id].id = _id;
		tree[_id].child.resize(k);
		for(int j = 0;j<k;++j){
			int tmp;
			scanf("%d",&tmp);
			tree[_id].child[j] = --tmp;
			tree[tmp].level = tree[_id].level+1;
			if(tree[tmp].level > maxlevel)
				maxlevel = tree[tmp].level;
		}
	}
	
	std::vector<int> leaves(maxlevel+1,0);
	int root;
	std::queue<int> q;

	q.push(0);
	while(!q.empty()){
		root = q.front();
		q.pop();
		if(tree[root].child.size()>0)
			for(int i = 0;i<tree[root].child.size();++i){
				q.push(tree[root].child[i]);
			}
		else{
			leaves[tree[root].level]++;
		}
	}
	auto i = leaves.begin();
	do{
		if(i!=leaves.begin()){
			printf(" %d",*i);
		}else{
			printf("%d",*i);
		}
		++i;
	}while(i!=leaves.end());
	return 0;
}