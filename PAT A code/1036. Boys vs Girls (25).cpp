#include <cstdio>
#include <cstring>
const int length = 16;
int main(){
	struct student{
		char name[length];
		char gender;
		char ID[length];
		int grade;
		student(){
			gender = 'A';
		}
	}temp,highgirl,lowboy;
	highgirl.grade = -1;
	lowboy.grade = 101;
	int n ;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.ID,&temp.grade);
		switch(temp.gender){
		case 'M':
			if(temp.grade < lowboy.grade)
				lowboy = temp;
			break;
		case 'F':
			if(temp.grade > highgirl.grade)
				highgirl = temp;
			break;
		}
	}
	if(highgirl.gender == 'F')
		printf("%s %s\n",highgirl.name,highgirl.ID);
	else 
		printf("Absent\n");
	if (lowboy.gender == 'M')
		printf("%s %s\n",lowboy.name,lowboy.ID);
	else 
		printf("Absent\n");
	if(highgirl.gender =='F' && lowboy.gender =='M')
		printf("%d",highgirl.grade - lowboy.grade);
	else
		printf("NA");
	return 0;
}