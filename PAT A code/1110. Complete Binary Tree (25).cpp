#include <cstdio>
#include <vector>
#include <queue>
struct node{
	int parent;
	int left,right;
	node(int l,int r){
		parent = -1;
		if(l == '-') left = -1;
		else left = l;
		if(r == '-') right = -1;
		else right = r;
	}
};
int tail;
bool is_complete_binary_tree(const std::vector<node> &tree,int root){
	std::queue<int> q;
	q.push(root);
	int traveled = 0;
	bool flag = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now == -1){
			if(traveled < tree.size()){
				flag = false;
				continue;
			}else{
				break;
			}
		}else{
			tail = now;
			traveled++;
			q.push(tree[now].left);
			q.push(tree[now].right);
		}
	}
	return flag;
}
int tonum(char a[]){
	if(a[0] == '-'){
		return -1;
	}
	int ans = 0,i=0;
	while(a[i]){
		ans = ans*10+ a[i++]-'0';
	}
	return ans;
}
int main(){
	int size,left,right;
	char buffer[8];
	scanf("%d",&size);
	std::vector<node> tree;
	for(int i = 0;i<size;++i){
		scanf("\n%s",buffer);
		left = tonum(buffer);
		scanf(" %s",buffer);
		right = tonum(buffer);
		tree.push_back(node(left,right));
	}
	for (int i = 0; i < size; ++i){
		if(tree[i].left !=-1){
			tree[tree[i].left].parent = i;	
		}
		if(tree[i].right !=-1){
			tree[tree[i].right].parent = i;	
		}
	}
	int root = -1;
	for(int i = 0;i<size;++i){
		if(tree[i].parent == -1){
			root = i;
			break;
		}
	}
	if(is_complete_binary_tree(tree,root)){
		printf("YES %d\n",tail);
	}else{
		printf("NO %d\n",root);
	}
	return 0;
}