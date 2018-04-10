#include<vector>
#include<cstdio>
#include<algorithm>
int n,k,p,maxfacsum = -1;
std::vector<int> fac,ans,temp;
int fastpower(int a,int b){
	int ans=1,c=a;
    while(b!=0){
        if((b&1)!=0)
			ans*=c;
        c*=c;
        b>>=1;
	}
    return ans;
}
int power(int x){
	return fastpower(x,p);
}
void init(){
	int i = 0,temp = 0;
	while(temp<=n){
		fac.push_back(temp);
		temp = power(++i);
	}
}
void DFS(int index ,int nowk,int sum,int facsum){
	if(sum == n&&nowk == k){// success
		if(facsum > maxfacsum){
			ans = temp;
			maxfacsum = facsum;
		}
		return;
	}
	if(sum>n ||nowk >k) return;//fail
	if(index > 0){//try a new case
		temp.push_back(index);
		DFS(index,nowk + 1,sum+fac[index],facsum+index);
		temp.pop_back();
		DFS(index - 1,nowk,sum,facsum);
	}
}
int main(){
	scanf("%d %d %d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(maxfacsum == -1) 
		printf("Impossible");
	else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i = 1;i<ans.size();++i)
			printf(" + %d^%d",ans[i],p);
	}
		printf("\n");
	return 0;
}