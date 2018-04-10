#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
struct node{
	int data;
	node *left,*right;
	bool equal;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
		equal = true;
	}
};
int balckbcount = -1;
node* pretraversal(std::vector<int> &a,int l,int r){
	if(l>=r) return NULL;
	node* root = new node(a[l]);
	int rpos = l;
	for(;rpos<r;++rpos){
		if(std::abs(a[rpos]) > std::abs(a[l])){
			break;
		}
	}
	root->left = pretraversal(a,l+1,rpos);
	root->right= pretraversal(a,rpos,r);
	return root;
}
node* buildtree(){
	int size;
	scanf("%d",&size);
	std::vector<int> pre(size);
	for(int i = 0;i<size;++i){
		scanf("%d",&pre[i]);
	}
	node* root = pretraversal(pre,0,size);
	return root;
}
bool check(node* root,int count){
	if(root == NULL){
		if(balckbcount == -1){
			balckbcount = count;
		}else if(balckbcount != count){
			return false;
		}
		return true;
	}
	if(root->data < 0){
		if(root->left && root->left->data<0) return false;
		if(root->right && root->right->data<0) return false;
	}else{
		count++;
	}
	return check(root->left,count) && check(root->right,count);
}
int main(){
	int tree_num;
	scanf("%d",&tree_num);
	while(tree_num--){
		node* root = buildtree();
		balckbcount = -1;
		if(root && root->data >0 && check(root,0)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}