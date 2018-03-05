//并查集 Kruskal Prim Dijkstra Bellman-Ford Floyd
//割顶和桥 BCC SCC Dinic MCMF LCA 树
//拓扑排序 欧拉回路 最小树形图
//二分图最大匹配 二分图完美匹配
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
//存图:1.邻接矩阵/vector
//2.邻接表
struct Edge
{
    int to,next,wei;
    Edge(int a,int b,int c):to(a),next(b),wei(c){};
    Edge():to(-1),next(-1),wei(0){};
}edge[12401];
int head[2501],dis[2501],d[20001];
int ne,n,m,bg,ed;
void insert(int a,int b,int c)
{
    edge[++ne]=(Edge){b,head[a],c};
    head[a]=ne;
}
//并查集
void init()
{
    for(int i=1;i<=n;i++) rank[id[i]=i]=0;
}
int find(int p)
{
    while (p!=id[p])
    {
        id[p]=id[id[p]];
        p=id[p];
    }
    return p;
}
void merge(int x,int y)
{
    if(rank[x=find(x)]>rank[y=find(y)]) id[y]=x;
    else
    {
        id[x]=y;
        rank[y]+=(rank[x]==rank[y]);
    }
}
//Kruskal O(ElogV)
struct Edge
{
    int u,v,d;
    bool operator <(const Edge &rhs) const
    {
        return d<rhs.d;
    }
};
const int maxn=5005;int n;int q;
int father[maxn],x[maxn],y[maxn];
int look(int x){return father[x]==x?x:father[x]=look(father[x]);}
vector<Edge>edge,need;
int Kruskal(int cnt,vector<Edge>e,vector<Edge>&use)//cnt:cc的数量,ans:边权和,use:使用的边
{
    if(cnt==1) return 0;
    int mm=e.size();int ans=0;use.clear();
    for(int i=0;i<mm;i++)
    {
        int u=look(e[i].u),v=look(e[i].v);int d=e[i].d;
        if(u!=v)
        {
            father[u]=v;
            ans+=d;use.push_back(e[i]);
            if(--cnt==1) break;
        }
    }
    return ans;
}
int solve()
{
    for(int i=0;i<n;i++) father[i]=i;
    sort(edge.begin(),edge.end());
    int ans=Kruskal(n,edge,need);
    return ans;
}
//Prim O(V^2)
int Prim()
{
    for(int i=2;i<=n;i++)
    {
        vis[i]=0;
        dis[i]=mat[i][1];
    }
    vis[1]=1;
    int sum=0;
    for(int i=1;i<=n-1;i++)
    {
        int tem=INF,pos;
        for(int j=1;j<=n;j++)
        {
        if(!vis[j]&&dis[j]<tem)
            tem=dis[pos=j];
        }
        vis[pos]=1;
        sum+=dis[pos];
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]>mat[pos][j]&&mat[pos][j]!=INF)
                dis[j]=mat[pos][j];
        }
    }
    return sum;
}
/*
* 次小生成树
* 求最小生成树时，用数组Max[i][j]来表示MST中i到j最大边权
* 求完后，直接枚举所有不在MST中的边，替换掉最大边权的边，更新答案
*/
//Dijkstra O(ElogV)
const int maxn=1005;const int INF=0x3f3f3f3f;
struct Edge
{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct HeapNode
{
    int d,u;
    HeapNode(int dd,int uu):d(dd),u(uu){}
    bool operator <(const HeapNode &rhs) const
    {
        return d>rhs.d;
    }
};
struct dijkstra
{
    int n,m;
    vector<Edge>edges;vector<int>G[maxn];bool done[maxn];int d[maxn];int p[maxn];
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist)
    {
        edges.push_back(Edge(from,to,dist));
        m=edges.size();G[from].push_back(m-1);
    }
    void Dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++){d[i]=INF;done[i]=0;}
        d[s]=0;
        Q.push(HeapNode(0,s));
        while(!Q.empty())
        {
            HeapNode x=Q.top();Q.pop();
            int u=x.u;if(done[u]) continue;
            done[u]=1;int sz=G[u].size();
            for(int i=0;i<sz;i++)
            {
                Edge&e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push(HeapNode(d[e.to],e.to));
                }
            }
        }
    }
};
//O(V^2)
void Dijkstra(int s)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) d[i]=pic[1][i];
    int id;
    for(int i=1;i<=n;i++)
    {
        int mx=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&mx<d[j]) mx=d[id=j];
        vis[id]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&d[j]<min(d[id],pic[id][j]))
            d[j]=min(d[id],pic[id][j]);
    }
}
//Bellman-Ford O(EV)
const int maxn=1005;const int INF=0x3f3f3f3f;int n,m;
int inq[maxn];int cnt[maxn];int d[maxn];int p[maxn];
vector<int>G[maxn];
struct Edge
{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};vector<Edge>edges;
bool BellmanFord(int s)
{
    queue<int>Q;
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) d[i]=INF;d[s]=0;
    inq[s]=1;Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        inq[u]=0;int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            Edge&e=edges[G[u][i]];
            if(d[u]<INF&&d[e.to]>d[u]+e.dist)
            {
                d[e.to]=d[u]+e.dist;
                p[e.to]=G[u][i];
                if(!inq[e.to])
                {
                    Q.push(e.to);
                    inq[e.to]=1;
                    if(++cnt[e.to]>n) return 0;
                }
            }
        }
    }
    return 1;
}
//SPFA O(KE)，其中K为所有顶点进队的平均次数，K一般小于等于2，但是可能被特殊数据卡
int spfa()
{
	dis[bg]=0;d[0]=bg;
	int q,t=0,w=1;
	while(t<w)
	{
		q=head[d[t]];
		while(q!=0)
		{
			if(dis[e[q].to]>dis[d[t]]+e[q].wei)
			{
                dis[e[q].to]=dis[d[t]]+e[q].wei;
                d[w++]=e[q].to;
		    }
		    q=e[q].next;
		}
		t++;
	}
	return dis[ed];
}
//Floyd
const int maxn=1005;const int INF=0x3f3f3f3f;int n,m;
int d[maxn][maxn];
void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]<INF&&d[k][j]<INF)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
//DFS
vector<int>G[maxn];int vis[maxn];int cc;int n;
void dfs(int u)
{
    vis[u]=1;
    //previsit(u);
    int d=G[u].size();
    for(int i=0;i<d;i++)
    {
        int v=G[u][i];
        if(!vis[v]) dfs(v);
    }
    //postvisit(u);
}
void find_cc()
{
    cc=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        if(!vis[i])
        dfs(i),cc++;
}
bool isbip(int u)
{
    int d=G[u].size();
    for(int i=0;i<d;i++)
    {
        int v=G[u][i];
        if(color[v]==color[i]) return 0;
        if(!color[v])
        {
            color[v]=3-color[i];
            if(!isbip(v)) return 0;
        }
    }
    return 1;
}
///无向图的割顶,桥,BCC
vector<int>G[maxn];
vector<pair<int,int> >bridges;
int iscut[maxn];int pre[maxn];int low[maxn];
int dfs_clock=0;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int child=0;int sz=G[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if(!pre[v])
        {
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])
            {
                iscut[u]=1;
                if(lowv!=pre[u])bridges.push_back(pair<int,int>(v,u));
            }
        }
        else if(pre[v]<pre[u]&&v!=fa)//visited,less pre,not father(back edge)
            lowu=min(lowu,pre[v]);
    }
    if(fa<0&&child==1) iscut[u]=0;
    low[u]=lowu;
    return lowu;
}
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int>G[maxn],bcc[maxn];
struct Edge
{
    int u;int v;
};
stack<Edge>S;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int child=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        Edge e=(Edge){u,v};
        if(!pre[v])
        {
            S.push(e);
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])//find new cut
            {
                iscut[u]=1;
                bcc_cnt++;bcc[bcc_cnt].clear();//initialize current bcc
                while(1)
                {
                    Edge x=S.top();S.pop();//last visited edge
                    if(bccno[x.u]!=bcc_cnt)//point not in bcc,add
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt)//point not in bcc,add
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u&&x.v==v) break;
                }
            }
            else if(pre[v]<pre[u]&&v!=fa)//back edge
            {
                S.push(e);
                lowu=min(lowu,pre[v]);
            }
        }
    }
    if(fa<0&&child==1) iscut[u]=0;
    return lowu;
}
void find_bcc(int n)
{
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=bcc_cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!pre[i]) dfs(i,-1);
    }
}
///有向图SCC
vector<int>G[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;
stack<int>S;
void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i>G[u].size();i++)
    {
        int v=G[u][i];
        if(!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v])
        {
            lowlink[u]=min(lowlink[u],pre[v]);
        }
    }
    if(lowlink[u]==pre[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=0;i<n;i++)
        if(!pre[i]) dfs(i);
}
//Dinic
struct Edge {
  int from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;    // 边数的两倍
  vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[maxn];         // BFS使用
  int d[maxn];           // 从起点到i的距离
  int cur[maxn];        // 当前弧指针

