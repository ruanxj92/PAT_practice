#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int check(const vector<bool> &clique,const vector<vector<bool>> &G){
    int len = clique.size(),n=0;
    vector<int> vis(len,0);
    for(int i = 1;i<len;++i){
        if(clique[i]){
			++n;
            for(int j = 1;j<len;++j){
                if(G[i][j]){
                    vis[j]++;
                }
            }
        }
    }
	bool maxclique=true,close=true;
    for(int i = 1;i<len;++i){
        if(clique[i]){
            if(vis[i]!=n-1) close = false;
        }else{
            if(vis[i]==n) maxclique = false;
        }
    }
	if(close){
		if(maxclique) return 0;
		else return 1;
	}else{
		return 2;
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> G(n+1,vector<bool>(n+1,false));
    for(int i = 0;i<m;++i){
        int a,b;
        cin >> a >> b;
        G[a][b] = true;
        G[b][a] = true;
    }
    int query;
    cin >> query;
    vector<bool> clique;
    for(int i = 0;i<query;++i){
        int len,tmp;
        cin >> len;
        clique.assign(n+1,false);
        for(int j = 0;j<len;++j){
            cin >> tmp;
            clique[tmp] = true;
        }
        int flag = check(clique,G);
        if(flag == 0) cout <<"Yes\n";
        else if(flag == 1) cout <<"Not Maximal\n";
        else cout << "Not a Clique\n";
    }
    return 0;
}