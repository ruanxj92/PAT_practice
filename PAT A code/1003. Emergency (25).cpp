/***
1003. Emergency (25)

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
***/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
const int maxn = 510;
const int inf = 0x3fffffff;
struct citydata{
	int id;
	int length;
};
std::vector<citydata> city[maxn];
int teams[maxn] = {0},maxteams[maxn] = {0},minlength[maxn] = {inf},roads[maxn] = {0};
bool inq[maxn] = {false};
void dijkstra(int s,int n){
	std::fill(minlength,minlength+n,inf);
	minlength[s] = 0;
	maxteams[s] = teams[s];	roads[s] = 1;
	for(int i = 0;i<n;++i){
		int u =-1,min = inf;
		for(int j = 0;j<n;++j){
			if(!inq[j]&& minlength[j]<min){
				u = j;	min = minlength[j];
			}
		}
		if(u < 0) return;
		inq[u] = true;
		for(int j = 0;j<city[u].size();++j){
			int target = city[u][j].id;
			if(!inq[target ] && minlength[u] + city[u][j].length < minlength[target]){
				minlength[target] =minlength[u] + city[u][j].length ;
				maxteams[target] = maxteams[u] + teams[target];
				roads[target] = roads[u];
			}else if(minlength[u] + city[u][j].length == minlength[target]){
				if(maxteams[u] + teams[target] > maxteams[target]) 
					maxteams[target] = maxteams[u] + teams[target];
				roads[target] += roads[u];
			}
		}
	}
}
int main(){
	int N,M,c1,c2,team;
	scanf("%d %d %d %d",&N,&M,&c1,&c2);
	for(int i = 0;i<N;++i){
		scanf("%d",&team);
		teams[i] = team;
	}
	for(int i = 0;i<M;++i){
		int start,end,length;
		scanf("%d %d %d",&start,&end,&length);
		citydata city1,city2;
		city1.id = start;	city1.length = length;
		city2.id = end;		city2.length = length;
		city[start].push_back(city2);
		city[end].push_back(city1);
	}
	dijkstra(c1,N);
	printf("%d %d\n",roads[c2],maxteams[c2]);
	return 0;
}