  void ClearAll(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    while(BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }

  vector<int> Mincut() { // call this after maxflow
    vector<int> ans;
    for(int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if(vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
    return ans;
  }

  void Reduce() {
    for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
  }
};
//ISAP
struct Edge {
  int from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[maxn];        // BFS使用
  int d[maxn];           // 从起点到i的距离
  int cur[maxn];        // 当前弧指针
  int p[maxn];          // 可增广路上的上一条弧
  int num[maxn];        // 距离标号计数

  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(t);
    vis[t] = 1;
    d[t] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]^1];
        if(!vis[e.from] && e.cap > e.flow) {
          vis[e.from] = 1;
          d[e.from] = d[x] + 1;
          Q.push(e.from);
        }
      }
    }
    return vis[s];
  }

  void ClearAll(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  int Augment() {
    int x = t, a = INF;
    while(x != s) {
      Edge& e = edges[p[x]];
      a = min(a, e.cap-e.flow);
      x = edges[p[x]].from;
    }
    x = t;
    while(x != s) {
      edges[p[x]].flow += a;
      edges[p[x]^1].flow -= a;
      x = edges[p[x]].from;
    }
    return a;
  }

  int Maxflow(int s, int t, int need) {
    this->s = s; this->t = t;
    int flow = 0;
    BFS();
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; i++) num[d[i]]++;
    int x = s;
    memset(cur, 0, sizeof(cur));
    while(d[s] < n) {
      if(x == t) {
        flow += Augment();
        if(flow >= need) return flow;
        x = s;
      }
      int ok = 0;
      for(int i = cur[x]; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(e.cap > e.flow && d[x] == d[e.to] + 1) { // Advance
          ok = 1;
          p[e.to] = G[x][i];
          cur[x] = i; // 注意
          x = e.to;
          break;
        }
      }
      if(!ok) { // Retreat
        int m = n-1; // 初值注意
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(e.cap > e.flow) m = min(m, d[e.to]);
        }
        if(--num[d[x]] == 0) break;
        num[d[x] = m+1]++;
        cur[x] = 0; // 注意
        if(x != s) x = edges[p[x]].from;
      }
    }
    return flow;
  }

  vector<int> Mincut() { // call this after maxflow
    BFS();
    vector<int> ans;
    for(int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if(!vis[e.from] && vis[e.to] && e.cap > 0) ans.push_back(i);
    }
    return ans;
  }

  void Reduce() {
    for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
  }

