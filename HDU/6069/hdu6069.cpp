//% gzp dl
#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int maxn=1000000+5;
const LL mod=998244353;
const int inf=0x3f3f3f3f;
LL prime[maxn];bool vis[maxn];
LL cnt,l,r,k;int t;
LL num[maxn];LL ans[maxn];
void Prime(LL n)
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(LL i=2; i<n; i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
        }
        for(LL j=0; j<cnt&&i*prime[j]<n; j++)
        {
            LL k=i*prime[j];
            vis[k]=1;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
bool visit[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    Prime(maxn);
    si(t);
    while(t--)
    {
        mem(visit);
        sl(l);sl(r);sl(k);
        LL n=r-l+1;
        for(LL i=0;i<n;i++)
        {
            num[i]=l+i;//i
            ans[i]=1;//d(i)
        }
        for(LL i=0;i<cnt;i++)//check primes with elements from [l,r]
        {//opposite to checking every elements from [l,r] with primes
            LL pos;
            if(l%prime[i]==0) pos=0;//l has this prime factor,start from l
            else
            {
                pos=prime[i]-(l%prime[i]);//start from pos which has this prime factor
                if(pos>n-1) continue;
            }
            for(LL j=pos;j<n;j+=prime[i])
            {
                LL aa=0;//power of this prime
                visit[j]=1;
                while(num[j]%prime[i]==0)
                {
                    aa++;
                    num[j]/=prime[i];
                }
                ans[j]=(ans[j]*(aa*k+1)%mod)%mod;
            }
        }
        LL tot=0;
        for(LL i=0;i<n;i++)
        {
            if(num[i]!=1)//has large prime(1e6<prime<1e12) which was not divided
            {
                ans[i]=(ans[i]*(1*k+1)%mod)%mod;
            }
            tot=(tot+ans[i])%mod;
        }
        printf("%I64d\n",tot);
    }
    return 0;
}
