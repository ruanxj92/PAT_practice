#include <cstdio>
#include <algorithm>
const int maxn = 10001;
struct node{
	int id,members,M_estate,Area;
	float AVG_sets,AVG_area;
	node(){
		id = maxn;
		members = 1;
		M_estate=0;
		Area=0;
		AVG_sets = 0;
		AVG_area = 0;
	}
	bool operator<(node next){
		if(id == maxn) return false;
		if(AVG_area != next.AVG_area){
			return AVG_area > next.AVG_area;
		}else return id < next.id;
	}
}family[maxn];
int root[maxn];
int findroot(int x){
	int rt = x;
	while(rt!=root[rt]){
		rt = root[rt];
	}
	while(x!=root[x]){
		int tmp = x;
		x = root[x];
		root[tmp] = rt;
	}
	return rt;
}
void merge(int a,int b){//并查集是合并根节点
	int rta = findroot(a);
	int rtb = findroot(b);
	if(rta<rtb){
		root[rtb] = rta;//前后都是父节点，根节点
	}else if(rtb<rta){
		root[rta] = rtb;
	}
	return;
}
int main(){
	for(int i = 0;i<maxn;++i){
		root[i] = i;
	}
	int n;
	scanf("%d",&n);
	int ID, Father, Mother, k, Child;
	for(int i = 0;i<n;++i){
		scanf("%d%d%d%d",&ID,&Father,&Mother,&k);
		family[ID].id = ID;
		if(Father!=-1){
			family[Father].id = Father;
			merge(ID,Father);
		}
		if(Mother!=-1){
			family[Mother].id = Mother;
			merge(ID,Mother);
		}
		for(int j= 0;j<k;++j){
			scanf("%d",&Child);
			family[Child].id = Child;
			merge(ID,Child);
		}
		int M_estate, Area;
		scanf("%d %d",&M_estate,&Area);
		family[ID].M_estate = M_estate;
		family[ID].Area = Area;		
	}
	int count=0;
	for(int i = 0;i<maxn;++i){
		if(family[i].id!=maxn){
			findroot(i);
		}
	}
	for(int i = 0;i<maxn;++i){
		if(family[i].id!=maxn){
			int rt = findroot(i);
			if(rt!=i){
				family[rt].members++;
				family[rt].M_estate+=family[i].M_estate;
				family[rt].Area+=family[i].Area;
			}else if(family[i].id == i){
				count++;
			}
		}
	}
	for(int i = 0;i<maxn;++i){
		if(family[i].id == i && root[i] == i){
			family[i].AVG_area = (float)family[i].Area/family[i].members;
			family[i].AVG_sets = (float)family[i].M_estate/family[i].members;
		}
	}
	std::sort(family,family+maxn);
	printf("%d\n",count);
	for(int i = 0;i<count;++i){
		printf("%04d %d %.3f %.3f\n", family[i].id,family[i].members,family[i].AVG_sets,family[i].AVG_area);
	}
	return 0;
}