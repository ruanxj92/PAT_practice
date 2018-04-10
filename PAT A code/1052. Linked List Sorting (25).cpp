#include <cstdio>
#include <algorithm>
#include <vector>
const int maxn = 100000;
struct node{
	int Address ,key,next;
	bool operator<(node a){
		return key < a.key;
	}
}tmp[maxn];
int main(){
	std::vector<node> v;
	int num,head, Address ,key,next;
	scanf("%d %d",&num,&head);
	for(int i = 0;i<num;++i){
		scanf("%d %d %d",& Address ,&key,&next);
		tmp[ Address ].Address = Address ;
		tmp[ Address ].key = key;
		tmp[ Address ].next = next;	
	}
	for(int i = head;i!=-1;i = tmp[i].next){
		v.push_back(tmp[i]);
	}
	if(v.size()){
		std::sort(v.begin(),v.end());
		printf("%d %05d\n",v.size(),v[0].Address);
		for(int i = 0;i!=v.size();++i){
			if(i!=v.size()-1) printf("%05d %d %05d\n", v[i]. Address , v[i].key, v[i+1]. Address );
			else printf("%05d %d -1\n",  v[i]. Address , v[i].key);
		}
	}
	else printf("0 -1\n");
	return 0;
}//链表题目注意可能会是空链表，以及输出输出的格式不要缺少零