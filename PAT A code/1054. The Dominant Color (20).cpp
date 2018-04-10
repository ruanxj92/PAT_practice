#include<cstdio>
#include<algorithm>
#include<map>
int main(){
	int m,n,col;
	scanf("%d%d",&m,&n);
	std::map<int,int> count;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<m;++j){
			scanf("%d",&col);
			if(count.find(col)!=count.end())
				++count[col];
			else
				count[col] = 1;
		}
	}
	int k = 0,MAX = 0;
	for(auto i = count.begin();i!=count.end();++i){
		printf("find %d color %d times.\n",i->first,i->second);
		if(i->second > MAX){
			k = i ->first;
			MAX = i->second;
		}
	}
	printf("%d\n",k);
	return 0;
}