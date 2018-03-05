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
const int maxn=1e3+5;
const int mod=1e9+7;
int cnt,n,m;
int pic[maxn][maxn];
int vis[maxn];int d[maxn];
//优先队列+邻接表的Dijk TLE
//今天看POJ另一题的Discuss里有人说用了链表就TLE，马上想到这题。看来是POJ机子的问题
//SPFA 1816K 313MS
//以下代码 4640K 375MS
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
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int t,a,b,c;scanf("%d",&t);int ks=1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        cnt=1;
        memset(pic,0,sizeof(pic));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            pic[a][b]=pic[b][a]=c;
        }
        Dijkstra(1);
        //for(int i=1;i<=n;i++)cout<<"di"<<i<<' '<<d[i]<<endl;
        printf("Scenario #%d:\n%d\n\n",ks++,d[n]);
    }
    return 0;
}
