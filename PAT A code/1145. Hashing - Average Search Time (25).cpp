#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
bool isprime(int a){
    if(a<2) return false;
    for(int i = 2;i*i<=a;++i){
        if(a%i==0) return false;
    }
    return true;
}
int resize(int n){
    while(!isprime(n)){
        ++n;
    }
    return n;
}
void insert(vector<int> &hashtable,int a){
    int i = 0;
    while(i<hashtable.size()){
        int pos = (a+i*i)%hashtable.size();
        if(hashtable[pos]==-1){
            hashtable[pos] = a;
            //cout << a << "is inserted in "<< pos << '\n';
            return;
        }
        ++i;
    }
    cout << a <<" cannot be inserted.\n";
}
int search(vector<int> &hashtable,int a){
    int i = 0;
    while(i<hashtable.size()){
        int pos = (a+i*i)%hashtable.size();
        if(hashtable[pos]==a){
            //cout << a << " searched in "<<pos<<" for times"<<i<<'\n';
             return ++i;
        }else if(hashtable[pos]==-1){
             return ++i;
        }
        ++i;
    } 
    return ++i;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int size,n,m;
    cin >> size >> n >> m;
    //cout << "size" << size << "n" << n<<"m" <<m << '\n';
    size = resize(size);
    vector<int> hashtable(size,-1);
    for(int i = 0;i<n;++i){
        int tmp;
        cin >> tmp;
        insert(hashtable,tmp);
    }
    int sum = 0;
    for(int i = 0;i<m;++i){
        int tmp;
        cin >> tmp;
        sum+=search(hashtable,tmp);
    }
    cout << fixed << setprecision(1) << sum*1.0/m;
    return 0;
}