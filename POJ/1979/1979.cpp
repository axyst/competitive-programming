#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
char pic[50][50];
int vis[50][50];
int cnt=0;
int h,w;
void dfs(int x,int y)
{
    if(x<0||y<0||x>=h||y>=w) return;
    if(pic[x][y]!='.'&&pic[x][y]!='@') return;
    if(vis[x][y]>9) return;
    if(vis[x][y]==0)
    {
        cnt++;
    }
    vis[x][y]++;
    for(int i=0;i<4;i++)
    {
        if(i==0) dfs(x,y+1);
        if(i==1) dfs(x,y-1);
        if(i==2) dfs(x-1,y);
        if(i==3) dfs(x+1,y);
    }
}
int main()
{
    while(scanf("%d%d",&w,&h)!=0)
    {
        if(w==0&&h==0) break;
        memset(vis,0,sizeof(vis));
        int yes=0;
        int m,n;
        for(int i=0;i<h;i++) scanf("%s",pic[i]);
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                if(pic[i][j]=='@')
                {
                    m=i,n=j;
                    yes=1;
                    break;
                }
                if(yes) break;
            }
        //vis[m][n]=1;
        dfs(m,n);
        printf("%d\n",cnt);
        cnt=0;
    }
    return 0;
}