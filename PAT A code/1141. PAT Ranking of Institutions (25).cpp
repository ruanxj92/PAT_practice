#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int rank,ns;
	double tws;
	int itws;
    string school;
    node(){
        rank=1;
        tws=0;
        ns=0;
    }
    bool operator<(const node &a){
        if(itws<a.itws||a.itws<itws) return itws>a.itws;
        if(ns<a.ns||a.ns<ns) return ns<a.ns;
        return school<a.school;
    }
};
void tolower(string &a){
    for(int i= 0;i!=a.size();++i){
        if(a[i]>='A' && a[i]<='Z')
            a[i] += ('a'-'A');
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string id,name;
    double score;
    unordered_map<string,node> candischool;
    for(int i = 0;i<n;++i){
        cin >> id >> score >> name;
        tolower(name);
        auto p = candischool.find(name);
        if(p==candischool.end()){//new one
            candischool[name].school = name;
            p = candischool.find(name);
        }
        double weight=0;
        if(id[0]=='T') weight = score*1.5; 
        else if(id[0]=='A') weight = score;
        else weight = score/1.5;
        p->second.tws+=weight;
        p->second.ns++;
    }
    vector<node> finschool;
    for(auto i =candischool.begin();i!=candischool.end();++i){
		i->second.itws = (int)i->second.tws;
        finschool.push_back(i->second);
    }
    sort(finschool.begin(),finschool.end());
    int count = 0;
    auto prev = finschool.begin();
    cout << finschool.size()<<'\n';
    for(auto i =finschool.begin();i!=finschool.end();++i){
        count++;
        if(i!=finschool.begin()){
            if(i->itws == prev->itws) i->rank = prev->rank;
            else i->rank = count;
        }
        prev = i;
        cout << i->rank <<' '<<i->school<<' '<<i->itws<<' '<<i->ns<<'\n';
    }
    return 0;
}