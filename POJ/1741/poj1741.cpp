//#include<bits/stdc++.h>
//http://www.cnblogs.com/kuangbin/p/3454883.html
//不是很懂……去看看论文
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%lld",&(n))
using namespace std;
typedef long long LL;
const int maxn=10000+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
typedef pair<int,int> pii;
vector<pii>g[maxn];
int sons[maxn];int vis[maxn];int dep[maxn];
int n;int k;int size;
int ri,le;
void dfssize(int cur,int fa)
{
    sons[cur]=1;
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i].first;
        if(vis[son]||fa==son) continue;
        dfssize(son,cur);
        sons[cur]+=sons[son];
    }
}
void getroot(int cur,int fa,int tot,int &root)
{
    int mx=tot-sons[cur];
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i].first;
        if(vis[son]||fa==son) continue;
        getroot(son,cur,tot,root);
        mx=max(mx,sons[son]);
    }
    if(mx<size)
    {
        root=cur;
        size=mx;
    }
}
void dfsdep(int cur,int fa,int d)
{
    dep[ri++]=d;
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i].first;
        if(vis[son]||fa==son) continue;
        dfsdep(son,cur,d+g[cur][i].second);
    }
}
int getdep(int l,int r)
{
    sort(dep+l,dep+r);
    int ret=0,en=r-1;
    for(int i=l;i<r;i++)
    {
        if(dep[i]>k) break;
        while(en>=l&&dep[en]+dep[i]>k) en--;
        ret+=(en-l+1);
        if(en>=i) ret--;
    }
    return ret>>1;
}
int solve(int cur)
{
    dfssize(cur,0);
    int tot=sons[cur];
    size=inf;int root;
    getroot(cur,0,tot,root);
    vis[root]=1;
    int sz=g[root].size();
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        int son=g[root][i].first;
        if(vis[son]) continue;
        ans+=solve(son);
    }
    le=0;ri=0;
    for(int i=0;i<sz;i++)
    {
        int son=g[root][i].first;
        if(vis[son]) continue;
        dfsdep(son,root,g[root][i].second);
        ans-=getdep(le,ri);
        le=ri;
    }
    ans+=getdep(0,ri);
    for(int i=0;i<ri;i++)
    {
        if(dep[i]<=k) ans++;
        else break;
    }
    vis[root]=0;
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int ln=0;
    int ia,ib,ic;
    while(~scanf("%d%d",&n,&k)&&n&&k)
    {
        mem(vis);if(!ln) ln=n;
        for(int i=0;i<=ln;i++) g[i].clear();
        ln=n;
        for(int i=0;i<n-1;i++)
        {
            si(ia);si(ib);si(ic);
            g[ia].push_back((pii){ib,ic});
            g[ib].push_back((pii){ia,ic});
        }
        printf("%d\n",solve(1));
    }
    return 0;
}
