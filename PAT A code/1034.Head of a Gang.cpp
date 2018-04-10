/*
1034. Head of a Gang (30)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
const int maxn = 2010;
const int inf = 1e9;

std::map<int,std::string> int2string;
std::map<std::string,int> string2int;
std::map<std::string,int> gang;//named after head
std::map<int,int> G[maxn];
int weight[maxn] = {0};

struct Gang{
	std::string head;
	int number;
}arraygang[maxn];

int gangnum = 0;
int numperson = 0,n,k;
bool vis[maxn] = {false};

void DFS(int curvisit,int &head,int &nummember,int& totalvalue){
	++nummember;
	vis[curvisit] = true;
	if(weight[curvisit] > weight[head]) head = curvisit;
	for(int i =0;i<numperson;++i){
		if(G[curvisit].find(i)!=G[curvisit].end()){
			totalvalue += G[curvisit][i];
			G[curvisit].erase(i);G[i].erase(curvisit);
			if(!vis[i]) DFS(i,head,nummember,totalvalue);
		}
	}
}
int toint(std::string str){
	if(string2int.find(str)!=string2int.end()){
		return string2int[str];
	}else{
		string2int[str] = numperson;
		int2string[numperson] = str;
		return numperson++;
	}
	return -2;
}
void DFStrave(){
	for(int i = 0;i<numperson;++i){
		if(!vis[i]){
			int head = i,nummember = 0,totalvalue = 0;
			DFS(i,head,nummember,totalvalue);
			if(nummember > 2 && totalvalue > k) gang[int2string[head]] = nummember;
		}
	}
}
bool cmp(Gang a, Gang b){
	return a.head < b.head;
}
int main(){
	int w;
	std::string str1,str2;
	std::cin >> n >> k;
	for(int i = 0;i<n;++i){
		std::cin >> str1 >> str2 >> w;
		int id1 = toint(str1);
		int id2 = toint(str2);
		weight[id1] += w;
		weight[id2] += w;
		if(G[id1].find(id2) == G[id1].end()){//not found
			G[id1][id2] = w;
		}else{
			G[id1][id2] += w;
		}		
		if(G[id2].find(id1) == G[id2].end()){//not found
			G[id2][id1] = w;
		}else{
			G[id2][id1] += w;
		}
	}
	DFStrave();
	std::cout << gang.size() << std::endl;
	for(auto i = gang.begin();i!=gang.end();++i){
		std::cout << i->first << " " <<i->second << std::endl;
	}
	return 0;
}