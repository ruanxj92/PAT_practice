#include <cstdio>
#include <queue>
struct node{
	int key;
	node* left;
	node* right;
	node(){
		left = NULL;
		right = NULL;
	}
};
int postorder[31],inorder[31];
int n;
node* findroot(int postl,int postr,int inl,int inr){
	if(postl > postr)
		return NULL;
	node* root = new node;
	root->key = postorder[postr];
	int i;
	for(i =inl;i<=inr;++i){
		if(inorder[i] == postorder[postr])
			break;
	}
	int numleft = i-inl;
	root->left = findroot(postl,postl+numleft-1,inl,i-1);
	root->right = findroot(postl+numleft,postr-1,i+1,inr);
	return root;
}
void bfs(node* root){
	std::queue<node*> q;
	q.push(root);
	node* now;
	int count = 0;
	while(!q.empty()){
		now = q.front();
		q.pop();
		printf("%d",now->key);
		count++;
		if(count < n) printf(" ");
		if(now->left)
			q.push(now->left);
		if(now->right)
			q.push(now->right);
	}
}
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",postorder+i);
	}
	for(int i = 0;i<n;++i){
		scanf("%d",inorder+i);
	}
	node* root = findroot(0,n-1,0,n-1);
	bfs(root);
	return 0;
}