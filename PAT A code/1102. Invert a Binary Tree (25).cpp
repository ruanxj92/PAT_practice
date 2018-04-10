#include<cstdio>
#include<queue>
struct Node{
	int left,right;
}seq[10];
bool notroot[10] = {false};
int count = 0;
int findroot(Node seq[],int &N){
	int i;
	for(i = 0;i<N;++i){
		if(!notroot[i]){
			return i;
		}
	}
	return -1;
}
void levelordertravel(Node seq[],int &root,int &N){
	std::queue<int> q;
	if(N>=0)
		q.push(root);
	else
		return;
	int num = 0;
	while(!q.empty()){
		int ptmp = q.front();
		q.pop();
		printf("%d",ptmp);
		if(++num< N)
			printf(" ");
		if(seq[ptmp].right>=0&&seq[ptmp].right<N)
			q.push(seq[ptmp].right);
		if(seq[ptmp].left>=0&&seq[ptmp].left<N)
			q.push(seq[ptmp].left);
	}
	printf("\n");
	return;
}
void inordertravel(Node seq[],int &root,int &end){
	if(root==-1)
		return;
	inordertravel(seq,seq[root].right,end);
	printf("%d",root);
	if(++count < end) printf(" ");
	inordertravel(seq,seq[root].left,end);
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i = 0;i<N;++i){
		char left,right;
		scanf("\n%c %c",&left,&right);
		if(left == '-')	seq[i].left = -1;
		else{
			seq[i].left = left - '0';
			notroot[seq[i].left] = true;
		}
		if(right== '-')	seq[i].right = -1;
		else{
			seq[i].right= right- '0';
			notroot[seq[i].right] = true;
		}
	}
	int root = findroot(seq,N);
	levelordertravel(seq,root ,N);
	inordertravel(seq,root,N);
	printf("\n");
	return 0;
}