#include<bits/stdc++.h>
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=6005;
vector<int>tree[maxn];
int dp[maxn][2];
int rat[maxn];
int root[maxn];
int ans;
void dfs(int cur)
{
    int sz=tree[cur].size();
    dp[cur][0]=0;
    dp[cur][1]=rat[cur];
    for(int i=0;i<sz;i++)
    {
        int son=tree[cur][i];
        dfs(son);
        dp[cur][0]=max(dp[cur][0],dp[cur][0]+max(dp[son][1],dp[son][0]));
        dp[cur][1]=max(dp[cur][1],dp[cur][1]+dp[son][0]);
        //cout<<dp[cur][0]<<' '<<dp[cur][1]<<' '<<cur<<endl;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int n;
    while(~si(n))
    {
        for(int i=1;i<=n;i++) si(rat[i]);
        memset(root,0,sizeof(root));
        int a,b;int boss=1;ans=1;
        while(1)
        {
            si(a);si(b);
            if(a==0&&b==0) break;
            tree[b].push_back(a);
            root[a]=1;
        }
        for(int i=1;i<=n;i++) if(!root[i]) {boss=i;break;}
        dfs(boss);
        printf("%d\n",max(dp[boss][0],dp[boss][1]));
    }
    return 0;
}