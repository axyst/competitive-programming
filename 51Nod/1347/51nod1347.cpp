#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1000000+5;
const int MOD=1e9+7;
char str[maxn];
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
        if(len&1)
        {
            printf("NO\n");
            goto l1;
        }
        len/=2;
        for(int i=0;i<len;i++)
        {
            if(str[i]!=str[i+len])
            {
                printf("NO\n");
                goto l1;
            }
        }
        printf("YES\n");
        l1:continue;
    }
    return 0;
}
