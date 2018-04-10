#include <iostream>
#include <vector>
using namespace std;
bool check(const vector<int> &candi,const vector<vector<int> > &G,vector<int> precount){
	for(auto i=candi.begin();i!=candi.end();++i){
		int from = *i;
		if(precount[*i]>0) return false;
		for(auto j = G[*i].begin();j!=G[*i].end();++j){
			int to = *j;
			--precount[*j];
		}
	}
	return true;
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > G(n+1);
	vector<int> precount(n+1,0);
	for(int i = 0;i<m;++i){
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		precount[b]++;
	}
	int query,count = 0;
	cin >> query;
	vector<int> candi(n);
	for(int j = 0;j<query;++j){
		for(int i = 0;i<n;++i){
			cin >> candi[i];
		}
		if(!check(candi,G,precount)){
			if(count++) cout << ' ';
			cout << j;
		}
	}
	return 0;
}