#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int mod=10;
int main()
{
    //freopen("test.txt","r",stdin);
    LL n;
    while(scanf("%I64d",&n)==1)
    {
        LL sub=n/2+n/3+n/5+n/7;
        sub-=(n/6+n/10+n/14+n/15+n/21+n/35);
        sub+=(n/30+n/42+n/70+n/105);
        sub-=(n/210);
        printf("%I64d\n",n-sub);
    }
    return 0;
}
