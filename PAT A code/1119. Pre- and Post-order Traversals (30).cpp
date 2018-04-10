#include <cstdio>
#include <vector>
#include <algorithm>
std::vector<int> prev;
std::vector<int> post;
std::vector<int> inod;
bool unique;
struct node{
	int data;
	node *left,*right;
};
int len = 0;
int traversal(int l1,int r1,int l2,int r2){
	if(l1>r1) 
		return 0;
	if(l1==r1){//左子树只有一个根节点
		inod[++len] = prev[l1];
		return 1;
	}
	int i;
	for(i = l2;i<=r2;++i){//后序右子树中找前序的最左边子节点
		if(post[i] == prev[l1+1]) break;
	}
	int ok = 1;//将子树划分后递归中序遍历
	ok&=traversal(l1+1,l1-l2+i+1,l2,i);
	inod[++len] = prev[l1];
	ok&=traversal(l1-l2+i+2,r1,i+1,r2-1);
	return ok;
}
int main(){
	len = 0;
	int n;
	scanf("%d",&n);
	prev.resize(n+1);
	post.resize(n+1);
	inod.resize(n+1,0);
	for(int i = 1;i<=n;++i){
		scanf("%d",&prev[i]);
	}
	for(int i = 1;i<=n;++i){
		scanf("%d",&post[i]);
	}
	if(traversal(1,n,1,n)){
		printf("Yes");
	}else{
		printf("No");
	}
	printf("\n");
	for(int i = 1;i<inod.size();++i){
		if(i!=1) printf(" ");
		printf("%d",inod[i]);
	}
	printf("\n");
	return 0;
}