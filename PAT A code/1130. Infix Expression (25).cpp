#include <string>
#include <cstdio>
#include <vector>
struct node{
	std::string data;
	int left,right;
	node(std::string str,int l,int r){
		data = str;
		left = l;
		right = r;
	}
	node(){
	}
};
std::vector<node> expression;
void intravel(int rt,int l){
	if(rt == -1) return;
	bool bracket = (expression[rt].left !=-1 || expression[rt].right != -1)&&(l!=0);
	if(bracket) printf("(");
	intravel(expression[rt].left,l+1);
	printf("%s",expression[rt].data.c_str());
	intravel(expression[rt].right,l+1);
	if(bracket) printf(")");
	return;
}
int main(){
	int n,root;
	scanf("%d",&n);
	root = (n+1)*n/2;
	expression.resize(1);
	for(int i = 1;i<=n;++i){
		char data[11];
		int l,r;
		scanf("%s %d %d",data,&l,&r);
		expression.push_back(node(data,l,r));
		if(l!=-1) root-=l;
		if(r!=-1) root-=r;
	}
	intravel(root,0);
	return 0;
}