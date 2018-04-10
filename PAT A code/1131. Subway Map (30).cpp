#include <cstdio>
#include <vector>
const int maxn = 10000;
int line[maxn][maxn],vis[maxn];
std::vector<std::vector<int>> v(maxn);
std::vector<int> path,tempath;
int counttransfer(std::vector<int> &a){
	int count = -1,preline = 0;
	for(int i = 1;i<a.size();++i){
		if(line[a[i-1]][a[i]]!=preline) count++;
		preline = line[a[i-1]][a[i]];
	}
	return count;
}
void dfs(int now,int e,int count,int &mincount,int &mintransfer){
	if(now == e){
		if(count<mincount||(count==mincount &&counttransfer(tempath)<mintransfer)){
		mincount = count;
		mintransfer = counttransfer(tempath);
		path=tempath;
		}
		return;
	}
	for(int i = 0;i<v[now].size();++i){
		if(!vis[v[now][i]]){
			vis[v[now][i]] = 1;
			tempath.push_back(v[now][i]);
			dfs(v[now][i],e,count+1,mincount,mintransfer);
			vis[v[now][i]] = 0;
			tempath.pop_back();
		}
	}
}
int main(){
	int n;
	int m,pre,next;
	int k;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d %d",&m,&pre);
		for(int L = 1;L<m;++L){
			scanf("%d",&next);
			v[pre].push_back(next);
			v[next].push_back(pre);
			line[pre][next] = i+1;
			line[next][pre] = i+1;
			pre = next;
		}
	}
	scanf("%d",&k);
	int start,end;
	for(int i = 0;i<k;++i){
		scanf("%d %d",&start,&end);
		tempath.clear();
		tempath.push_back(start);
		vis[start] = 1;
		int mincount = maxn,mintransfer = maxn;
		dfs(start,end,0,mincount,mintransfer);
		vis[start] = 0;
		printf("%d\n",mincount);
		int preline = 0,pretransfer = start;
		for(int j = 1;j<path.size();++j){
			if(line[path[j-1]][path[j]]!=preline){
				if(preline!=0) printf("Take Line#%d from %04d to %04d.\n", preline, pretransfer, path[j-1]);
				preline = line[path[j-1]][path[j]];
				pretransfer = path[j-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preline, pretransfer, end);
	}
	return 0;
}