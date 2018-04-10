#include <cstdio>
#include <vector>
#include <queue>
struct node{
	int data,level;
	node *left,*right;
	node(int d,int L){
		level = L;
		data = d;
		left = NULL;
		right = NULL;
	}
};
std::vector<int> inod;
std::vector<int> post;
node *buidtree(int ib,int ie,int pb,int pe,int l){
	if(ib>=ie){
		return NULL;
	}
	node* rt = new node(post[pe-1],l);
	int im;
	for(im = ib; im <ie; ++im){
		if(inod[im] == post[pe-1]) break;
	}
	rt->left =	buidtree(ib,im,pb,pb+im - ib,l+1);
	rt->right = buidtree(im+1,ie,pb+im - ib,pe-1,l+1);
	return rt;
}
void zigzagtraversal(node* root,int n){
	std::queue<node*> q;
	q.push(root);
	std::vector<std::vector<int> > vec(n);
	while(!q.empty()){//normal level traversal
		node* top = q.front();
		vec[top->level].push_back(top->data);
		q.pop();
		if(top->left) q.push(top->left);
		if(top->right) q.push(top->right);
	}
	int count = 0;
	for(int i = 0;i<n;++i){//zigzag output
		if(i%2){
			for(int j = 0;j<vec[i].size();++j){
				if(count++) printf(" ");
				printf("%d",vec[i][j]);
			}
		}else{
			for(int j = vec[i].size()-1;j>=0;--j){
				if(count++) printf(" ");
				printf("%d",vec[i][j]);
			}
		}
	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);	inod.resize(n);	post.resize(n);
	for (std::vector<int>::iterator i = inod.begin(); i != inod.end(); ++i){
		scanf("%d",&(*i));
	}
	for (std::vector<int>::iterator i = post.begin(); i != post.end(); ++i){
		scanf("%d",&(*i));
	}
	node* root = buidtree(0,n,0,n,0);
	zigzagtraversal(root,n);
	return 0;
}