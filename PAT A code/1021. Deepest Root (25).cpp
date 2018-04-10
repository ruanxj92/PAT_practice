//һ��ʼûʲô�õ��뷨����������floyd����룬Ȼ���ϲ��鼯����û��ͬһ����ͨ��ͼ�ڡ�Ȼ�����Ͻⷨ��ö�
//������������һ���㿪ʼ������ڵ�ļ���A��Ȼ���A�����ҵ�����㼯��B���������A+B�Ĳ���������ҵ��Ľڵ㲻����ͨ,���������ͨ����ͼ������
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
std::vector<std::vector<int> > tree;
std::set<int> deepnode[2];
std::vector<int> res;
std::vector<int> distance;
std::vector<bool> vis;
std::vector<int> father;
int maxdepth,run;
int bfs(int top){
	std::fill(distance.begin(),distance.end(),0);
	std::fill(vis.begin(),vis.end(),false);
	std::queue<int> q;
	int depos;
	maxdepth = 0;
	q.push(top);
	while(!q.empty()){
		top = q.front();
		q.pop();
		if(vis[top]) continue;
		vis[top] = true;
		if(maxdepth < distance[top]){
			depos = top;
			maxdepth  = distance[top];
			deepnode[run].clear();
			deepnode[run].insert(top);
		}else if(maxdepth == distance[top]){			
			deepnode[run].insert(top);
		}
		for(unsigned i = 0;i<tree[top].size();++i){
			int child = tree[top][i];
			if(!vis[child]){
				q.push(child);
				distance[child]= distance[top]+1;
			}
		}
	}
	run++;
	return depos;
}
int findfather(int x){
	int root = x;
	while(root!=father[root]){
		root = father[root];
	}
	while(x!=father[x]){
		int tmp = x;
		x = father[x];
		father[tmp] = root;
	}
	return root;
}
int unionfather(int a,int b){
	int fa = findfather(a);
	int fb = findfather(b);
	int root = fa<fb?fa:fb;
	if(fa!=fb){
		father[a] = root;
		father[b] = root;
	}
	return root;
}
int main(){
	int n;
	scanf("%d",&n);
	tree.resize(n+1);
	father.resize(n+1);
	distance.resize(n+1);
	vis.resize(n+1);
	run = 0;
	int a,b;
	for(unsigned i = 1;i<father.size();++i){
		father[i] = i;
	}
	for(int i = 1;i<n;++i){
		scanf("%d%d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
		unionfather(a,b);
	}
	int components = 0,root;
	for(int i = 1;i<=n;++i){
		if(father[i] == i){
			root = i;
			components++;
		}
	}
	if(components>1){
		printf("Error: %d components",components);
	}else{
		bfs(bfs(root));
		auto i = deepnode[0].begin();
		auto j = deepnode[1].begin();
		auto k = i;
		while(i!=deepnode[0].end() || j!=deepnode[1].end()){
			if(i!=deepnode[0].end() && j!=deepnode[1].end()){
				if(*i<*j){
					k=i++;
				}else if(*j<*i){
					k=j++;
				}else{
					k=i++;
					j++;
				}
			}else if(i!=deepnode[0].end()){
				k = i++;
			}else if(j!=deepnode[1].end() ){
				k = j++;
			}
			printf("%d\n",*k);
		}
	}
	return 0;
}