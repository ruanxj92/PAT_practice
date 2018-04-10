#include <cstdio>
#include <algorithm>
#include <vector>
struct node{
	int id,data,next;
}tmp,seq[1000001];
int main(){
	std::vector<node> vec;
	int head,len,seg;
	scanf("%d %d %d",&head,&len,&seg);
	for(int i = 0;i<len;++i){
		scanf("%d %d %d",&tmp.id,&tmp.data,&tmp.next);
		seq[tmp.id].id = tmp.id;
		seq[tmp.id].data = tmp.data;
		seq[tmp.id].next = tmp.next;
	}
	for(int i =head;i!=-1;i = seq[i].next){
		vec.push_back(seq[i]);
	}
	for(int i = 0;i<vec.size();i+=seg){
		if(i+seg<=vec.size())//这里注意要有等号，用于处理正好整除的长度
			std::reverse(vec.begin()+i,vec.begin()+i+seg);
	}
	for(int i = 0;i<vec.size();++i){
		if(i!=vec.size()-1){
			printf("%05d %d %05d\n",vec[i].id,vec[i].data,vec[i+1].id);
		}else{
			printf("%05d %d -1\n",vec[i].id,vec[i].data);
		}
	}
	return 0;
}//最后一个测试样例包含有在链表以外的无效节点。特别坑