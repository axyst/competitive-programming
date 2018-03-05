#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
bool vis[maxn];int prime[maxn],mu[maxn];int cnt;
void Init()
{
    memset(prime,0,sizeof(prime));
    memset(mu,0,sizeof(mu));
    memset(vis,0,sizeof(vis));
    mu[1] = 1;
    cnt = 0;
    for(int i=2; i<maxn; i++)
    {
        if(!vis[i])
        {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<cnt&&i*prime[j]<maxn; j++)
        {
            vis[i*prime[j]] = 1;
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];
            else
            {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
    for(int i=0;i<maxn;i++) mu[i]=-mu[i];
}
LL fpow(LL a,int b)
{
    if(a==0) return 0;
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int a[maxn];int sum[maxn];
//http://www.cnblogs.com/nicetomeetu/p/7248040.html
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    Init();
    int t;si(t);
    for(int ks=1;ks<=t;ks++)
    {
        mem(sum);int n;si(n);
        for(int i=1;i<=n;i++)
        {
            si(a[i]);
            sum[a[i]]++;
        }
        int mx=a[1],mn=a[1];
        for(int i=2;i<=n;i++)
        {
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        for(int i=1;i<=mx;i++) sum[i]+=sum[i-1];
        LL ans=0;
        for(int i=2;i<=mn;i++)
        {
            if(!mu[i]) continue;
            LL res=1;
            int j=min(i,mx);int k=min((i<<1)-1,mx);
            for(int l=1;;l++)
            {
                if(sum[k]-sum[j-1])
                    res=res*fpow(l,sum[k]-sum[j-1])%mod;
                if(k==mx) break;
                j+=i;k+=i;
                k=min(k,mx);
            }
            ans=(ans+mu[i]*res)%mod;
            if(ans<0) ans=(ans+mod)%mod;
        }
        printf("Case #%d: %I64d\n",ks,ans);
    }
    return 0;
}
