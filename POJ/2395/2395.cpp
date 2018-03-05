#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=10005;
int u[MAXN],v[MAXN],w[MAXN],aset[MAXN],num[MAXN];
int m,n;
int Cmp(int a,int b)
{
    return w[a]<w[b];
}
int Find(int x)
{
    if(aset[x]==x) return x;
    return aset[x]=Find(aset[x]);
}
int Krus()
{
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++) aset[i]=i;
    for(int i=1;i<=m;i++) num[i]=i;
    sort(num+1,num+1+m,Cmp);
    for(int i=1;i<=m;i++)
    {
        int e=num[i];
        int x=Find(u[e]),y=Find(v[e]);
        if(x!=y)
        {
            ans=max(ans,w[e]);
            aset[x]=y;
            cnt++;
        }
        if(cnt==n-1) return ans;
    }
    if(cnt<n-1) ans=0;
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
        printf("%d\n",Krus());
    }
    return 0;
}