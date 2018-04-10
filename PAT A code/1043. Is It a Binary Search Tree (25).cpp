/*
1043. Is It a Binary Search Tree (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO

*/
#include <cstdio>
#include <vector>
typedef struct node 
{
	int data;
	node *left;
	node *right;
}Node;
void insert(node* &root, int &data){
	if(root == NULL) {
		root= new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return ;
	}
	if(data<root->data){
		insert(root->left,data);
	}else{
		insert(root->right,data);
	}
}
void preorder(std::vector<int> &ori,node* root){
	if(root == NULL) return;
	ori.push_back(root->data);
	preorder(ori,root->left);
	preorder(ori,root->right);
}
void premorder(std::vector<int> &ori,node* root){
	if(root == NULL) return;
	ori.push_back(root->data);
	premorder(ori,root->right);
	premorder(ori,root->left);
}
void postorder(std::vector<int> &ori,node* root){
	if(root == NULL) return;
	postorder(ori,root->left);
	postorder(ori,root->right);
	ori.push_back(root->data);
}
void postmorder(std::vector<int> &ori,node* root){
	if(root == NULL) return;
	postmorder(ori,root->right);
	postmorder(ori,root->left);
	ori.push_back(root->data);
}

int main(){
	int N,temp;
	std::vector<int> ori,pre,post,prem,postm;
	scanf("%d",&N);
	node* root = NULL;
	for(int i = 0;i<N;++i){
		scanf("%d",&temp);
		ori.push_back(temp);
		insert(root,temp);
	}
	preorder(pre,root);
	premorder(prem,root);
	postorder(post,root);
	postmorder(postm,root);
	if(ori==pre){
		printf("YES\n");
		for(int i = 0;i!=post.size();++i){
			printf("%d",post[i]);
			if(i+1<post.size()) printf(" "); 
			else printf("\n");
		}
	}else if(ori==prem){
		printf("YES\n");
		for(int i = 0;i!=postm.size();++i){
			printf("%d",postm[i]);
			if(i+1<postm.size()) printf(" "); 
			else printf("\n");
		}
	}else printf("NO\n");
	return 0;
}