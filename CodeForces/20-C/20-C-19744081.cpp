#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=100005;
const int MAXM=200005;
const LL INF=1e18;
int n,m;
int parent[MAXN],vis[MAXN],head[MAXM];
LL d[MAXN];
struct Edge
{
    int u;
    int v;
    int w;
}edge[MAXM];
void Print(int a)
{
    if(parent[a]==-1)
    {
        printf("%d",a);
        return;
    }
    Print(parent[a]);
    printf(" %d",a);
}
void Spfa()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;i++) d[i]=INF;
    parent[1]=-1,d[1]=0,vis[1]=1;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i!=-1;i=edge[i].v)
        {
            int j=edge[i].u;
            if(d[j]>d[x]+edge[i].w)
            {
                parent[j]=x;
                d[j]=d[x]+edge[i].w;
                if(!vis[j])
                {
                    vis[j]=1;
                    q.push(j);
                }
            }
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int a,b,cnt=0;
    LL c;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%I64d",&a,&b,&c);
        edge[cnt].u=b,edge[cnt].v=head[a],edge[cnt].w=c,head[a]=cnt++;
        edge[cnt].u=a,edge[cnt].v=head[b],edge[cnt].w=c,head[b]=cnt++;
    }
    Spfa();
    if(d[n]==INF) printf("-1");
    else Print(n);
    printf("\n");
    return 0;
}