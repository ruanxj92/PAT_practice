/*书上给的选择队伍的方式是找到队伍中处理完当前业务时间最早的。、
而一般常见的选择方式是在顾客到达时选择人数最少的队伍，同样的队伍选择最前的，
	*/
#include <cstdio>
#include <algorithm>
#include <vector>
const int endtime = 17*3600,start_time = 8*3600;
struct costumer{
	int in,duration;
	costumer(const int &_in, const int &_dura){
		in = _in;
		duration =_dura;
	}
	bool operator<(const costumer &a){
		return in < a.in;
	}
};
int main(){
	int N_costumers,K_windows,hh,mm,ss,time,duration,served = 0;
	std::vector<costumer> waiting_line;
	scanf("%d %d",&N_costumers,&K_windows);
	for (int i = 0; i < N_costumers; ++i){
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&duration);
		time = ss+mm*60+hh*3600;
		duration*=60;
		if(time <= endtime)
			waiting_line.push_back(costumer(time,duration));
	}
	std::sort(waiting_line.begin(), waiting_line.end());
	std::vector<int> window(K_windows,start_time);
	double total_taittime = 0;
	for(auto cur = waiting_line.begin();cur!=waiting_line.end();cur++){
		int id = -1,minfintime = endtime*2;
		for (int i = 0; i < window.size(); ++i){
			if(window[i]<minfintime){//need more consideration
				id = i;
				minfintime = window[i];
			}
		}
		if(id == -1){
			continue;
		}
		served++;
		if(window[id]>cur->in){//come too early, have to wait;
			total_taittime += window[id] - cur->in;
			window[id] += cur->duration;
		}else{//come and serve
			window[id] = cur->in+cur->duration;
		}
	}
	if(served)
		printf("%.1lf\n", total_taittime/60/served);
	else
		printf("0.0\n");
	return 0;
}