#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=100000+5;
const int mod=1e9+7;
char str[maxn];
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
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    while(~scanf("%s",str))
    {
        int len=strlen(str);
        LL now=0;
        for(int i=0;i<len;i++)
            now=(now*10+str[i]-'0')%(mod-1);

        printf("%I64d\n",fpow(2,now-1));
    }
    return 0;
}