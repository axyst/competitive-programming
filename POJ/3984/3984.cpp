#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int maze[10][10];
int vis[10][10];
int cnt=0;
struct node
{
    int x,y;
};
node dir[4]={{1,0},{0,1},{-1,0},{0,-1}};
node rec[10][10],ans[30];
void bfs()
{
    queue<node>q;
    node def;
    def.x=0,def.y=0;
    vis[0][0]=1;
    q.push(def);
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(u.x==4&&u.y==4) return;
        else for(int i=0;i<4;i++)
        {
            node next;
            next.x=u.x+dir[i].x;
            next.y=u.y+dir[i].y;
            if(next.x>=0&&next.x<5&&next.y>=0&&next.y<5&&!vis[next.x][next.y]&&!maze[next.x][next.y])
            {
            rec[next.x][next.y].x=u.x;
            rec[next.x][next.y].y=u.y;
            vis[next.x][next.y]=1;
            q.push(next);
            }
        }
    }
}
void print()
{
    int x=4,y=4;
    for(;x!=0||y!=0;cnt++)//回溯到左上角
    {
        ans[cnt].x=x;
        ans[cnt].y=y;
        node tem=rec[x][y];
        x=tem.x;
        y=tem.y;
    }
}
int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&maze[i][j]);
    memset(vis,0,sizeof(vis));
    bfs();
    print();
    for(int i=cnt;i>=0;i--)
        printf("(%d, %d)\n",ans[i].x,ans[i].y);
    return 0;
}