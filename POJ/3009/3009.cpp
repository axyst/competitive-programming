#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
const int M=410;
using namespace std;
int sx,sy,wi,hi,mi;
int pic[21][21];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,int t)
{
    if(t>=10) return;
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(pic[nx][ny]==1) continue;
        while(!pic[nx][ny])
        {
            nx+=dir[i][0];
            ny+=dir[i][1];
        }
        //printf("%d %d %d %d\n",nx,ny,hi,wi);
        if(nx>=0&&nx<hi&&ny>=0&&ny<wi)
        {
            //printf("%d %d\n",nx,ny);
            if(pic[nx][ny]==1)
            {
                pic[nx][ny]=0;
                dfs(nx-dir[i][0],ny-dir[i][1],t+1);
                pic[nx][ny]=1;
            }
            if(pic[nx][ny]==3)
                if(t+1<mi) mi=t+1;
        }
    }
}
int main()
{
    int t1,t2;
    while(scanf("%d%d",&t1,&t2)!=EOF)
    {
        if(t1==0&&t2==0) break;
        wi=t1,hi=t2;
        memset(pic,1,sizeof(pic));
        for(int i=0;i<hi;i++)
            for(int j=0;j<wi;j++)
            {
                scanf("%d",&pic[i][j]);
                //printf("%d",pic[i][j]);
                if(pic[i][j]==2) {pic[i][j]=0;sx=i;sy=j;}
            }
        mi=M;
        //printf("%d %d\n",hi,wi);
        dfs(sx,sy,0);
        //printf("%d\n",mi);
        if(mi<M) printf("%d\n",mi);
        else printf("-1\n");
    }
    return 0;
}