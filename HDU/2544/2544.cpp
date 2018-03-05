#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dis[105],pre[105],vis[105],nex[20005];
struct Edge
{
    int u;
    int v;
    int w;
}edge[20005];
void SPFA(int x)
{
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=pre[x];i!=-1;i=nex[i])
        {
            int y=edge[i].v;
            if(dis[y]>dis[x]+edge[i].w)
            {
                dis[y]=dis[x]+edge[i].w;
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}
int main()
{
    int n,m,a,b,c;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=1;i<=n;i++) dis[i]=(i==1?0:INF);
        memset(pre,-1,sizeof(pre));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[i].u=a;
            edge[i].v=b;
            edge[i].w=c;
            nex[i]=pre[a];
            pre[a]=i;
        }
        for(int i=1;i<=m;i++)
        {
            edge[i+m].u=edge[i].v;
            edge[i+m].v=edge[i].u;
            edge[i+m].w=edge[i].w;
            nex[i+m]=pre[edge[i].v];
            pre[edge[i].v]=i+m;
        }
        SPFA(1);
        printf("%d\n",dis[n]);
    }
    return 0;
}