#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=405;const int INF=0x3f3f3f3f;int n,m,k,no;
int types[maxn];int device[maxn];int from[maxn];int to[maxn];
map<string,int>ids;
int id(string a)
{
    if(ids.count(a)) return ids[a];
    else
    {
        ids.insert(pair<string,int>(a,++no));
        return no;
    }
}
struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f) {}
};

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;    // twice the edges
  vector<int> G[maxn];   // adjunct graph,G[i][j] means id of jth edge of i
  int a[maxn];           // augment amount from s
  int p[maxn];           // arc to p

  void init(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for(;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while(!Q.empty()) {//BFS
        int x = Q.front(); Q.pop();
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap-e.flow);
            Q.push(e.to);
          }
        }
        if(a[t]) break;
      }
      if(!a[t]) break;
      for(int u = t; u != s; u = edges[p[u]].from) {//augment once
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};
char useless[105];
int main()
{
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        ids.clear();no=-1;string tmp,pmt;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            types[i]=id(tmp);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%s",useless);
            cin>>tmp;
            device[i]=id(tmp);
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            cin>>tmp>>pmt;
            from[i]=id(tmp);
            to[i]=id(pmt);
        }
        EdmondsKarp ek;
        ek.init(no+5);
        for(int i=0;i<n;i++)
            ek.AddEdge(types[i],no+2,1);//types to t
        for(int i=0;i<m;i++)
            ek.AddEdge(no+1,device[i],1);//s to device
        for(int i=0;i<k;i++)
            ek.AddEdge(from[i],to[i],INF);
        int mf=ek.Maxflow(no+1,no+2);//devices that can match(go from device to type)
        printf("%d\n",m-mf);
        if(t) printf("\n");
    }
    return 0;
}
