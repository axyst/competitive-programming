#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
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
vector<int>discount[10];
int cost[10];
int Kruskal(int cnt,vector<Edge>e,vector<Edge>&use)//cnt:cc的数量
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
    int ans=Kruskal(n,edge,need);//第一次 全图的边，n个cc（每个点都是一个）
    for(int mask=0;mask<(1<<q);mask++)//枚举套餐 用二进制数字表达购买方案
    {
        for(int i=0;i<n;i++) father[i]=i;
        int cnt=n,c=0;
        for(int i=0;i<q;i++) if(mask&(1<<i))//购买此套餐，计算购买可以减少多少个cc
        {
            c+=cost[i];
            for(int j=1;j<discount[i].size();j++)
            {
                int u=look(discount[i][j]),v=look(discount[i][0]);
                if(u!=v){father[u]=v;cnt--;}
            }
        }
        vector<Edge>temp;
        ans=min(ans,c+Kruskal(cnt,need,temp));//第二次 套餐中的边和第一次的边,扣除减少量后的cc
    }
    return ans;
}
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b;
    int ks,sz,tmp;scanf("%d\n",&ks);
    while(ks--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<q;i++)
        {
            discount[i].clear();
            scanf("%d%d",&sz,cost+i);
            for(int j=0;j<sz;j++)
            {
                scanf("%d",&tmp);
                discount[i].push_back(tmp-1);
            }
        }
        for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
        edge.clear();need.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int c=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                edge.push_back((Edge){i,j,c});//只有1000个点，画成完全图
            }
        }
        int ans=solve();
        printf("%d\n",ans);
        if(ks) printf("\n");
    }
    return 0;
}
