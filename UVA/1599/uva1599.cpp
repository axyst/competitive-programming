/*
这题写了一万年，一开始TLE，后来RE，不知道为什么会错，和网上的代码对过了写的都差不多
没办法只好照别人的重写一遍
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int n,m;int cnt=0;
vector<int>g[maxn];
vector<int>c[maxn];
int vis[maxn],d[maxn],ans[maxn];
void getd()
{
    memset(d,-1,sizeof(d));
    queue<int>q;d[n]=0;q.push(n);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        int sz=g[u].size();
        for(int i=0;i<sz;i++)
        {
            int v=g[u][i];
            if(v==1)
            {
                d[1]=d[u]+1;
                return;
            }
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void bfs()
{
    memset(vis,0,sizeof(vis));
    queue<int>q;q.push(1);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(d[u]==0) return;
        int sz=g[u].size();int cc=-1;
        for(int i=0;i<sz;i++)
        {
            int v=g[u][i];
            if(d[v]==d[u]-1)
            {
                if(cc==-1) cc=c[u][i];
                else cc=min(cc,c[u][i]);
            }
        }
        int dep=d[1]-d[u];
        if(ans[dep]==0) ans[dep]=cc;
        else ans[dep]=min(ans[dep],cc);
        for(int i=0;i<sz;i++)
        {
            int v=g[u][i];
            if(!vis[v]&&d[v]==d[u]-1&&c[u][i]==cc)
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<=n;i++) g[i].clear();
        for(int i=0;i<=n;i++) c[i].clear();
        int a,b,t;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&t);
            g[a].push_back(b);
            g[b].push_back(a);
            c[a].push_back(t);
            c[b].push_back(t);
        }
        getd();
        bfs();
        printf("%d\n%d",d[1],ans[0]);
        for(int i=1;i<d[1];i++) printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
