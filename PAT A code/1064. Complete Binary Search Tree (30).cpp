#include <cstdio>
#include <algorithm>
#include <vector>
	int n;
void inorder(std::vector<int> &v,int root,int &index,std::vector<int> &cbt){
	if(root>=n) return ;
	inorder(v,root*2+1,index,cbt);
	cbt[root] = v[index++];
	inorder(v,root*2+2,index,cbt);	
}
int main(){
	std::vector<int> v;
	scanf("%d",&n);	
	std::vector<int> cbt(n);
	for(int i = 0;i<n;++i){
		int tmp;
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	std::sort(v.begin(),v.end());
	int index = 0;
	inorder(v,0,index,cbt);
	for(int i = 0;i<n;++i){
		if(i) printf(" ");
		printf("%d",cbt[i]);
	}
	return 0;
}