//Min Cost Max Flow
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

  bool BellmanFord(int s, int t, int& flow, int& cost) {
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
    flow += a[t];
    cost += d[t] * a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return true;
  }

  // 需要保证初始网络中没有负权圈
  int MincostMaxflow(int s, int t, int& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s, t, flow, cost));
    return flow;
  }
  //有流量上限的情况
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

  int MincostFlow(int s, int t, int flow_limit, int& cost) {
    int flow = 0; cost = 0;
    while(flow < flow_limit && BellmanFord(s, t, flow_limit, flow, cost));
    return flow;
  }

};
//LCA
/*
 * LCA  (POJ 1330)
 * 在线算法 DFS + ST O(nlogn)
 */
const int MAXN = 10010;
int rmq[2*MAXN];//rmq数组，就是欧拉序列对应的深度序列
struct ST
{
    int mm[2*MAXN];
    int dp[2*MAXN][20];//最小值对应的下标
    void init(int n)
    {
        mm[0] = -1;
        for(int i = 1;i <= n;i++)
        {
            mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
            dp[i][0] = i;
        }
        for(int j = 1; j <= mm[n];j++)
            for(int i = 1; i + (1<<j) - 1 <= n; i++)
                dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }
    int query(int a,int b)//查询[a,b]之间最小值的下标
    {
        if(a > b)swap(a,b);
        int k = mm[b-a+1];
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
    }
};
//边的结构体定义
struct Edge
{
    int to,next;
};
Edge edge[MAXN*2];
int tot,head[MAXN];

