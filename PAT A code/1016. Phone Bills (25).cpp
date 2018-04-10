#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1010;
int toll[25];
struct record{
	char name[25];
	int month,dd,hh,mm;
	int date;
	bool status;
}rec[maxn],temp;
bool cmp(record a,record b){
	int s = strcmp(a.name,b.name);
	if(s != 0)
		return s < 0;
	if(a.date!= b.date)
		return a.date < b.date;
}
void getans(int on,int off, int& time, int& money){
	temp = rec[on];
	while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm){
		++time;
		money += toll[temp.hh];
		temp.mm++;
		if(temp.mm >= 60){
			temp.mm = 0;
			temp.hh++;
		}
		if(temp.hh >= 24){
			temp.hh = 0;
			temp.dd++;
		}
	}
}
int main(){
	for(int i=0;i<24;++i){
		scanf("%d",&toll[i]);
	}
	int n;
	scanf("%d",&n);
	char line[10];
	for(int i = 0;i<n;++i){
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
		rec[i].date = rec[i].month*1e6+rec[i].dd*1e4+rec[i].hh*1e2+rec[i].mm;
		scanf("%s",line);
		switch(line[1]){
		case 'n':
			rec[i].status = true;
			break;
		case 'f':
			rec[i].status = false;
			break;
		}
	}
	sort(rec, rec+n,cmp);
	int on = 0 ,off,next;
	while(on < n){
		int needprint = 0;
		next = on;
		while(next<n && strcmp(rec[next].name,rec[on].name)==0){
			if(needprint == 0 && rec[next].status == true){
				needprint = 1;
			}else if(needprint == 1 && rec[next].status == false){
				needprint = 2;
			}
			next++;
		}
		if(needprint < 2){
			on = next;
			continue;
		}
		int sum = 0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next){
			while(on < next -1 
				&& !(rec[on].status == true && rec[on+1].status == false)){
				++on;
			}
			off = on+1;
			if(off == next){
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
			printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
			int time = 0,money = 0;
			getans(on,off,time,money);
			sum+=money;
			printf("%d $%.2f\n",time,money/100.0);
			on = off +1;
		}
		printf("Total amount: $%.2f\n",sum/100.0);
	}
	return 0;
}