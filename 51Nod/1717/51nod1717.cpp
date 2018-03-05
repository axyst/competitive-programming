#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=2*1e5+5;
const int MOD=1e9+7;
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL n;
    while(~scanf("%I64d",&n))
    {
        LL tmp=sqrt(n);
        LL ans=n-tmp;
        printf("%I64d\n",ans);
    }
    return 0;
}