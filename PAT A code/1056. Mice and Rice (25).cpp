#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
const int maxn = 1010;
struct Mouse{
	int weight,R;
};
int main(){
	std::vector<Mouse> mouse;
    int np,ng,order;
	Mouse node;
    scanf("%d %d",&np,&ng);
	for(int i = 0;i<np;++i){
		scanf("%d",&node.weight);
		node.R = 0;
		mouse.push_back(node);
	}
	std::queue<int> q;
	for(int i = 0;i<np;++i){
		scanf("%d",&order);
		q.push(order);
	}
	int temp = np,group;
	while(q.size()!=1){
		if(temp% ng ==0) group = temp / ng;
		else group = temp/ng +1;
		for(int i=0;i<group;++i){
			int k  = q.front();
			for(int j = 0;j<ng;++j){
				if(i*ng +j >=temp) break;
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight)
					k = front;				
			mouse[front].R = group + 1;
			q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].R = 1;
	for(int i = 0;i<np;++i){
		printf("%d",mouse[i].R);
		if(i<np-1) printf(" ");
	}
	printf("\n");
    return 0;
}