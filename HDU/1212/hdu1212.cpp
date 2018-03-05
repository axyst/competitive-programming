#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1000+5;
char str[maxn];
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int mod;
    while(scanf("%s%d",str,&mod)!=EOF)
    {
        int len=strlen(str);
        int now=0;
        for(int i=0;i<len;i++)
            now=(now*10+str[i]-'0')%mod;
        printf("%d\n",now);
    }
    return 0;
}
