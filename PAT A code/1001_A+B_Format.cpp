#include <cstdio>
#include <cmath>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int c = a + b;
	int absc = std::abs(c);
	if(absc>999999)
		printf("%d,%03d,%03d",c/1000000,absc/1000%1000,absc%1000);
	else if(absc>999)
		printf("%d,%03d",c/1000,absc%1000);
	else
		printf("%d",c);
	return 0;
}
/*
查看提交

评测结果

时间	结果	得分	题目	语言	用时(ms)	内存(kB)	用户
8月25日 16:25	答案正确	20	1001	C++ (g++ 4.7.2)	8	384	simonruan92
测试点

测试点	结果	用时(ms)	内存(kB)	得分/满分
0	答案正确	6	244	9/9
1	答案正确	3	384	1/1
10	答案正确	6	384	1/1
11	答案正确	7	384	1/1
2	答案正确	8	384	1/1
3	答案正确	6	384	1/1
4	答案正确	8	384	1/1
5	答案正确	7	384	1/1
6	答案正确	3	384	1/1
7	答案正确	6	384	1/1
8	答案正确	7	384	1/1
9	答案正确	3	380	1/1

https://www.patest.cn/submissions/3488014
*/