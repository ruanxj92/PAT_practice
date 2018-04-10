/*
Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1.


Figure 1
Input Specification:

Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

Output Specification:

For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
input
2 1 2
1 1
00 1 01

output
1 1
input
1 0 2
2
output
2


*/
#include <cstdio>
#include <vector>
#include <algorithm>
struct node{
	int weight;
	std::vector<int> children;
};
int N,M,S;
std::vector<int> path;//记录从根开始的路径
std::vector<node> Node;//记录所有节点及其子节点
bool cmp(int a,int b){
	return Node[a].weight > Node[b].weight ;
}
void DFS(int node,int num,int sum){
	if(sum > S) return ;//权重超限，返回
	if(sum == S){	//当路径权重和相等于给定值时
		if(Node[node].children.size() > 0) return ;//非叶节点，返回,
		for(int i = 0;i < num;++i)//在叶节点 找到合适路径，输出
			printf("%d%c",Node[path[i]].weight,i == (num - 1)? '\n':' ');
		return;	
	}
	for(int i = 0 ;i < Node[node].children.size(); ++i){//权重不足，继续找子节点
		int nextchild = Node[node].children[i];	path[num] = nextchild;
		DFS(nextchild ,num+1,sum+Node[nextchild].weight);
	}
	return;
}
int main(){
	scanf("%d %d %d",&N,&M,&S);
	Node.resize(N);	path.resize(N);
	for(int i =0;i<N;++i)// 读N个节点权重
		scanf("%d",&(Node[i].weight));
	for(int i =0;i<M;++i){//读子节点
		int head,nextn; scanf("%d %d",&head,&nextn);
		Node[head].children.resize(nextn);
		for(int j = 0;j<nextn;++j)
			scanf("%d",&Node[head].children[j]);
		std::sort(Node[i].children.begin(),Node[i].children.end(),cmp);//按照子节点权重降序排列，便于结束时输出
	}
	path[0] = 0;DFS(0,1,Node[0].weight);
	return 0;
}
/*
http://blog.csdn.net/liuchuo/article/details/52258046 这个网页里的代码能全部通过。
但是自己的代码总是有一个编号为2的测试点错误。搞不懂。
仔细看了下，认为最重要的区别在于首次DFS前自己的代码把0点放入路径，但是网上的参考代码没有这一步。
然后如果把自己的代码删除这一句的话，连其他测试点都通不过。很迷~~~
*/