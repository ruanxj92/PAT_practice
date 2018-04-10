#include <cstdio>
#include <vector>
#include <algorithm>
bool insert_sort(std::vector<int> a,const std::vector<int> &final){
	bool same =false;
	int pmin = 0,len = a.size(),j;
	int min;
	for(int i = 1;i<len;++i){
		if(i!=1 && a == final){
			same = true;
		}
		min = a[i];
		j = i;
		while(j>0 && a[j-1] > min){
			a[j] = a[j-1];
			--j;
		}
		a[j] = min;
		if(same){
			printf("Insertion Sort\n");
			for(int i =0;i<len;++i){
				if(i) printf(" ");
				printf("%d",a[i]);
			}
			printf("\n");
			return true;
		}
	}
	return false;
}
void merge_sort(std::vector<int> a,const std::vector<int> &final){
	bool same = false;
	int len = a.size();
	for(int step = 2;step/2 <=len;step*=2){
		if(step !=2 && a == final){
			same = true;
		}
		for(int i = 0;i<len;i+=step){
			std::sort(a.begin()+i,a.begin()+std::min(i+step,len));
		}
		if(same){
			printf("Merge Sort\n");
			for(int i =0;i<len;++i){
				if(i) printf(" ");
				printf("%d",a[i]);
			}
			printf("\n");
			return;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int> origin(n,0),final(n,0);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&origin[i]);
	}
	std::vector<int> origin2 = origin;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&final[i]);
	}
	if(!insert_sort(origin,final))
		merge_sort(origin2,final);
	return 0;
}