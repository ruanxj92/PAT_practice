#include <cstdio>
#include <stack>
#include <algorithm>
const int maxn = 31;
struct node{
	int data;
	node* left;
	node* right;
	node(){
		left = NULL;
		right = NULL;
	}
};
int in[maxn],pre[maxn];
node* findroot(int preL,int preR,int inL,int inR){
	if(preL > preR) return NULL;
	node* root = new node;
	root->data = pre[preL];
	int i;
	for(i = inL;i<=inR;++i){
		if(in[i] == pre[preL])
			break;
	}
	int len = i-inL;
	root->left = findroot(preL+1,preL+len,inL,i-1);
	root->right = findroot(preL+len+1,preR,i+1,inR);
	return root;
}
void outputpost(node* root,int num){
	if(root == NULL) return;
	outputpost(root->left,num+1);
	outputpost(root->right,num+1);
	printf("%d",root->data);
	if(num) printf(" ");
}
int main(){
	int num,data,posin=0,pospost=0,pospre=0;
	char op[5];
	scanf("%d\n",&num);
	std::stack<int> st;
	for(int i = 0;i<2*num;++i){
		scanf("%s",op);
		if(op[1]=='u'){
			scanf("%d",&data);
			st.push(data);
			pre[pospre++] = data;
		}else{
			in[posin++] = st.top();
			st.pop();
		}
	}
	node* root = findroot(0,num-1,0,num-1);
	outputpost(root,0);
	return 0;
}