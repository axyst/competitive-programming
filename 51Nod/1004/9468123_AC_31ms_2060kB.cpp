#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int mod=10;
LL fpow(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
int main()
{
    //freopen("test.txt","r",stdin);
    LL n;
    while(scanf("%I64d",&n)==1) printf("%I64d\n",fpow(n,n));
    return 0;
}
