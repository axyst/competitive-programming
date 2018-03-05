#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const LL maxn=200000+5;
char buf[100000],*p1=buf,*p2=buf;
inline char nc()
{
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x)
{
    //bool IsN=false;
    char c=nc();x=0;
    if(c==EOF) return false;
    //if(c=='-') isN=true;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    //if(isN) x=-x;
    return true;
}
inline bool rea(LL & x)
{
    //bool IsN=false;
    char c=nc();x=0;
    if(c==EOF) return false;
    //if(c=='-') isN=true;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    //if(isN) x=-x;
    return true;
}
LL color[maxn],sons[maxn],sum[maxn],vis[maxn];
vector<int>tree[maxn];
LL ans;
void dfs(int cur,int fa)
{
    sons[cur]=1;
    int sz=tree[cur].size();
    LL res=0;
    for(int i=0;i<sz;i++)
    {
        int son=tree[cur][i];
        if(son==fa) continue;
        LL bef=sum[color[cur]];
        dfs(son,cur);
        sons[cur]+=sons[son];
        LL diff_cur=sons[son]-(sum[color[cur]]-bef);//new nodes without cur color
        res+=diff_cur;
        ans+=diff_cur*(diff_cur-1LL)/2LL;//make roads
    }
    sum[color[cur]]+=(res+1);//plus self
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int n,a,b;int ks=1;
    while(rea(n))
    {
        memset(vis,0,sizeof(vis));
        memset(sum,0,sizeof(sum));
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            tree[i].clear();
            rea(color[i]);
            if(!vis[color[i]]) tot++;
            vis[color[i]]=1;
        }
        for(int i=1;i<=n-1;i++)
        {
            rea(a);rea(b);
            tree[a].push_back(b);tree[b].push_back(a);
        }
        printf("Case #%d: ",ks++);
        if(tot==1)
        {
            printf("%I64d\n",n*(n-1LL)*1LL/2LL);
            continue;
        }
        ans=0;
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) continue;
            ans+=(n-sum[i])*(n-sum[i]-1LL)/2LL;//delete all parts without this color
        }
        printf("%I64d\n",n*(n-1LL)/2LL*tot-ans);
    }
    return 0;
}