int F[MAXN*2];//欧拉序列，就是dfs遍历的顺序，长度为2*n-1,下标从1开始
int P[MAXN];//P[i]表示点i在F中第一次出现的位置
int cnt;

ST st;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)//加边，无向边需要加两次
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int u,int pre,int dep)
{
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == pre)continue;
        dfs(v,u,dep+1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}
void LCA_init(int root,int node_num)//查询LCA前的初始化
{
    cnt = 0;
    dfs(root,root,0);
    st.init(2*node_num-1);
}
int query_lca(int u,int v)//查询u,v的lca编号
{
    return F[st.query(P[u],P[v])];
}
bool flag[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int N;
    int u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init();
        memset(flag,false,sizeof(flag));
        for(int i = 1; i < N;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
            flag[v] = true;
        }
        int root;
        for(int i = 1; i <= N;i++)
            if(!flag[i])
            {
                root = i;
                break;
            }
        LCA_init(root,N);
        scanf("%d%d",&u,&v);
        printf("%d\n",query_lca(u,v));
    }
    return 0;
}
/*
 * POJ 1470
 * 给出一颗有向树，Q个查询
 * 输出查询结果中每个点出现次数
 */
/*
 * LCA离线算法，Tarjan
 * 复杂度O(n+Q);
 */
const int MAXN = 1010;
const int MAXQ = 500010;//查询数的最大值

//并查集部分
int F[MAXN];//需要初始化为-1
int find(int x)
{
    if(F[x] == -1)return x;
    return F[x] = find(F[x]);
}
void bing(int u,int v)
{
    int t1 = find(u);
    int t2 = find(v);
    if(t1 != t2)
        F[t1] = t2;
}
//************************
bool vis[MAXN];//访问标记
int ancestor[MAXN];//祖先
struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

struct Query
{
    int q,next;
    int index;//查询编号
}query[MAXQ*2];
int answer[MAXQ];//存储最后的查询结果，下标0~Q-1
int h[MAXQ];
int tt;
int Q;

void add_query(int u,int v,int index)
{
    query[tt].q = v;
    query[tt].next = h[u];
    query[tt].index = index;
    h[u] = tt++;
    query[tt].q = u;
    query[tt].next = h[v];
    query[tt].index = index;
    h[v] = tt++;
}

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    tt = 0;
    memset(h,-1,sizeof(h));
    memset(vis,false,sizeof(vis));
    memset(F,-1,sizeof(F));
    memset(ancestor,0,sizeof(ancestor));
}

void LCA(int u)
{
    ancestor[u] = u;
    vis[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v])continue;
        LCA(v);
        bing(u,v);
        ancestor[find(u)] = u;
    }
    for(int i = h[u];i != -1;i = query[i].next)
    {
        int v = query[i].q;
        if(vis[v])
        {
            answer[query[i].index] = ancestor[find(v)];
        }
    }
}

