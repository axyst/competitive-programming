#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//reversal edge of i is i^1
const int maxn=1005;const int INF=0x3f3f3f3f;
struct Edge
{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKarp
{
    int m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];
    void init(int n)
    {
        for (int i=0;i<n;++i)
        {
            G[i].clear();
        }
        edges.clear();
    }
    void AddEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int Maxflow(int s,int t)
    {
        int flow=0;
        while (true)
        {
            memset(a,0,sizeof(a));//a[i]:augment amount from s to i
            queue<int> Q;
            Q.push(s);
            a[s]=INF;
            while (!Q.empty())//BFS
            {
                int x=Q.front();
                Q.pop();
                for (int i=0;i<G[x].size();++i)
                {
                    Edge& e=edges[G[x][i]];
                    if (!a[e.to]&&e.cap>e.flow)
                    {
                        p[e.to]=G[x][i];//p[i]:the arc to i
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t])
                {
                    break;
                }
            }
            if (!a[t])//no augmenting path
            {
                break;
            }
            for (int u=t;u!=s;u=edges[p[u]].from)//augment once
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};
int num[55][55];
int a[55];int b[55];
int main()
{
    //freopen("test.txt","r",stdin);
    int t,r,c;scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        printf("Matrix %d\n",ks);
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++) scanf("%d",a+i);
        for(int i=1;i<=c;i++) scanf("%d",b+i);
        a[0]=b[0]=0;

        EdmondsKarp ek;ek.init(r+c+2);
        for(int i=1;i<=r;i++) ek.AddEdge(0,i,a[i]-a[i-1]-c);
        for(int i=1;i<=c;i++) ek.AddEdge(i+r,r+c+1,b[i]-b[i-1]-r);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                ek.AddEdge(i,j+r,19);
                num[i][j]=ek.edges.size()-2;
            }
        int cnt=1;
        ek.Maxflow(0,r+c+1);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
                printf("%d ",ek.edges[num[i][j]].flow+1);
            printf("\n");
        }
        if(ks!=t) printf("\n");
    }
    return 0;
}