#include<cstdio>  
#include<cmath>  
long int n;  
int IsPrimer(long n){  
    int i;  
    for(i=2;i*i<=n;i++)  
        if(n%i==0) return 0;  
    return 1;  
}  
int main(){  
    scanf("%ld",&n);  
    printf("%d=",n);  
    if(n==1) printf("%ld\n",n);  
    else{  
        int i,tmp = n;  
        for(i=2;i<=tmp;i++){  
            int k=0;  
            if(IsPrimer(i)){  
                while(n%i==0){  
                    k++;  
                    n=n/i;  
                }  
            }  
            if(k>1){  
                printf("%d^%d",i,k);  
            }  
            else if(k==1) printf("%d",i);  
            if(n!=1&&k>=1) printf("*");  
            else if(n==1) break;  
        }  
    }  
    printf("\n");  
    return 0;  
}  
/*
д��AC֮��Ļ���
��������ʱ��������ŷ��ɸԤ�Ȱ��������ӡ������Ȼ�����������ÿһ��ָ�������������С��ģ��ʱ��ܺã�����ģ����ʱ������ڴ泬�ޡ����������Ǵ�������ռ����̫��ռ䡣
֮���������ҵķ�����ֻ��һ���ж������ĺ�������������ÿһ��������ָ������������Ǵ�С��ģ���ܺá�����ŵ����ڴ�ռ��С������򵥣��㷨��ʵ�֡�
�ܽ᣺�������������������������㷨�ĸ��Ӷȡ���ʱ��Ϳռ临�Ӷ����ҵ�����ʵķ���������õġ�
*/