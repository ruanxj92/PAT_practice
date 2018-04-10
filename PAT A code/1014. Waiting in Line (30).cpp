#include <cstdio>
#include <vector>
#include <queue>
const int start_time = 0,end_time = (17-8)*60,inf = 0x3fffffff;
struct customer{
	int transaction_time,fin_time;
}tmp;
struct window{
	std::queue<int> Q;
	int end_time,pop_time;
	window(){
		end_time = 0;//+ when push
		pop_time = 0;//+ when pop
	}
};
int main(){
	int N_windows,M_linecapacity,K_customers,Q_query,now = 0;
	std::vector<customer> incoming;
	scanf("%d %d %d %d",&N_windows,&M_linecapacity,&K_customers,&Q_query);
	for(int i = 0 ;i<K_customers;++i){
		scanf("%d",&tmp.transaction_time);
		incoming.push_back(tmp);
	}
	std::vector<window> bank(N_windows);
	int index = 0;
	for (int i = 0; i < N_windows*M_linecapacity && i < K_customers; ++i){
		bank[index%N_windows].Q.push(index);
		bank[index%N_windows].end_time+=incoming[index].transaction_time;
		if(index < N_windows)
			bank[index%N_windows].pop_time = incoming[index].transaction_time;
		incoming[index].fin_time = bank[index%N_windows].end_time;
		++index;
	}
	for (; index < K_customers; ++index){
		int id = -1,minpoptime = inf;//刚开始这里用17：00的时间，有一个数据点时间有晚于17：00，都导致过不了,改成inf就可以了
		for (int j = 0; j < N_windows; ++j){
			if(minpoptime > bank[j].pop_time){
				id = j;
				minpoptime = bank[j].pop_time;
			}
		}
		window& W = bank[id];
		W.Q.pop();
		W.Q.push(index);
		W.end_time+=incoming[index].transaction_time;
		W.pop_time+=incoming[W.Q.front()].transaction_time;
		incoming[index].fin_time = W.end_time;
	}
	for (int i = 0; i < Q_query; ++i){
		int one;
		scanf("%d",&one);
		--one;
		if(incoming[one].fin_time - incoming[one].transaction_time <end_time){
			int hh = (incoming[one].fin_time)/60+8;
			int mm = (incoming[one].fin_time)%60;
			printf("%02d:%02d\n",hh,mm);		
		}else{
			printf("Sorry\n");
		}
	}
	return 0;
}