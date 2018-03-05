#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1000+5;
const int mod=1e9+7;
int cnt,n,t;
int head[maxn];int d[maxn];int vis[maxn];
struct Edge
{
    int to;int next;int weight;
}edges[maxn*2];
void insert(int from,int to,int weight)
{
    edges[cnt].to=to;
    edges[cnt].weight=weight;
    edges[cnt].next=head[from];
    head[from]=cnt++;
}
struct HeapNode
{
    int dis;int id;
    HeapNode(int d,int i){dis=d;id=i;}
    bool operator <(const HeapNode &rhs) const
    {
        return dis>rhs.dis;
    }
};
void Dijkstra(int s)
{
    priority_queue<HeapNode> q;
    d[s]=0;
    q.push(HeapNode(0,s));
    while(!q.empty())
    {
        HeapNode tp=q.top();q.pop();
        int id=tp.id;if(vis[id]) continue;
        vis[id]=1;
        for(int i=head[id];i;i=edges[i].next)
        {
            int to=edges[i].to;
            if(d[to]>d[id]+edges[i].weight)
            {
                d[to]=d[id]+edges[i].weight;
                q.push(HeapNode(d[to],to));
            }
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int a,b,c;
    while(~scanf("%d%d",&t,&n))
    {
        cnt=1;
        memset(head,0,sizeof(head));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<=n;i++) d[i]=INF;
        for(int i=0;i<t;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            insert(a,b,c);
            insert(b,a,c);
        }
        Dijkstra(1);
        printf("%d\n",d[n]);
    }
    return 0;
}
