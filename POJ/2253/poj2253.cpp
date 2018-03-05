#include<cstdio>
#include<cstdlib>
#include<cmath>
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
const int maxn=1e6+5;
const int mod=1e9+7;
int cnt,n;
int head[maxn];double d[maxn];int vis[maxn];
int x[maxn];int y[maxn];
double length(int a,int b)
{
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
struct Edge
{
    int to;int next;double weight;
}edges[maxn*2];
void insert(int from,int to,double weight)
{
    edges[cnt].to=to;
    edges[cnt].weight=weight;
    edges[cnt].next=head[from];
    head[from]=cnt++;
}
struct HeapNode
{
    double dis;int id;
    HeapNode(double d,int i){dis=d;id=i;}
    bool operator <(const HeapNode &rhs) const
    {
        return dis>rhs.dis;
    }
};
void Dijkstra(int s)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++) d[i]=INF;
    priority_queue<HeapNode> q;
    d[s]=0;
    q.push(HeapNode(0.0,s));
    while(!q.empty())
    {
        HeapNode tp=q.top();q.pop();
        int id=tp.id;if(vis[id]) continue;
        vis[id]=1;
        for(int i=head[id];i;i=edges[i].next)
        {
            int to=edges[i].to;
            //cout<<"to"<<to<<endl;
            if(d[to]>max(d[id],edges[i].weight))
            {
                d[to]=max(d[id],edges[i].weight);
                q.push(HeapNode(d[to],to));
            }
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int ks=1;
    while(~scanf("%d",&n)&&n)
    {
        cnt=1;
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",x+i,y+i);
            for(int j=1;j<i;j++)
            {
                double wei=length(i,j);
                insert(i,j,wei);
                insert(j,i,wei);
            }
        }
        Dijkstra(1);
        //for(int i=1;i<=n;i++)cout<<"di"<<i<<' '<<d[i]<<endl;
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",ks++,sqrt(d[2]));
    }
    return 0;
}
