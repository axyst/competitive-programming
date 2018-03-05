#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=100005;
LL a[maxn];LL dp[maxn];
//up=[(a1+...+an)+2*(¡Æ|ai-aj|)]/n,(i!=j)
LL gcd(LL a,LL b)
{
    return a%b?gcd(b,a%b):b;
}
int main()
{
    LL n;scanf("%I64d",&n);
    LL sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",a+i);
        sum+=a[i];
    }
    sort(a,a+n);
    LL x=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+i*abs(a[i]-a[i-1]);
        x+=dp[i];
    }
    x=2*x+sum;LL y=n;
    LL z=gcd(x,y);
    x/=z;y/=z;
    printf("%I64d %I64d\n",x,y);
    return 0;
}