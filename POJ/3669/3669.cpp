#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define X next.x
#define Y next.y
using namespace std;
//int vis[350][350][18050];
int pic[500][500];
int dir[5][2]={{1,0},{-1,0},{0,1},{0,-1},{0,0}};
struct node
{
    int x,y,t;
};
int bfs()
{
    if(pic[0][0]==0) return -1;
    if(pic[0][0]==-1) return 0;
    queue<node>q;
    node def;
    def.x=def.y=def.t=0;
    q.push(def);
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node next;
            X=u.x+dir[i][0];
            Y=u.y+dir[i][1];
            next.t=u.t+1;
            if(X<0||X>400||Y<0||Y>400) continue;
            if(pic[X][Y]==-1) return next.t;
            if(pic[X][Y]<=next.t) continue;//被砸后
            pic[X][Y]=next.t;//被砸之前走到，标记
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    //scanf("%d",&m);
    {
        memset(pic,-1,sizeof(pic));
        while(m--)//输入时预处理
        {
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            for(int i=0;i<5;i++)
            {
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx<0||nx>400||ny<0||ny>400) continue;
                if(pic[nx][ny]==-1) pic[nx][ny]=t;
                else if(pic[nx][ny]>t) pic[nx][ny]=t;//第一次被砸到
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}