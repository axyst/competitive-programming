#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int n,k;
int vis[100050];
struct node
{
    int x,time;
};
int bfs(int a)
{
    queue<node>q;
    node def;
    def.x=a,def.time=0;
    vis[def.x]=1;
    q.push(def);
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(u.x==k) return u.time;
        else for(int i=0;i<3;i++)
        {
            node next;
            if(i==0) next.x=u.x+1;
            else if(i==1) next.x=u.x-1;
            else if(i==2&&u.x!=0) next.x=u.x*2;
            if(next.x<0||next.x>100000) continue;
            if(!vis[next.x])
            {
                next.time=u.time+1;
                q.push(next);
                vis[next.x]=1;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d",&n,&k);
    memset(vis,0,sizeof(vis));
    if(n>=k) printf("%d\n",n-k);
    else printf("%d\n",bfs(n));
    return 0;
}