/*
1030. Travel Plan (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
const int inf = 0x2fffffff;
int N,M,S,D;
struct node{
	int s;
	int d;
	int cost;
	int length;
	node(int _s,int _d,int _l,int _c){
		s = _s;
		d = _d;
		length = _l;
		cost = _c;
	}
};
std::queue<int> Q;
std::vector<std::vector<node> > adj;
std::vector<int> distance;
std::vector<int> cost;
std::vector<int> inqnum;
std::vector<int> prev;
std::stack<int> printstack;
std::vector<bool> inq;
bool spfa(int s){
	std::fill(distance.begin(),distance.end(),inf);
	std::fill(cost.begin(),cost.end(),inf);
	std::fill(inqnum.begin(),inqnum.end(),0);
	std::fill(inq.begin(),inq.end(),false);
	for(int i = 0;i<prev.size();++i){
		prev[i] = i;
	}
	Q.push(s);
	++inqnum[s];
	distance[s] = 0;
	cost[s] = 0;
	prev[s] = s;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for(int i = 0;i<adj[u].size();++i){
			int v = adj[u][i].d;
			int dis = adj[u][i].length;
			int c = adj[u][i].cost;
			if(distance[u]+dis <distance[v]){
				distance[v] = distance[u]+dis;
				cost[v] = cost[u] + c;
				prev[v] = u;
				if(!inq[v]){
					Q.push(v);
					inq[v] = true;					
					if(++inqnum[v] >= N ) return false;
				}
			}else if (distance[u]+dis == distance[v] && cost[v] > cost[u] + c){
				cost[v] = cost[u] + c;
				prev[v] = u;
				if(!inq[v]){
					Q.push(v);
					inq[v] = true;					
					if(++inqnum[v] >= N ) return false;
				}
			}//if(distance[u]+dis <= distance[v])
		}//for
	}//while
	return true;
}
int main(){
	scanf("%d %d %d %d",&N,&M,&S,&D);
	adj.resize(N);
	distance.resize(N);
	cost.resize(N);
	inqnum.resize(N);
	inq.resize(N);
	prev.resize(N);
	for(int i =0;i<M;++i){
		int s,d,c,l;
		scanf("%d %d %d %d",&s,&d,&l,&c);
		adj[s].push_back(node(s,d,l,c));
		adj[d].push_back(node(d,s,l,c));
	}
	spfa(S);

	int cur = D;
	printstack.push(D);
	for(int i = 0;i<M;++i){
		if(cur == S){
			break;
		}
		printstack.push(prev[cur]);
		cur = prev[cur];
	}
	while(!printstack.empty()){
		printf("%d ",printstack.top());
		printstack.pop();
	}
	printf("%d %d",distance[D],cost[D]);
	return 0;
}