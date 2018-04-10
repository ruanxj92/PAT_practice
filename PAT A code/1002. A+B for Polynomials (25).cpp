#include <map>
//#include <iostream>
#include <iterator>
#include <cstdio>
using namespace std;
int main()
{
	map<int,double> res;
	int size,pos;
	double coe;
	scanf("%d",&size);
	for(int i = 0;i<size;++i){
		scanf("%d %lf",&pos,&coe);
		res[pos]+=coe;
	}
	scanf("%d",&size);
	for(int i = 0;i<size;++i){
		scanf("%d %lf",&pos,&coe);
		res[pos]+=coe;
		if(res[pos]==0)
			res.erase(pos);
	}
	printf("%d",res.size());
	for(map<int,double>::reverse_iterator s = res.rbegin();s!=res.rend();++s){
		printf(" %d %.1lf",s->first,s->second);
	}
	printf("\n");
	return 0;
}
