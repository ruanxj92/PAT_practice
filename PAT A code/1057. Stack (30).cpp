#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
const int sqrN = 316;
const int maxN = 1e5+1;
std::stack<int> st;
char opstring[] = {"PeekMedian"};
int block[sqrN] = {0};
int table[maxN] = {0};
void pop(){
	if(st.empty()) {
		printf("Invalid\n");
		return;
	}
	printf("%d\n",st.top());
	--table[st.top()];
	--block[st.top()/sqrN];
	st.pop();
	return;
}
void push(){
	int n;
	scanf("%d",&n);
	st.push(n);
	++table[n];
	++block[n/sqrN];
	return;
}
void peek(){	
	if(st.empty()) {
		printf("Invalid\n");
		return;
	}
	int K = st.size();
	if(K%2) K = (K+1)/2;
	else K/=2;
	int sum = 0;
	int idx = 0;
	while(sum + block[idx] < K)		sum+=block[idx++];//核心代码，区块和区块号
	int num = idx *sqrN;//
	while(sum + table[num] < K)		sum+=table[num++];//区块内号码
	printf("%d\n",num);//
}
int main(){
	int num;
	scanf("%d",&num);
	for(int i = 0;i<num;++i){
		char op;
		scanf("%s",opstring);
		op = opstring[1];
		switch (op){
		case 'o'://pop
			pop();
			break;
		case 'u'://push
			push();
			break;
		case 'e'://peekmedian
			peek();
			break;
		}
	}
	return 0;
}
/*
1057. Stack (30)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid

*/