#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
int tonum(char *a){//字符变int
	return (a[3]-'0')+(a[2]-'A')*10+(a[1]-'A')*260+(a[0]-'A')*6760;
}
void print(int id){//int返回字符
	printf("%c",id/6760+'A'); 
	printf("%c",id%6760/260+'A'); 
	printf("%c",id%260/10+'A'); 
	printf("%d\n",id%10);
}
int main(){
	int N,K;
	char tmp[5];
	scanf("%d %d",&N,&K);	
	std::vector<std::vector<int> > courselist;
	courselist.resize(K);
	for(int i = 0;i<N;++i){
		int num;
		scanf("%s%d",tmp,&num);
		for(int j = 0;j<num;++j){
			int stu;
			scanf("%d",&stu);
			courselist[--stu].push_back(tonum(tmp));
			std::push_heap(courselist[stu].begin(),courselist[stu].end());
		}
	}
	for(int i = 0;i<K;++i){
		printf("%d %d\n", i+1,courselist[i].size());
		std::sort_heap(courselist[i].begin(),courselist[i].end());
		for(auto j = courselist[i].begin();j!=courselist[i].end();++j){
			print(*j);
		}
	}
	return 0;
}
//在数据量很大的时候，手动写映射函数比用STL的map快。
//用push_back 配合push_heap可以达到log n 插入复杂度。同理，输出时利用sort_heap达到顺序输出