#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
int w[maxn];
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
int main()
{
    //freopen("test.txt","r",stdin);
    int t,n,tmp;scanf("%d",&t);
    while(t--)
    {
        LL ans=0;
        LL sub=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",w+i);
            ans+=(LL)(w[i]*w[i]);
            tmp=(w[i]>0?w[i]:-w[i]);
            sub+=(LL)(tmp);
        }
        LL dom=(LL)n;
        ans=dom*ans-(sub*sub);
        LL gg=gcd(ans,dom);
        printf("%I64d/%I64d\n",ans/gg,dom/gg);
    }
    return 0;
}