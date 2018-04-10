#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iterator>
enum cat{sage,nobleman,foolman,smallman};
struct man{
	int ID;
	int virtue;
	int talent;
	int grade;
	cat flag;
};
bool cmp(man a,man b){
	if(a.flag!=b.flag) return a.flag < b.flag;
	else if (a.grade!=b.grade) return a.grade > b.grade;
	else if (a.virtue!=b.virtue) return a.virtue > b.virtue;
	return a.ID < b.ID;
}

int main(){
	std::vector<man> stu;
	man tmp;
	int N,L,H;
	scanf("%d %d %d",&N,&L,&H);
	for(int i = 0 ;i<N;++i){
		scanf("%d %d %d",&(tmp.ID),&(tmp.virtue),&(tmp.talent));
		tmp.grade = tmp.talent + tmp.virtue;
		if(tmp.talent>=L&&tmp.virtue>=L){
			if(tmp.talent>=H&&tmp.virtue>=H){
				tmp.flag = sage;
			}else if(tmp.virtue>=H){
				tmp.flag = nobleman;
			}else if (tmp.talent <H&&tmp.virtue<H && tmp.virtue >= tmp.talent){
				tmp.flag = foolman;
			}else
				tmp.flag = smallman;
			stu.push_back(tmp);
		}		
	}
	std::sort(stu.begin(),stu.end(),cmp);
	printf("%d\n",stu.size());
	for(std::vector<man>::iterator i =stu.begin();i!=stu.end();i++){
		printf("%d %d %d\n",i->ID,i->virtue,i->talent);
	}
	return 0;
}