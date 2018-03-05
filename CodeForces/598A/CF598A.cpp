#include<bits/stdc++.h>
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int t;si(t);
    while(t--)
    {
        LL n;sl(n);
        LL ans=n*(n+1)/2;
        for(int i=0;(1<<i)<=n;i++)
        {
            ans-=(1<<(i+1));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}