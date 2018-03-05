//MLE
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1000003;
int n,m;
int father[maxn];
int sum[maxn];double dp[maxn];
int look(int x)
{
    //cout<<x<<' '<<father[x]<<endl;
    return father[x]==x?x:father[x]=look(father[x]);
}
struct Edge
{
    int u,v,d;
}edge[maxn*10];
bool cmp(Edge a,Edge b)
{
    return a.d<b.d;
}
struct pii
{
    int first;
    int second;
};
vector<pii>tree[maxn];
void dfs(int cur,int ft)
{
    sum[cur]=1;
    int sz=tree[cur].size();
    for(int i=0;i<sz;i++)
    {
        int v=tree[cur][i].first;
        if(v==ft) continue;
        int d=tree[cur][i].second;
        dfs(v,cur);
        sum[cur]+=sum[v];
        dp[cur]+=(dp[v]+(double)sum[v]*(double)(n-sum[v])*(double)d);
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,a,b,c;scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=n;i++) tree[i].clear();
        //for(int i=0;i<=n;i++) father[i]=i;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) father[i]=i;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].d);
        }
        sort(edge,edge+m,cmp);
        LL ans=0;
        int k=0;
        for(int i=0;i<m;i++)
        {
            int u=look(edge[i].u),v=look(edge[i].v);int d=edge[i].d;
            //cout<<u<<' '<<v<<' '<<d<<endl;
            if(u!=v)
            {
                father[u]=father[v];
                pii uu=(pii){edge[i].v,d};pii vv=(pii){edge[i].u,d};
                tree[u].push_back(uu);tree[v].push_back(vv);
                ans+=(LL)d;
                k++;
            }
            if(k==n-1) break;
        }
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        dfs(1,0);
        double expect=((double)n*(double)(n-1)*0.5);
        expect=dp[1]/expect;
        printf("%I64d %.2f\n",ans,expect);
    }
    return 0;
}