#include <cstdio>
#include <vector>
#include <algorithm>
const int hobbynum = 1001;
int isroot[hobbynum] = {0};
int father[hobbynum];
int hobby[hobbynum] = {0};
int findfather(int input){
	int root = input;
	while(root!=father[root]) root = father[root];
	while(input!=father[input]){
		int z =input;
		input= father[input];
		father[z] = root;
	}
	return root;
}
int uni(int a,int b){
	int fa = findfather(a);
	int fb = findfather(b);
	if(fa != fb){
		father[fb] = fa;
	}
	return fa;
}
int main(){
	int num,id;
	scanf("%d",&num);
	for(int i = 1;i<=num;++i){
		father[i] = i;
	}
	for(int i = 1;i<=num;++i){
		int ki;
		scanf("%d:",&ki);
		for(int j = 0;j<ki;++j){
			int h;
			scanf("%d",&h);
			if(hobby[h] == 0){
				hobby[h] = i;
			}
			uni(i,findfather(hobby[h]));
		}
	}
	for(int i = 1;i<=num;++i){
		isroot[findfather(i)]++;
	}
	int rootnum=0;
	for(int i = 1;i<=num;++i){
		if(isroot[i]) rootnum++;
	}
	std::sort(isroot+1,isroot+num+1,std::greater<int>());
	printf("%d\n",rootnum);
	for(int i = 1;i<=rootnum;++i){
		if(i!=1) printf(" ");
		printf("%d",isroot[i]);
	}
	return 0;
}