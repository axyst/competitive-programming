#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
int m,n;
char map[101][101];
int dir[8][2]={{1,0},{1,-1},{1,1},{0,-1},{0,1},{-1,0},{-1,-1},{-1,1}};
void dfs(int x,int y)
{
    int nx,ny;
    for(int i=0;i<8;i++)
    {
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(0<=nx&&nx<n&&0<=ny&&ny<m&&map[nx][ny]=='@')
        {
            map[nx][ny]='*';
            dfs(nx,ny);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    getchar();
    if(m==0&&n==0) return 0;
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++) scanf("%c",&map[i][j]);
        getchar();
        }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(map[i][j]=='@')
        {
            map[i][j]='*';
            ans++;
            dfs(i,j);
        }
    printf("%d\n",ans);
    }
}