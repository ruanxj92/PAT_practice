#include <cstdio>
#include <queue>
struct node
{
	int data,height;
	node *left,*right;
	node(int input){
		data = input;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

int get_height(node* &root){
	if(root==NULL) return 0;
	else return root->height;
}
int height_update(node* root){
	return root->height = std::max(get_height(root->left),get_height(root->right))+1;
}
int getbalancer(node* root){
	return get_height(root->left) - get_height(root->right);
}

void L(node* &root){ 
	node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	height_update(root);
	height_update(tmp);
	root = tmp;
	return;
}
void R(node* &root){
	node* tmp = root->left;
	root->left = tmp->right;
	tmp->right= root;
	height_update(root);
	height_update(tmp);
	root = tmp;
	return;
}


void insert(node* &root, int data){
	if (root == NULL)
	{
		root = new node(data);
		return;
	}else{
		if(data < root->data){
			insert(root->left,data);
			height_update(root);
			if(getbalancer(root) == 2){
				if(getbalancer(root->left) == 1){
					R(root);
				}else if(getbalancer(root->left) == -1){
					L(root->left);
					R(root);
				}
			}
		}else{
			insert(root->right,data);
			height_update(root);
			if(getbalancer(root) == -2){
				if(getbalancer(root->right) == -1){
					L(root);
				}else if(getbalancer(root->right) == 1){
					R(root->right);
					L(root);
				}
			}
		}
	}
}


bool leveltraversal(node* root){
	bool res = true;
	bool haschild = true;
	std::queue<node*> Q;
	if(root != NULL)Q.push(root);
	while(!Q.empty()){
		node* top = Q.front();
		Q.pop();
		if(top != root) printf(" ");
		printf("%d", top->data);
		if(top->left == NULL){
			haschild = false;
		}else{
			Q.push(top->left);
			if(!haschild){
				res = false;
			}
		}
		if(top->right == NULL){
			haschild = false;
		}else{
			Q.push(top->right);
			if(!haschild){
				res = false;
			}
		}
	}
	printf("\n");
	return res;
}

int main(){
	node *root = NULL;
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int data;
		scanf("%d",&data);
		insert(root,data);
	}
	if(leveltraversal(root)) printf("YES\n");
	else printf("NO\n");
	return 0;
}