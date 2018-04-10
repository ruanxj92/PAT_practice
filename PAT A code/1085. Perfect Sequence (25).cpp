/*
1085. Perfect Sequence (25)
*/
#include<cstdio>
#include<algorithm>
#include<vector>
int main1(){//binary search
    int n,p;
    std::vector<int> a;
    scanf("%d %d",&n,&p);
	a.resize(n);
    for(int i = 0;i<n;++i){
        scanf("%d",&a[i]);
    }
    std::sort(a.begin(),a.end());
    int ans = 1;
    for(int i = 0;i<n;++i){
        int j = std::upper_bound(a.begin()+i+1,a.begin()+n,(long long)a[i]*p)- a.begin();
        ans = std::max(ans,j-i);
    }
    printf("%d\n",ans);
    return 0;
}
int main(){//two pointers
	int n,p;
    std::vector<long long> a;
    scanf("%d %d",&n,&p);
	a.resize(n);
    for(int i = 0;i<n;++i){
        scanf("%d",&a[i]);
    }
    std::sort(a.begin(),a.end());
    int ans = 1;
    int i = 0,j = 0;
	while(i<n&&j<n){
		while(j<n &&a[j] <= (long long)(a[i]*p)){
			if(ans < j-i+1)
				ans = j-i+1;
			++j;
		}
		++i;
	}
	printf("%d\n",ans);    
	return 0;
}