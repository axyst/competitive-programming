#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
typedef long long ll;
const int inf=0x3f3f3f3f;
const LL mod=1e9+7;
const int maxn=1e3+5;
LL m[maxn];LL a[maxn];LL n;
LL gcd(LL a,LL b)
{
    while(b)
    {
        LL t=a%b;
        a=b;
        b=t;
    }
    return a;
}
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
LL china(LL l, LL r, LL *m, LL *a)
{
    LL lcm = 1;
    for(LL i = l; i <= r; i++)lcm = lcm/gcd(lcm,m[i])*m[i];
    for(LL i = l+1; i <= r; i++)
    {
        LL A = m[l], B = m[i], d, k1, k2, c = a[i]-a[l];
        exgcd(A,B,d,k1,k2);
        if(c%d)return -1;
        LL mod = m[i]/d;
        LL K = ((k1*c/d)%mod+mod)%mod;
        a[l] = m[l]*K + a[l];
        m[l] = m[l]*m[i]/d;
    }
    if(a[l]==0)return lcm;
    return a[l];
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL aa;
    while(~scanf("%I64d%I64d",&n,&aa)&&aa)
    {
        for(int i=1;i<=n;i++) {sl(m[i]);a[i]=m[i]-aa;}
        printf("%I64d\n",china(1,n,m,a));
    }
    return 0;
}
