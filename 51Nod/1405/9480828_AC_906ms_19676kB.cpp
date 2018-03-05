#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int n;
LL ans[maxn];
int d[maxn];
vector<int>tree[maxn];
void dfs1(int cur,int fa,int dep)
{
    int sz=tree[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=tree[cur][i];
        if(fa==son) continue;
        ans[1]+=(tree[son].size()-1)*dep;
        dfs1(son,cur,dep+1);
        d[cur]+=d[son];
    }
}
void dfs2(int cur,int fa)
{
    int sz=tree[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=tree[cur][i];
        if(fa==son) continue;
        ans[son]=(ans[cur]-d[son])+(n-d[son]);
        dfs2(son,cur);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ans[1]=tree[1].size();
    for(int i=1;i<=n;i++) d[i]=1;
    dfs1(1,0,2);
    dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%I64d\n",ans[i]);
    return 0;
}
