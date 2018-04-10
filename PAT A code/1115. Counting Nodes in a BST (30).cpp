#include <cstdio>
#include <vector>
struct node{
	int data,depth;
	node* left;
	node* right;
	node(int _indata,int _dpth){
		data = _indata;
		depth = _dpth;
		left = NULL;
		right = NULL;
	}
};
std::vector<int> depthsum;
int maxdepth = 0;
void insert(node *&root,int data,int depth){
	if(root == NULL){
		root = new node(data,depth);
		depthsum[depth]++;
		if(depth > maxdepth)
			maxdepth = depth;
	}else if(data > root->data){
		insert(root->right,data,depth+1);
	}else{
		insert(root->left,data,depth+1);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	depthsum.assign(N,0);
	node* root = NULL;
	for(int i =0;i<N;++i){
		int tmp;
		scanf("%d",&tmp);
		insert(root,tmp,0);
	}
	printf("%d + %d = %d\n", depthsum[maxdepth],depthsum[maxdepth-1],depthsum[maxdepth]+depthsum[maxdepth-1]);
	return 0;
}