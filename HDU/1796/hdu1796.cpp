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
LL a[15];
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
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL n,m;
    while(~scanf("%I64d%I64d",&n,&m))
    {
        n--;LL cnt=1;LL tmp;
        for(int i=0;i<m;i++)
        {
            sl(tmp);
            if(tmp) a[cnt++]=tmp;
        }
        m=cnt-1;LL upper=1<<m;
        LL ans=0;
        for(LL i=1;i<upper;i++)
        {
            LL oe=0;LL lcm=1;
            for(LL j=0;j<m;j++)
            {
                if((i>>j)&1)
                {
                    oe++;
                    lcm=lcm*a[j+1]/gcd(lcm,a[j+1]);
                }
            }
            if(oe&1) ans+=n/lcm;
            else ans-=n/lcm;
        }
        printf("%I64d\n",ans);

    }
    return 0;
}
