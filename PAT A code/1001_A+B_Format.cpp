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
�鿴�ύ

������

ʱ��	���	�÷�	��Ŀ	����	��ʱ(ms)	�ڴ�(kB)	�û�
8��25�� 16:25	����ȷ	20	1001	C++ (g++ 4.7.2)	8	384	simonruan92
���Ե�

���Ե�	���	��ʱ(ms)	�ڴ�(kB)	�÷�/����
0	����ȷ	6	244	9/9
1	����ȷ	3	384	1/1
10	����ȷ	6	384	1/1
11	����ȷ	7	384	1/1
2	����ȷ	8	384	1/1
3	����ȷ	6	384	1/1
4	����ȷ	8	384	1/1
5	����ȷ	7	384	1/1
6	����ȷ	3	384	1/1
7	����ȷ	6	384	1/1
8	����ȷ	7	384	1/1
9	����ȷ	3	380	1/1

https://www.patest.cn/submissions/3488014
*/