#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
struct node{
	int data,left,right;
};
void inorder(std::vector<node> &v,int root,std::vector<int> &pre,int &index){
	if(root == -1) return;
	inorder(v,v[root].left,pre,index);
	v[root].data = pre[index++];
	inorder(v,v[root].right,pre,index);
}
void levelorder(std::vector<node> &v,std::vector<int> &bst){
	std::queue<int> q;
	q.push(0);
	int index = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		bst[index++] = v[top].data;
		if(v[top].left != -1) q.push(v[top].left);
		if(v[top].right != -1) q.push(v[top].right);
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	std::vector<node> v(n);
	std::vector<int> bst(n);
	std::vector<int> pre(n);
	for(int i = 0;i<n;++i){
		int left,right;
		scanf("%d %d",&left,&right);
		v[i].left = left;
		v[i].right = right;
	}
	for(int i = 0;i<n;++i){
		int data;
		scanf("%d",&data);
		pre[i] = data;
	}
	std::sort(pre.begin(),pre.end());
	int index = 0;
	inorder(v,0,pre,index);
	levelorder(v,bst);
	for(int i = 0;i<n;++i){
		if(i) printf(" ");
		printf("%d",bst[i]);
	}
	return 0;
}