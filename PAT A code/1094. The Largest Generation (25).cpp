#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
struct node{
	int level;
	std::vector<int> child;
	node(){
		level = 1;
	}
};
void bfs(std::vector<node> &tree,std::vector<int> &levelcount,int &mostlevel){
	std::queue<int> q;
	q.push(1);
	levelcount[1] = 1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		int toplevel = tree[top].level,childlevel = tree[top].level+1;
		for(int i = 0;i<tree[top].child.size();++i){
			int chilid = tree[top].child[i];
			tree[chilid].level = childlevel;
			levelcount[childlevel]++;
			if(levelcount[childlevel] >= levelcount[mostlevel])
				mostlevel = childlevel;
			q.push(chilid);
		}
	}
	return ;
}
int main(){
	int m,n,id,k,child,mostlevel = 1;
	scanf("%d %d",&n,&m);
	std::vector<node> tree;
	std::vector<int> levelcount(n+2,0);
	tree.resize(n+1);
	for(int i = 0;i<m;++i){
		scanf("%d %d",&id,&k);
		for(int j = 0;j<k;++j){
			scanf("%d",&child);
			tree[id].child.push_back(child);
		}
	}
	bfs(tree,levelcount,mostlevel);
	printf("%d %d\n",levelcount[mostlevel],mostlevel);
	return 0;
}