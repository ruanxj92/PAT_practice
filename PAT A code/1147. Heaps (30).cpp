#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void postorder(const vector<int> &a,int pos){
	if(pos>=a.size()) return;
	postorder(a,2*pos+1);
	postorder(a,2*pos+2);
	cout << a[pos];
	if(pos) cout << ' ';
	else cout << '\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n;
	cin >> m >> n;
	vector<int> ori(n),trans;
	while(m--){
		for(int i = 0;i<n;++i){
			cin >> ori[i];
		}
		trans = ori;
		make_heap(trans.begin(),trans.end());
		if(trans == ori) {
			cout << "Max Heap\n";
		}else {
			make_heap(trans.begin(),trans.end(),greater<int>());
			if(trans == ori){
				cout << "Min Heap\n";
			}else{
				cout << "Not Heap\n";
			}
		}
		postorder(ori,0);
	}
	return 0;
}