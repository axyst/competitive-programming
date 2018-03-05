#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2005;const int INF=0x3f3f3f3f;
struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];         // 是否在队列中
  int d[maxn];           // Bellman-Ford
  int p[maxn];           // 上一条弧
  int a[maxn];           // 可改进量

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BellmanFord(int s, int t, int flow_limit, int& flow, int& cost) {
    for(int i = 0; i < n; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }
    if(d[t] == INF) return false;
    if(flow + a[t] > flow_limit) a[t] = flow_limit - flow;
    flow += a[t];
    cost += d[t] * a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return true;
  }

  // 需要保证初始网络中没有负权圈
  int MincostFlow(int s, int t, int flow_limit, int& cost) {
    int flow = 0; cost = 0;
    while(flow < flow_limit && BellmanFord(s, t, flow_limit, flow, cost));
    return flow;
  }

};
MCMF mcmf;
int main()
{
    //freopen("test.txt","r",stdin);
    int v,e;int a,b,c;
    while(scanf("%d%d",&v,&e)==2&&v)
    {
        mcmf.init(v<<1);
        for(int i=2;i<v;i++) mcmf.AddEdge(i,i+v-1,1,0);
        for(int i=0;i<e;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a!=1&&a!=v) a+=v-1;
            mcmf.AddEdge(a,b,1,c);
        }
        int ans;
        mcmf.MincostFlow(1,v,2,ans);
        printf("%d\n",ans);
    }
    return 0;
}