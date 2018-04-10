#include<cstdio>
#include<queue>
const int maxm=1287,maxn=129,maxl=61;
struct Node{
    int x,y,z;
}node;
int n,m,slice,t;
int pixel[maxm][maxn][maxl]={-1};
bool inq[maxm][maxn][maxl] = {false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int &x,int &y,int &z){
    if(x>=n || x<0 ||y>=m || y<0 ||z>=slice || z<0)
        return false;
    if(pixel[x][y][z] == 0 ||inq[x][y][z]==true) return false;
    return true;
}
int bfs(int &x,int &y,int &z){
    int count = 0;
    int tot = 0;
    std::queue<Node> q;
    node.x = x,node.y = y,node.z = z;
    q.push(node);
    inq[x][y][z] = true;
    int newx,newy,newz;
    while(!q.empty()){
        Node top = q.front();
        ++tot;
        q.pop();
        for(int i = 0;i<6;++i){
            newx = top.x + X[i],newy = top.y + Y[i],newz = top.z + Z[i];
            if(judge(newx,newy,newz)){
                node.x = newx,node.y = newy,node.z = newz;
                q.push(node);inq[newx][newy][newz] = true;
            }
        }
    }
    if(tot >=t) return tot;
    else return 0;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&slice,&t);
    for(int z = 0;z<slice;++z){
        for(int x = 0;x<n;++x){
            for(int y = 0;y<m;++y){
                scanf("%d",&pixel[x][y][z]);
            }
        }
    }
    int ans = 0;
    for(int z = 0;z<slice;++z){
        for(int x = 0;x<n;++x){
            for(int y = 0;y<m;++y){
                if(pixel[x][y][z]==1&&inq[x][y][z]==false){
                    ans+=bfs(x,y,z);
                }
            }
        }
    }    
    printf("%d\n",ans);
	return 0;
}