#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
const int MAXN = 1001;
bool cmp(std::pair<double,int> a , std::pair<double,int> b){
	return a.first > b.first;
}
int main(){
	int N;
	double D,tmp;
	double store[MAXN],value[MAXN],price[MAXN] = {0};
	scanf("%d %lf",&N,&D);
	for(int i = 0;i<N;++i){
		scanf("%lf",&store[i]);	
	}
	for(int i = 0;i<N;++i){
		scanf("%lf",&value[i]);	
	}
	for(int i = 0;i<N;++i){
		price[i] = value[i]/store[i];
	}
	std::vector<std::pair<double,int>> compare;
	std::pair<double,int> tmppair;
	for(int i = 0;i<N;++i){
		tmppair.first = price[i];
		tmppair.second = i;
		compare.push_back(tmppair);
	}
	std::sort(compare.begin(),compare.end(),cmp);
	std::vector<std::pair<double,int>>::iterator k = compare.begin();
	double sum = 0;
	while(D>0&&compare.size()>0){
		if(D>store[k->second]){
			sum += value[k->second];
			D -= store[k->second];
			k = compare.erase(k);
		}else{
			sum += price[k->second]*D;
			break;
		}
	}
	printf("%.2lf\n",sum);
	return 0;
}