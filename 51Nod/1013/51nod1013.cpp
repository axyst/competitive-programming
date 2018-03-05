#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL mod=1000000007;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    LL d=exgcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-a/b*y;
    return d;
}
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
    LL n,x,y;
    while(scanf("%I64d",&n)==1)
    {
        LL ans=fpow(3,n+1)-1;
        exgcd(2,mod,x,y);//模mod下除以2 等价于 乘以2对mod的逆元
        while(x<0) x+=mod;
        printf("%I64d\n",ans*x%mod);
    }
    return 0;
}