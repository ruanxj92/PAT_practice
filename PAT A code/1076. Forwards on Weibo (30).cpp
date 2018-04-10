/*
1076. Forwards on Weibo (30)
ʱ������
3000 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5

*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
const int maxn = 1001;
struct node{
	int id;
	int layer;
};
std::vector<node> user[maxn];
bool inq[maxn] = {false};
int BFS(int s, int L){
	int forward = 0;
	std::queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);//
	inq[start.id] = true;//
	while(!q.empty()){//
		node top = q.front();//
		q.pop();//
		for(unsigned int i = 0;//
			i < user[top.id].size();
			++i){
			node next = user[top.id][i];
			next.layer = top.layer+1;
			if(inq[next.id] == false && next.layer<=L){
				q.push(next);
				inq[next.id] = true;
				++forward;
			}
		}
	}
	return forward;
}
int main(){
	node u;
	int N,L,follow,followee;
	scanf("%d %d",&N,&L);
	for(int i = 1;i<=N;++i){
		u.id = i;
		scanf("%d",&follow);
		while(follow--){
			scanf("%d",&followee);
			user[followee].push_back(u);
		}
	}
	int query,s;
	scanf("%d",&query);
	while(query--){//
		scanf("%d",&s);
		std::memset(inq,false,sizeof(inq));
		printf("%d\n",BFS(s,L));
	}
	return 0;
}