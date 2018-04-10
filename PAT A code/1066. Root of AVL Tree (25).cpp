#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
struct node{
	int data,height;
	node* left;
	node* right;
	node(int _data){
		data = _data;
		height = 1;
		left = NULL;
		right = NULL;
	}
};
int getheight(const node* root){
	if(root == NULL) return 0;
	return root->height;
}
void updateheight(node* root){
	int heightL = getheight(root->left),heightR = getheight(root->right);
	root->height = (heightL>heightR?heightL:heightR)+1;
}
int balancefactor(const node* root){
	return getheight(root->left)-getheight(root->right);
}
void R(node* &root){
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void L(node* &root){
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void insert(node* &root, int &data){
	if(root == NULL){
		root = new node(data);
		return;
	}
	if(data < root->data){
		insert(root->left,data);
		updateheight(root);
		if(balancefactor(root)== 2){
			if(balancefactor(root->left) == 1){
				R(root);
			}else if(balancefactor(root->left) == -1){
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,data);
		updateheight(root);
		if(balancefactor(root)== -2){
			if(balancefactor(root->right) == -1){
				L(root);
			}else if(balancefactor(root->right) == 1){
				R(root->right);
				L(root);
			}
		}
	}

}
int main(){
	int n ;
	scanf("%d",&n);
	int data;
	node* root = NULL;
	for(int i = 0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	printf("%d",root->data);
	return 0;
}