bool flag[MAXN];
int Count_num[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int u,v,k;
    while(scanf("%d",&n) == 1)
    {
        init();
        memset(flag,false,sizeof(flag));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d:(%d)",&u,&k);
            while(k--)
            {
                scanf("%d",&v);
                flag[v] = true;
                addedge(u,v);
                addedge(v,u);
            }
        }
        scanf("%d",&Q);
        for(int i = 0;i < Q;i++)
        {
            char ch;
            cin>>ch;
            scanf("%d %d)",&u,&v);
            add_query(u,v,i);
        }
        int root;
        for(int i = 1;i <= n;i++)
            if(!flag[i])
            {
                root = i;
                break;
            }
        LCA(root);
        memset(Count_num,0,sizeof(Count_num));
        for(int i = 0;i < Q;i++)
            Count_num[answer[i]]++;
        for(int i = 1;i <= n;i++)
            if(Count_num[i] > 0)
                printf("%d:%d\n",i,Count_num[i]);
    }
    return 0;
}

//笛卡儿树(Cartesian Tree) 是一种特殊的堆，它根据一个长度为n的数组A建立。
//它的根是A的最小元素位置i，而左子树和右子树分别为A[1. . . i-1]和A[i+1. . . n]的笛卡儿树
//RMQ定理 数组A的Cartesian树记为C(A)，则RMQ(A, i, j) = LCA(C(A), i, j)
/*树的性质
以i为根的子树直径d[i] 以i为根的子树深度g[i] 结点i在原树中的深度depth[i]
g[i] = max{depth[i], g[j]}
d[i]= max{g[u]+g[v], d[j]}
设T(u, v)为原树删除边(u, v)后以v为顶点的有根树（ u为0表示不删除任何边），
d[u, v]为T(u, v)的深度，则有递推式d[u, v] = max{0, d[v, w] + 1}，
其中w是v不等于u的儿子
则每个结点i的最远点离它的距离就是d[0, i]，时间复杂度为O(n)
*/
//树的重心
//POJ 1655
//给定一棵树,求树的重心的编号以及重心删除后得到的最大子树的节点个数size,
//如果size相同就选取编号最小的
vector<int>g[maxn];
int sons[maxn];int vis[maxn];
int cnt;int n;int ans;int size;
void dfs(int cur)
{
    vis[cur]=1;
    sons[cur]=0;
    int mx=0;
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i];
        if(!vis[son])
        {
            dfs(son);
            sons[cur]+=(sons[son]+1);
            mx=max(mx,sons[son]+1);
        }
    }
    mx=max(mx,n-sons[cur]-1);
    if(mx<size||mx==size&&cur<ans)
    {
        ans=cur;
        size=mx;
    }
}

