#include<cstdio>
#include<algorithm>
const int maxn = 100000;
struct Node{	
	char letter;
	bool visited;
	int next;
}chain[ maxn ];
int main(){
	int begin1,begin2,n;
	scanf("%d %d %d",&begin1,&begin2,&n);
	for(int i = 0;i<maxn;++i){
		chain[i].next=-2;
		chain[i].visited=false;
	}
	int addr,next;char letter;
	for(int i = 0;i<n;++i){		
		scanf("%d %c %d",&addr,&letter,&next);
		chain[addr].letter = letter;
		chain[addr].next = next;
	}
	for(addr = begin1;addr>-1;addr = chain[addr].next)
		chain[addr].visited = true;
	for(addr = begin2;addr>-1;addr = chain[addr].next)
		if(chain[addr].visited == true)
			break;

	if(addr<0)
		printf("-1\n");
	else 
		printf("%05d\n",addr);
	return 0;
}