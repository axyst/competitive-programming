//#include<bits/stdc++.h>
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
const int maxn=20000+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
vector<int>g[maxn];
int sons[maxn];int vis[maxn];//sons:子结点数
int cnt;int n;int ans;int size;
void dfs(int cur)
{
    vis[cur]=1;
    sons[cur]=0;
    int mx=0;
    int sz=g[cur].size();
    for(int i=0;i<sz;i++)
    {
        int son=g[cur][i];
        if(!vis[son])
        {
            dfs(son);
            sons[cur]+=(sons[son]+1);
            mx=max(mx,sons[son]+1);
        }
    }
    mx=max(mx,n-sons[cur]-1);//自己也要删掉
    if(mx<size||mx==size&&cur<ans)
    {
        ans=cur;
        size=mx;
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t,ia,ib;si(t);
    while(t--)
    {
        for(int i=1;i<=n;i++) g[i].clear();
        cnt=0;
        size=inf;
        mem(vis);
        si(n);
        for(int i=1;i<=n-1;i++)
        {
            si(ia);si(ib);
            g[ia].push_back(ib);
            g[ib].push_back(ia);
        }
        dfs(1);
        printf("%d %d\n",ans,size);
    }
    return 0;
}
