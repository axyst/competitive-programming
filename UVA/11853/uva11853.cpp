/*
算是思维题吧，我自己做肯定是没有思路
要从触及上边界的圆往其他圆dfs,dfs过程中经过与左边界相交的圆，则更新最北进入位置
同理与有边界相交时更新最南离开位置
如果能从顶走到底则无解
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1005;
int x[maxn],y[maxn],r[maxn],vis[maxn];
int n;double lbound,rbound;
bool intersect(int a,int b)
{
    return ((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]))<(r[a]+r[b])*(r[a]+r[b]);
}
bool dfs(int dep)
{
    if(vis[dep]) return 0;
    vis[dep]=1;
    if(y[dep]<r[dep]) return 1;
    for(int i=0;i<n;i++)
        if(intersect(i,dep)&&dfs(i)) return 1;
    if(x[dep]<r[dep]) lbound=min(lbound,y[dep]-sqrt(r[dep]*r[dep]-x[dep]*x[dep]));
    if(x[dep]+r[dep]>=1000) rbound=min(rbound,y[dep]-sqrt(r[dep]*r[dep]-(1000-x[dep])*(1000-x[dep])));
    return 0;
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        bool flag=0;
        memset(vis,0,sizeof(vis));
        lbound=rbound=1000;
        for(int i=0;i<n;i++) scanf("%d%d%d",x+i,y+i,r+i);
        for(int i=0;i<n;i++)
            if(r[i]+y[i]>=1000&&dfs(i))
            {
                flag=1;
                break;
            }
        if(!flag) printf("0.00 %.2lf 1000.00 %.2lf\n",lbound,rbound);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
