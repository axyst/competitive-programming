//URAL ”√lld£¨”√I64dª·WA
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=20005;const int maxs=100005;
LL a[maxn];LL c[maxn];LL d[maxn];
LL vis[maxs];
int lowbit(int x){return x & -x;}
void add(LL x,LL v)
{
    while(x<=maxs)
    {
        vis[x]+=v;
        x+=lowbit(x);
    }
}
LL sum(LL x)
{
    LL ret=0;
    while(x>0)
    {
        ret+=vis[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,n;scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        for(int i=0;i<n;i++)
        {
            add(a[i],1);
            c[i]=sum(a[i]-1);
        }
        memset(vis,0,sizeof(vis));
        for(int i=n-1;i>=0;i--)
        {
            add(a[i],1);
            d[i]=sum(a[i]-1);
        }
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=(c[i-1]*(n-i-d[i-1])+d[i-1]*(i-c[i-1]-1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
