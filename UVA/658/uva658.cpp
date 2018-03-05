#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=25;const int maxm=105;const int INF=0x3f3f3f3f;int n,m;
int cost[maxm];char bef[maxm][maxn];char aft[maxm][maxn];
int d[1<<maxn];int vis[1<<maxn];
struct HeapNode
{
    int d,u;
    HeapNode(){}
    HeapNode(int dd,int uu):d(dd),u(uu){}
    bool operator <(const HeapNode &rhs) const
    {
        return d>rhs.d;
    }
};
int solve()
{
    priority_queue<HeapNode> Q;
    for(int i=0;i<(1<<n);i++){d[i]=INF;vis[i]=0;}
    HeapNode s;s.d=0;s.u=((1<<n)-1);
    d[s.u]=0;
    Q.push(s);
    while(!Q.empty())
    {
        HeapNode x=Q.top();Q.pop();
        if(!x.u) return x.d;
        if(vis[x.u]) continue;
        vis[x.u]=1;
        for(int i=0;i<m;i++)
        {
            bool flag=1;
            for(int j=0;j<n;j++)
            {
                if(bef[i][j]=='-'&&(x.u&(1<<j))){flag=0;break;}
                if(bef[i][j]=='+'&&!(x.u&(1<<j))){flag=0;break;}
            }
            if(!flag) continue;
            HeapNode y;y.d=x.d+cost[i];y.u=x.u;
            for(int j=0;j<n;j++)
            {
                if(aft[i][j]=='-') y.u&=(~(1<<j));
                if(aft[i][j]=='+') y.u|=(1<<j);
            }
            int &e=d[y.u];
            if(e<0||y.d<e)
            {
                e=y.d;
                Q.push(y);
            }
        }
    }
    return -1;
}
int main()
{
    freopen("test.txt","r",stdin);
    int ks=0;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        //if(++ks>1) printf("\n");
        printf("Product %d\n",++ks);
        for(int i=0;i<m;i++)
        {
            scanf("%d",cost+i);
            scanf("%s",bef[i]);
            scanf("%s",aft[i]);
        }
        int ans=solve();
        if(ans>=0) printf("Fastest sequence takes %d seconds.\n\n",ans);
        else printf("Bugs cannot be fixed.\n\n");
    }
    return 0;
}
