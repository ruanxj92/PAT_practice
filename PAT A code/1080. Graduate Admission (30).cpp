#include <cstdio>
#include <vector>
#include <algorithm>
struct node{
	int ge,gi,sum,rank,id;
	std::vector<int> choices;
	bool operator<(const node& b){
		if(ge+gi !=b.ge+b.gi)
			return ge+gi >b.ge+b.gi;
		if(ge!=b.ge)
			return ge > b.ge;
		return id <b.id;
	}
	node(){
		rank = 0;
	}
};
struct sch{
	int need,lastrank;
	std::vector<int> can;
	sch(){
		need = 0;
		lastrank = 0;
	}
};
int main(){
	int N,M,K;
	std::vector<sch> school;
	scanf("%d%d%d",&N,&M,&K);
	school.resize(M);	
	for(int i =0;i<M;++i){
		scanf("%d",&school[i].need);
	}
	std::vector<node> applicants;
	applicants.resize(N);
	for(int i =0;i<N;++i){
		scanf("%d %d",&applicants[i].ge,&applicants[i].gi);
		applicants[i].sum = applicants[i].ge+applicants[i].gi;
		applicants[i].choices.resize(K);
		applicants[i].id = i;
		for(int j = 0;j<K;++j){
			scanf("%d",&applicants[i].choices[j]);
		}
	}
	sort(applicants.begin(),applicants.end());
	for(int i = 0 ;i<applicants.size();++i){
		if(i>0){
			if(applicants[i].sum == applicants[i-1].sum&&
				applicants[i].ge == applicants[i-1].ge){
				applicants[i].rank = applicants[i-1].rank;
			}else{
				applicants[i].rank = i;
			}
		}
		for(int j = 0;j<applicants[i].choices.size();++j){
			int sc = applicants[i].choices[j];
			if(school[sc].can.size()<school[sc].need || 
				(school[sc].can.size()>0 && school[sc].lastrank == applicants[i].rank)){
				school[sc].can.push_back(applicants[i].id);
				school[sc].lastrank = applicants[i].rank;
				break;
			}
		}
	}
	for(int i= 0;i<M;++i){
		std::sort(school[i].can.begin(),school[i].can.end());
		for(int j = 0;j<school[i].can.size();++j){
			if(j!=0) printf(" ");
			printf("%d",school[i].can[j]);
		}
		printf("\n");
	}
	return 0;
}