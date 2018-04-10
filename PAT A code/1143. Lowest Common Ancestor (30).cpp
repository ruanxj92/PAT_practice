#include <bits/stdc++.h>  
using namespace std;  
struct XX{  
    int val,l,r;  
}a[1000 000];  
map<int,int>vis;  
void build(int root,int id)  
{  
    if (a[id].val < a[root].val) //left  
    {  
        if (a[root].l == -1) a[root].l = id;  
        else build(a[root].l,id);  
    }  
    else //right  
    {  
        if (a[root].r == -1) a[root].r = id;  
        else build(a[root].r,id);  
    }  
}  
int main()  
{  
    vis.clear();  
    int pp,n;
	scanf("%d%d",&pp,&n); 
	scanf("%d",&a[0].val);
	a[0].l=a[0].r=-1;
	vis[a[0].val] = 1;  
    for (int i=1;i<n;i++)  
    {  
        scanf("%d",&a[i].val);  
        vis[a[i].val] = 1;  
        a[i].l = a[i].r = -1;  
        build(0,i);  
    }  
    int x,y,root;  
    while (pp--)  
    {  
        scanf("%d%d",&x,&y);  
        if (!vis[x] && !vis[y])  
        {  
            printf("ERROR: %d and %d are not found.",x,y);  
        }  
        else  
        if (!vis[x])  
        {  
            printf("ERROR: %d is not found.",x);  
        }  
        else  
        if (!vis[y])  
        {  
            printf("ERROR: %d is not found.",y);  
        }  
        else  
        {  
            root = 0;  
            while (root != -1)  
            {  
                if (a[root].val == x) break;  
                if (a[root].val == y) break;  
                if (x<a[root].val && y<a[root].val)  
                    root = a[root].l;  
                else  
                if (x>=a[root].val && y>=a[root].val)  
                    root = a[root].r;  
                else  
                    break;  
            }  
            if (a[root].val == x) printf("%d is an ancestor of %d.",x,y);else  
            if (a[root].val == y) printf("%d is an ancestor of %d.",y,x);else  
            printf("LCA of %d and %d is %d.",x,y,a[root].val);  
        }  
        puts("");  
    }  
    return 0;  
}  