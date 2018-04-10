#include <cstdio>
#include <vector>
#include <algorithm>
struct tests{
	std::string id;
	int local_rank;
	int final_rank ;
	int location_number;
	int score;
}temp;
std::vector<tests> testees;
bool cmp(tests &a,tests &b){
	if(a.score!=b.score)
		return a.score > b.score;
	std::string s1 = a.id,s2 = b.id;
	int k =a.id.compare(b.id) ; 
	return k<0;
}
void calculatelocarank(std::vector<tests>::iterator start, std::vector<tests>::iterator finish){
	for(int i = 0;start+i!=finish;++i){
		if(i == 0) {
			++i;
			if(start+i==finish)
				return;
		}
		if((start+i)->score == (start+i-1)->score )
			(start+i)->local_rank= (start+i-1)->local_rank;
		else
			(start+i)->local_rank = i;
	}
	return;
}
void calulatefinal_rank (std::vector<tests>::iterator start, std::vector<tests>::iterator finish){
	for(int i = 0;start+i!=finish;++i){
		if(i == 0){
			++i;
			if(start+i==finish)
				return;
		}
		if((start+i)->score == (start+i-1)->score )
			(start+i)->final_rank = (start+i-1)->final_rank ;
		else
			(start+i)->final_rank  = i;
	}
	return;
}
int main(){
	int locations,persons,score,canditates;
	char registration_number[32];
	scanf("%d",&locations);
	for(int i = 0;i<locations;++i){
		canditates = testees.size();
		scanf("%d",&persons);
		for(int j = 0;j<persons;++j){
			scanf("%s %d",registration_number,&score);
			temp.id = std::string(registration_number);
			temp.score = score;
			temp.local_rank = 0;
			temp.final_rank = 0;
			temp.location_number = i;
			testees.push_back(temp);
		}
		sort(testees.begin()+canditates,testees.begin()+canditates+persons,cmp);
		calculatelocarank(testees.begin()+canditates,testees.begin()+canditates+persons);
	}
	sort(testees.begin(),testees.end(),cmp);
	calulatefinal_rank(testees.begin(),testees.end());
	printf("%d\n",testees.size());
	for(int i=0;i!=testees.size();++i){
		printf("%s %d %d %d\n",testees[i].id.c_str(),
			testees[i].final_rank+1,
			testees[i].location_number+1,
			testees[i].local_rank+1);
	}
	return 0;
}