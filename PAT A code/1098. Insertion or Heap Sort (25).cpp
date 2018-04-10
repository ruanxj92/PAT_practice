#include <cstdio>
#include <vector>
#include <algorithm>
bool insertpos(std::vector<int> ori,const std::vector<int> &fin){
	bool same = false;
	for(int i = 2;i<ori.size();++i){//注意此处如果从int i = 1 开始就有一个2号测试点不过，需要仔细考虑清楚
		if(i!=2 && ori == fin) same = true;
		std::sort(ori.begin(),ori.begin()+i);
		if(same) break;
	}
	if(!same) return false;
	printf("Insertion Sort\n");
	for(int i = 0;i<ori.size();++i){
		if(i) printf(" ");
		printf("%d",ori[i]);
	}
	return true;
}
void  heappos(std::vector<int> ori,const std::vector<int> &fin){
	printf("Heap Sort\n");
	std::make_heap(ori.begin(),ori.end());
	bool same = false;
	for(int i = ori.size()-1;i>0;--i){
		if(i!=ori.size()-1 && ori == fin) same = true;
		std::swap(ori[i],ori[0]);
		make_heap(ori.begin(),ori.begin()+i);
		if(same) break;
	}
	for(int i = 0;i<ori.size();++i){
		if(i) printf(" ");
		printf("%d",ori[i]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int> ori(n);
	std::vector<int> fin(n);
	for(int i = 0;i<n;++i){
		scanf("%d",&ori[i]);
	}
	for(int i = 0;i<n;++i){
		scanf("%d",&fin[i]);
	}
	if(!insertpos(ori,fin)){
		heappos(ori,fin);
	}
	return 0;
}
//关于测试数据，0，2，4号测试点是插入排序，1、3、5测试点是堆排序。