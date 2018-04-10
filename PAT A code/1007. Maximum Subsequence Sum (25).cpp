#include <cstdio>
#include <vector>
int main(){
	int leng,tmp;
	std::vector<int> v;
	scanf("%d",&leng);
	bool neg = true;
	for(int i = 0;i<leng;++i){
		scanf("%d",&tmp);
		v.push_back(tmp);		
		if(tmp >=0) neg = false;// neg is true when all the numbers are nonegtive
	}
	if(neg){//if all are negtive
		printf("0 %d %d\n",v[0],v[leng-1] );
		return 0;
	}
	std::vector<int> subsum(leng,0);
	std::vector<int> head(leng,0);
	subsum[0] = v[0];
	for (int i = 1; i < leng; ++i)
	{
		if(subsum[i-1]+v[i] > v[i]){
			subsum[i] = subsum[i-1]+v[i] ;
			head[i] = head [i-1];
		}else{
			subsum[i] = v[i];
			head[i] = i;
		}
	}
	int maxpos = 0;
	for (int i = 0; i < subsum.size(); ++i)
	{
		if(subsum[i] > subsum[maxpos])
			maxpos = i;
	}
	printf("%d %d %d",subsum[maxpos],v[head[maxpos]],v[maxpos] );
	return 0;
}