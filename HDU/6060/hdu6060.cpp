//加读入挂2137ms,不加1310ms，可以说读入挂是一种玄学了
#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int maxn=1e6+5;
typedef pair<int,int> pii;
vector<pii>g[maxn];
int father[maxn];
int sons[maxn];//子树大小
void dfs(int cur,int fa)
{
    father[cur]=fa;
    sons[cur]=1;
    int sz=g[cur].size();
    rep(i,0,sz-1)
    {
        int son=g[cur][i].first;
        if(fa==son) continue;
        dfs(son,cur);
        sons[cur]+=sons[son];
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int n,k,a,b,c;
    while(~scanf("%d",&n))
    {
        memset(sons,0,sizeof(sons));
        rep(i,1,n) g[i].clear();
        scanf("%d",&k);
        rep(i,1,n-1)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back((pii){b,c});g[b].push_back((pii){a,c});
        }
        dfs(1,1);
        LL ans=0;
        rep(i,1,n)
        {
            int sz=g[i].size();
            rep(j,0,sz-1)
            {
                int son=g[i][j].first;
                if(son==father[i]) continue;
                ans+=1LL*g[i][j].second*min(sons[son],k);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
