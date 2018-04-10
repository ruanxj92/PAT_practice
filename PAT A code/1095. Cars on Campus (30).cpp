#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
struct timenode{
	int hh,mm,ss;
	bool operator <(timenode &t){
		if(hh!=t.hh)
			return hh<t.hh;
		if(mm!=t.mm)
			return mm<t.mm;
		return ss<t.ss;
	}
};
timenode tmptime;
struct rec{
	char plate_number[8];
	timenode t1;
	bool status;
	bool operator <(rec &_n){
		if(strcmp(plate_number,_n.plate_number)!=0)
			return strcmp(plate_number,_n.plate_number)<0;
		return t1<_n.t1;
	}
};
bool cmp(rec &a,rec &b){
	return a.t1<b.t1;
}
int tminus(timenode &t1,timenode &t2){
	return t1.ss-t2.ss+(t1.mm-t2.mm)*60+(t1.hh-t2.hh)*3600;
}
int main(){
	int N,K,maxtime = 0;
	scanf("%d %d",&N,&K);
	std::vector<rec> record;
	std::vector<rec> carlist;
	std::map<std::string,int> cartime;
	record.resize(N);
	char status[8];
	for(int i = 0;i<N;++i){
		scanf("%s %d:%d:%d %s",&record[i].plate_number,
			&record[i].t1.hh,&record[i].t1.mm,&record[i].t1.ss,
			status);
		switch(status[0]){
		case 'o':
			record[i].status = false;
			break;
		case 'i':
			record[i].status = true;
			break;
		}
	}
	std::sort(record.begin(),record.end());
	for(int i = 0;i!=record.size()-1;++i){
		if(!strcmp(record[i].plate_number,record[i+1].plate_number)&&
			record[i].status&&
			!record[i+1].status){
			carlist.push_back(record[i]);
			carlist.push_back(record[i+1]);
			std::string str(record[i].plate_number);
			if(cartime.find(str)==cartime.end()) 
				cartime[(record[i]).plate_number] = 0;
			int t = tminus(record[i+1].t1,record[i].t1);
			cartime[std::string(record[i].plate_number)]+=t;
			if(maxtime<cartime[std::string(record[i].plate_number)])
				maxtime = cartime[std::string(record[i].plate_number)];
		}
	}
	std::sort(carlist.begin(),carlist.end(),cmp);
	int now=0,car=0;
	for(int i = 0;i<K;++i){
		scanf("%d:%d:%d",&tmptime.hh,&tmptime.mm,&tmptime.ss);
		int tt = tmptime.hh*3600+tmptime.mm*60+tmptime.ss;
		while(now<carlist.size() && tminus(tmptime,carlist[now].t1)>=0){
			if(carlist[now].status) ++car;
			else --car;
			++now;
		}
		printf("%d\n",car);
	}
	for(auto i = cartime.begin();i!=cartime.end();++i){
		if(i->second == maxtime){
			printf("%s ",i->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
	return 0;
}