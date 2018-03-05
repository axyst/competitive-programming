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
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=200005;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
char pic[40][40][40];
bool vis[40][40][40];
int dx[]={0,0,-1,1,0,0};
int dy[]={-1,1,0,0,0,0};
int dz[]={0,0,0,0,-1,1};
int ans,l,r,c;
int sx,sy,sz,ex,ey,ez;
typedef struct mapnode
{
    int x;int y;int z;
    int time;
}node;
int bfs()
{
    queue<node>q;
    node def;def.x=sx;def.y=sy;def.z=sz;def.time=0;
    q.push(def);
    while(!q.empty())
    {
        node tmp=q.front();
        q.pop();
        //cout<<tmp.time<<endl;
        //cout<<ex<<ey<<ez<<endl;
        //cout<<tmp.x<<tmp.y<<tmp.z<<endl;
        if(tmp.x==ex&&tmp.y==ey&&tmp.z==ez)
            return tmp.time;
        int tx=tmp.x,ty=tmp.y,tz=tmp.z,tt=tmp.time;
        for(int i=0;i<6;i++)
        {
            if(!vis[tx+dx[i]][ty+dy[i]][tz+dz[i]]
               &&pic[tx+dx[i]][ty+dy[i]][tz+dz[i]]!='#'
               &&tx+dx[i]>=0&&tx+dx[i]<l
               &&ty+dy[i]>=0&&ty+dy[i]<r
               &&tz+dz[i]>=0&&tz+dz[i]<c)
               {
                   tmp.x=tx+dx[i];
                   tmp.y=ty+dy[i];
                   tmp.z=tz+dz[i];
                   tmp.time=tt+1;
                   vis[tx+dx[i]][ty+dy[i]][tz+dz[i]]=1;
                   q.push(tmp);
               }
        }
    }
    return 0;
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(scanf("%d%d%d\n",&l,&r,&c)&&l&&r&&c)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<l;i++,getchar())
            for(int j=0;j<r;j++,getchar())
                for(int k=0;k<c;k++)
        {
            scanf("%c",&pic[i][j][k]);
            if(pic[i][j][k]=='S') sx=i,sy=j,sz=k;
            if(pic[i][j][k]=='E') ex=i,ey=j,ez=k;
        }
        ans=bfs();
        if(ans)printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
    }
    return 0;
}