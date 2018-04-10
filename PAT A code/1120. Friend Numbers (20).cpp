#include <cstdio>
#include <vector>
int friendid(int data){
	int n = 0;
	while(data!=0){
		n+=data%10;
		data/=10;
	}
	return n;
}
int main(){
	const int maxn = 1e4+1;
	 std::vector<int> hash(maxn,0);
	 int n,tmp;
	 scanf("%d",&n);
	 for(int i = 0;i<n;++i){
	 	scanf("%d",&tmp);
	 	hash[friendid(tmp)] = 1;
	 }
	 std::vector<int> ans;
	 for(int i = 0;i<maxn;++i){
	 	if(hash[i]){
	 		ans.push_back(i);
	 	}
	 }
	 printf("%d\n",ans.size());
	 for (int i = 0; i < ans.size(); ++i){
	 	if(i) printf(" ");
	 	printf("%d",ans[i]);
	 }
	 return 0;
}