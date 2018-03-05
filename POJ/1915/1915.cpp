#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define X next.x
#define Y next.y
using namespace std;
int vis[350][350];
//int pic[350][350];
struct node
{
    int x,y,time;
};
node dir[8]={-2,1,0,-1,2,0,1,2,0,2,1,0,2,-1,0,1,-2,0,-1,-2,0,-2,-1,0};
node def={0,0,0};
node out={0,0,0};
int l;
int bfs()
{
    queue<node>q;
    vis[def.x][def.y]=1;
    q.push(def);
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(u.x==out.x&&u.y==out.y) return u.time;
        else for(int i=0;i<8;i++)
        {
            node next;
            X=u.x+dir[i].x;
            Y=u.y+dir[i].y;
            if(X<0||X>=l||Y<0||Y>=l) continue;
            if(!vis[X][Y])
            {
                next.time=u.time+1;
                q.push(next);
                vis[X][Y]=1;
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    memset(vis,0,sizeof(vis));
    scanf("%d",&l);
    scanf("%d%d",&def.x,&def.y);
    scanf("%d%d",&out.x,&out.y);
    printf("%d\n",bfs());
    }
    return 0;
}