int main()
{
    int t,ia,ib;si(t);
    while(t--)
    {
        for(int i=1;i<=n;i++) g[i].clear();
        cnt=0;
        size=inf;
        mem(vis);
        si(n);
        for(int i=1;i<=n-1;i++)
        {
            si(ia);si(ib);
            g[ia].push_back(ib);
            g[ib].push_back(ia);
        }
        dfs(1);
        printf("%d %d\n",ans,size);
    }
}
//树的分治 POJ1741
typedef pair<int,int> pii;
vector<pii>g[maxn];
int sons[maxn];int vis[maxn];int dep[maxn];
int n;int k;int size;
int ri,le;
void dfssize(int cur,int fa)
{
    sons[cur]=1;
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i].first;
        if(vis[son]||fa==son) continue;
        dfssize(son,cur);
        sons[cur]+=sons[son];
    }
}
void getroot(int cur,int fa,int tot,int &root)
{
    int mx=tot-sons[cur];
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i].first;
        if(vis[son]||fa==son) continue;
        getroot(son,cur,tot,root);
        mx=max(mx,sons[son]);
    }
    if(mx<size)
    {
        root=cur;
        size=mx;
    }
}
void dfsdep(int cur,int fa,int d)
{
    dep[ri++]=d;
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i].first;
        if(vis[son]||fa==son) continue;
        dfsdep(son,cur,d+g[cur][i].second);
    }
}
int getdep(int l,int r)
{
    sort(dep+l,dep+r);
    int ret=0,en=r-1;
    for(int i=l;i<r;i++)
    {
        if(dep[i]>k) break;
        while(en>=l&&dep[en]+dep[i]>k) en--;
        ret+=(en-l+1);
        if(en>=i) ret--;
    }
    return ret>>1;
}
int solve(int cur)
{
    dfssize(cur,0);

    int tot=sons[cur];
    size=inf;int root;
    getroot(cur,0,tot,root);
    vis[root]=1;
    int sz=g[root].size();
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        int son=g[root][i].first;
        if(vis[son]) continue;
        ans+=solve(son);
    }
    le=0;ri=0;
    for(int i=0;i<sz;i++)
    {
        int son=g[root][i].first;
        if(vis[son]) continue;
        dfsdep(son,root,g[root][i].second);
        ans-=getdep(le,ri);
        le=ri;
    }
    ans+=getdep(0,ri);
    for(int i=0;i<ri;i++)
    {
        if(dep[i]<=k) ans++;
        else break;
    }
    vis[root]=0;
    return ans;

}
int main()
{
    int ln=0;
    int ia,ib,ic;
    while(~scanf("%d%d",&n,&k)&&n&&k)
    {
        mem(vis);if(!ln) ln=n;
        for(int i=0;i<=ln;i++) g[i].clear();
        ln=n;
        for(int i=0;i<n-1;i++)
        {
            si(ia);si(ib);si(ic);
            g[ia].push_back((pii){ib,ic});
            g[ib].push_back((pii){ia,ic});
        }
        printf("%d\n",solve(1));
    }
    return 0;
}
//拓扑排序判环
vector<int> G[MAXN];  // 邻接表。
int son[MAXN];          // 入度数。
void topo()
{
    queue<int> que;
    int ok = 0;
    for (int i = 0; i < n; i++)
        if (!son[i])
            que.push(i);    // 入度为0时入队。

    while (!que.empty())
    {
        if (que.size() > 1)
            ok = 1;         // 当队列中个数超多1时，表示有不唯一解。
        int t = que.front();
        que.pop();
        cnt--;          //  如果队列为空后，计数器> 0， 说明存在环结构。
        for (int i = 0; i < G[t].size(); i++)
            if (--son[G[t][i]] == 0) // 判断减掉当前点的关系后，点的入度是否为0。
                que.push(G[t][i]);
    }
}
//欧拉回路,inv[i]是i的反向边
vector<int>route;int cnt;int head[maxn];
struct edge{int to,int next}edges;
void insert(int from,int to){edges[cnt].to=to;edges[cnt].next=head[from];head[from]=cnt++;}
void eulerroute(int u)
{
    for(int i=head[u];i;i=edges[i].next)
    {
        if(!mk[i])
        {
            mk[i]=mk[inv[i]]=1;
            eulerroute(edges[i]);
            route.push(i);
        }
    }
}
/*
* 最小树形图
* int型
* 复杂度O(NM)
* 点从0开始
*/
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int MAXM = 40010;
struct Edge
{int u,v,cost;}edge[MAXM];
int pre[MAXN],id[MAXN],visit[MAXN],in[MAXN];
int zhuliu(int root,int n,int m,Edge edge[])
{
    int res = 0,u,v;
    while(1)
    {
        for(int i = 0;i < n;i++)
        in[i] = INF;
        for(int i = 0;i < m;i++)
        if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v])
        {
            pre[edge[i].v] = edge[i].u;
            in[edge[i].v] = edge[i].cost;
        }
        for(int i = 0;i < n;i++)
        if(i != root && in[i] == INF)
        return -1;//不存在最小树形图
        int tn = 0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root] = 0;
        for(int i = 0;i < n;i++)
        {
            res += in[i];
            v = i;
            while( visit[v] != i && id[v] == -1 && v != root)
            {
                visit[v] = i;
                v = pre[v];
            }
            if( v != root && id[v] == -1 )
            {
                for(int u = pre[v]; u != v ;u = pre[u])
                id[u] = tn;
                id[v] = tn++;
            }
        }
        if(tn == 0)break;//没有有向环
        for(int i = 0;i < n;i++)
        if(id[i] == -1)
        id[i] = tn++;
        for(int i = 0;i < m;)
        {
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v)
            edge[i++].cost -= in[v];
            else swap(edge[i],edge[--m]);
        }
        n = tn;
        root = id[root];
    }
    return res;
}
int g[MAXN][MAXN];
int main()
{
    int n,m;
    int iCase = 0;
    int T;
    scanf("%d",&T);
    while( T-- )
    {
        iCase ++;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        g[i][j] = INF;
        int u,v,cost;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&cost);
            if(u == v)continue;
            g[u][v] = min(g[u][v],cost);
        }
        int L = 0;
        for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        if(g[i][j] < INF)
        {
            edge[L].u = i;
            edge[L].v = j;
            edge[L++].cost = g[i][j];
        }
        int ans = zhuliu(0,n,L,edge);
        printf("Case #%d: ",iCase);
        if(ans == -1)printf("Possums!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
//二分图最大匹配
///匈牙利算法 O(EV)
const int maxn=1505;//这个值要超过两边个数的较大者，因为有link
int link[maxn];
bool used[maxn];
vector<int>G[maxn];
int uN;
bool dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        if(!used[G[u][i]])
        {
            used[G[u][i]]=true;
            if(link[G[u][i]]==-1||dfs(link[G[u][i]]))
            {
                link[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int u;
    int res=0;
    memset(link,-1,sizeof(link));
    for(u=0; u<uN; u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
///Hopcroft-Carp O(sqrt(V)E)
const int MAXN=3001;
const int INF=1<<28;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];
bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<Nx;i++)
        if(Mx[i]==-1)
        {
            Q.push(i);
            dx[i]=0;
        }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis)  break;
        for(int v=0;v<Ny;v++)
            if(g[u][v]&&dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(My[v]==-1)  dis=dy[v];
                else
                {
                    dx[My[v]]=dy[v]+1;
                    Q.push(My[v]);
                }
            }
    }
    return dis!=INF;
}
bool DFS(int u)
{
    for(int v=0;v<Ny;v++)
       if(!vst[v]&&g[u][v]&&dy[v]==dx[u]+1)
       {
           vst[v]=1;
           if(My[v]!=-1&&dy[v]==dis) continue;
           if(My[v]==-1||DFS(My[v]))
           {
               My[v]=u;
               Mx[u]=v;
               return 1;
           }
       }
    return 0;
}
int MaxMatch()
{
    int res=0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP())
    {
        memset(vst,0,sizeof(vst));
        for(int i=0;i<Nx;i++)
          if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;
}
//二分图完美匹配 KuhnMunkres O(V^3)
#define M 505
#define inf 0x3fffffff
bool sx[M], sy[M];
int match[M], w[M][M], n, m, d, lx[M], ly[M];
//n：左集元素个数； m：右集元素个数
void init ()
{
    memset (w, 0, sizeof(w));    //不一定要，求最小值一般要初始化为负无穷！
}
bool dfs (int u)
{
    int v; sx[u] = true;
    for (v = 0; v < m; v++)
    {
        if (!sy[v] && lx[u]+ly[v]==w[u][v])
        {
            sy[v] = true;
            if (match[v] == -1 || dfs (match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int KM ()
{
    int i, j, k, sum = 0;
    memset (ly, 0, sizeof(ly));
    for (i = 0; i < n; i++)
    {
        lx[i] = -inf;
        for (j = 0; j < m; j++)
            if (lx[i] < w[i][j])
                lx[i] = w[i][j];
    }
    memset (match, -1, sizeof(match));
    for (i = 0; i < n; i++)
    {
        while (1)
        {
            memset (sx, false, sizeof(sx));
            memset (sy, false, sizeof(sy));
            if (dfs (i))
                break;
                d = inf;
                for (j = 0; j < n; j++)
                    if (sx[j])
                        for (k = 0; k < m; k++)
                            if (!sy[k])
                                d = min (d, lx[j]+ly[k]-w[j][k]);
                if (d == inf)    //找不到完美匹配
                    return -1;
                for (j = 0; j < n; j++)
                    if (sx[j])
                        lx[j] -= d;
                for (j = 0; j < m; j++)
                    if (sy[j])
                        ly[j] += d;
        }
    }
    for (i = 0; i < m; i++)
        if (match[i] > -1)
            sum += w[match[i]][i];
    return sum;
}
