#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
struct Person{
	std::string name;
	int height;
	bool operator<(Person another){
		if(height != another.height)
			return height > another.height;
		else
			return name < another.name;
	}
}tmperson;
int main(){
	int N_people,K_row,extra,m_column;
	scanf("%d %d",&N_people,&K_row);
	m_column = N_people/K_row;
	extra = N_people - m_column*K_row;
	std::vector<Person> person;
	for(int i = 0;i<N_people;++i){
		char name[9];
		scanf("\n%s %d",name,&tmperson.height);
		tmperson.name = name;
		person.push_back(tmperson);
	}
	sort(person.begin(), person.end());
	std::vector<std::vector<int> > position(K_row);
	position[0].assign(m_column+extra,-1);
	for(int i = 1;i<position.size();++i){
		position[i].assign(m_column,-1);
	}
	int inpos = 0;	
	for(int row = 0;row<position.size();++row){
		int mid = position[row].size()/2; 
		int pos_in_row = mid ;
		for (int i = 0; i < position[row].size(); ++i){
			if(i%2){//odd 1,3,5
				pos_in_row =  mid - (i+1)/2;
			}else{//even 0,2,4
				pos_in_row =  mid + (i+1)/2;
			}
			position[row][pos_in_row] = inpos++;
		}
	}
	for (int i = 0; i < position.size(); ++i){
		for (int j = 0; j < position[i].size(); ++j){
			if (j) printf(" ");
			printf("%s", person[position[i][j]].name.c_str());
		}
		printf("\n");
	}
	return 0;
}