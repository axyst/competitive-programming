#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
typedef vector<int> vci; typedef pair<int, int> pii;
typedef long long LL;typedef unsigned long long ULL;
using namespace std;
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1e4+5;const long long MOD=10007;

char pic[35][35][35];
int vis[35][35][35];
int dx[]={0,0,-1,1,0,0};
int dy[]={-1,1,0,0,0,0};
int dz[]={0,0,0,0,-1,1};
int l,r,c;
int sx,sy,sz,ex,ey,ez;
struct node
{
    int x;int y;int z;int time;
};
bool check(node n,int dir)
{
    int nx=n.x+dx[dir];
    if(nx<0||nx>l-1) return 0;
    int ny=n.y+dy[dir];
    if(ny<0||ny>r-1) return 0;
    int nz=n.z+dz[dir];
    if(nz<0||nz>c-1) return 0;
    if(vis[nx][ny][nz]) return 0;
    if(pic[nx][ny][nz]=='#') return 0;
    return 1;
}
int bfs()
{
    int ans=INF;
    queue<node>q;
    vis[sx][sy][sz]=1;
    node st;st.x=sx;st.y=sy;st.z=sz;st.time=0;
    q.push(st);
    while(!q.empty())
    {
        node f=q.front();
        q.pop();
        if(f.x==ex&&f.y==ey&&f.z==ez)
        {
            ans=min(ans,f.time);
            continue;
        }
        for(int i=0;i<6;i++)
        {
            if(!check(f,i)) continue;
            node nx;nx.x=f.x+dx[i];nx.y=f.y+dy[i];
            nx.z=f.z+dz[i];nx.time=f.time+1;
            vis[f.x+dx[i]][f.y+dy[i]][f.z+dz[i]]=1;
            q.push(nx);
        }
    }
    return ans;
}
int main()
{
    while(~scanf("%d%d%d",&l,&r,&c)&&(l&&r&&c))
  {
      memset(vis,0,sizeof(vis));
      rep(i,l) rep(j,r) scanf("%s",&pic[i][j]);
      rep(i,l) rep(j,r) rep(k,c)
      {
          if(pic[i][j][k]=='S') sx=i,sy=j,sz=k;
          if(pic[i][j][k]=='E') ex=i,ey=j,ez=k;
      }
      int ans=bfs();
      if(ans!=INF) cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
      else cout<<"Trapped!"<<endl;
  }
    return 0;
}
