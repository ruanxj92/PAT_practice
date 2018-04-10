#include <cstdio>
#include <vector>
std::vector<int> inod;
std::vector<int> post;
std::vector<int> prev;
struct node{
	int data;
	node *left,*right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* findroot(int lp,int rp,int li,int ri){
	if(lp>=rp){
		return NULL;
	}
	int root = prev[lp];
	int rposi = li;
	for(int i = li;i<ri;++i){
		if(inod[i] == root){
			rposi = i;
			break;
		}
	}
	int leftlen = rposi-li;
	node* rt = new node(root);
	rt->left = findroot(lp+1,lp+leftlen+1,li,rposi);
	rt->right = findroot(lp+leftlen+1,rp,rposi+1,ri);
	return rt;
}
void posttraversal(node* root){
	if(root == NULL)
		return;
	posttraversal(root->left);
	posttraversal(root->right);
	post.push_back(root->data);
	return;
}
int main(){
	int n ;
	scanf("%d",&n);
	inod.resize(n);
	prev.resize(n);
	for(int i = 0;i<n;++i){
		scanf("%d",&prev[i]);
	}
	for(int i = 0;i<n;++i){
		scanf("%d",&inod[i]);
	}
	node* root = NULL;
	root = findroot(0,n,0,n);
	posttraversal(root);
	printf("%d\n",post[0]);
	return 0;
}