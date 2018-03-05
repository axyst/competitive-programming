#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define X next.x
#define Y next.y
#define T next.time
using namespace std;
int t,r,c,k;
int vis[125][125][125];
char maze[125][125];
struct node
{
    int x,y,time;
};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
node in,out;
int yes(int a,int b,int c)
{
    if(maze[a][b]=='#'&&c%k!=0) return 0;
    else return 1;
}
int bfs()
{
    queue<node>q;
    in.time=0;
    vis[in.x][in.y][0]=1;
    q.push(in);
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node next;
            X=u.x+dir[i][0];
            Y=u.y+dir[i][1];
            T=u.time+1;
            //printf("%d %d\n",X,Y);
            if(X<0||X>=r||Y<0||Y>=c||!yes(X,Y,T)||vis[X][Y][T%k]) continue;
            if(X==out.x&&Y==out.y) return T;
            q.push(next);
            vis[X][Y][T%k]=1;
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&r,&c,&k);
    for(int i=0;i<r;i++) scanf("%s",&maze[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(maze[i][j]=='Y') in.x=i,in.y=j;
            if(maze[i][j]=='G') out.x=i,out.y=j;
        }
        //printf("%d %d \n%d %d\n",in.x,in.y,out.x,out.y);
    int ans=bfs();
    if(ans!=-1) printf("%d\n",ans);
    else printf("Please give me another chance!\n");
    }
    return 0;
}