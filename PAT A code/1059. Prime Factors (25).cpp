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
写在AC之后的话：
做这道题的时候，先是用欧拉筛预先吧素数表打印出来，然后尝试逐个计算每一个指数。结果发现在小规模的时候很好，当规模变大的时候出现内存超限。分析结论是存素数表占用了太多空间。
之后在网上找的方法是只用一个判断素数的函数来辅助计算每一个因数的指数，结果不管是大小规模都很好。这个优点是内存占用小，代码简单，算法易实现。
总结：具体问题具体分析，不用迷恋算法的复杂度。在时间和空间复杂度上找到最合适的方法才是最好的。
*/