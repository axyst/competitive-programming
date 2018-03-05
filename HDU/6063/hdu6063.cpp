#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const LL mod=1e9+7;
const int maxn=1e6+5;
LL fpow(LL a,LL b)
{
    a=a%mod;
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL n,k;LL ks=1;
    while(scanf("%I64d%I64d",&n,&k) != EOF)
    {
        printf("Case #%I64d: %I64d\n",ks++,fpow(n,k));
    }
    return 0;
}
