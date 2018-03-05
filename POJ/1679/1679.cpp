#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=105;
bool vis[MAXN],used[MAXN][MAXN];
int low[MAXN],pre[MAXN],ma[MAXN][MAXN],edge[MAXN][MAXN];
int ans;
int Prim(int cost[][MAXN],int n)
{
    int ret=0;
    memset(vis,0,sizeof(vis));
    memset(ma,0,sizeof(ma));
    memset(used,0,sizeof(used));
    vis[1]=1;
    pre[1]=-1;
    for(int i=2;i<=n;i++)
    {
        low[i]=cost[1][i];
        pre[i]=1;
    }
    low[1]=0;
    for(int i=2;i<=n;i++)
    {
        int mi=INF;
        int p=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&mi>low[j])
            {
                mi=low[j];
                p=j;
            }
        if(mi==INF) return -1;
        ret+=mi;
        vis[p]=1;
        used[p][pre[p]]=used[pre[p]][p]=1;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]) ma[j][p]=ma[p][j]=max(ma[j][pre[p]],low[p]);
            if(!vis[j]&&low[j]>cost[p][j])
            {
                low[j]=cost[p][j];
                pre[j]=p;
            }
        }
    }
    return ret;
}
int smst(int cost[][MAXN],int n)
{
    int mi=INF;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(cost[i][j]!=INF&&!used[i][j])
                mi=min(mi,ans+cost[i][j]-ma[i][j]);
    if(mi==INF) return -1;
    return mi;
}
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        int u,v,w;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                edge[i][j]=(i==j?0:INF);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u][v]=edge[v][u]=w;
        }
        ans=Prim(edge,n);
        if(ans==-1)
        {
            printf("Not Unique!\n");
            continue;
        }
        if(ans==smst(edge,n))printf("Not Unique!\n");
        else printf("%d\n",ans);
    }
    return 0;
}