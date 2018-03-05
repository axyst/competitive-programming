#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define X next.x
#define Y next.y
#define nextmove (maze[next.x][next.y])
using namespace std;
int n,m,t;
bool vis[25][25][1050];
char maze[25][25];
struct node
{
    int x,y,time,key;
}def;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int bfs()
{
    queue<node>q;
    def.key=0,def.time=0;
    vis[def.x][def.y][0]=1;
    q.push(def);
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(u.time%t==0&&u.time!=0)
        {
            u.x=def.x;
            u.y=def.y;
        }
        if(maze[u.x][u.y]=='^') return u.time;
        for(int i=0;i<4;i++)
        {
            node next;
            X=u.x+dir[i][0];
            Y=u.y+dir[i][1];
            next.key=u.key;
            if(X<0||X>=n||Y<0||Y>=m||nextmove=='*'||vis[X][Y][next.key]) continue;
            next.time=u.time+1;
            if(nextmove>='a'&&nextmove<='j')
            {
                int num=nextmove-'a';
                if(!(u.key&(1<<num)))
                    next.key=u.key+(1<<num);//用二进制储存key
            }
            if(nextmove>='A'&&nextmove<='J')
            {
                int num=nextmove-'A';
                int tem=u.key>>num;
                if(!(tem&1)) continue;
                next.key=u.key;
            }
            vis[X][Y][next.key]=1;
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) scanf("%s",&maze[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(maze[i][j]=='@'){def.x=i,def.y=j;break;}
    int ans=bfs();
    printf("%d\n",ans);
    }
    return 0;
}