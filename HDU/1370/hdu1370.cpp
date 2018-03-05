#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1000+5;
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int n;scanf("%d\n",&n);int ks=1;
    int a,b,c,d;
    while(n--)
    {
        if(ks>1) printf("\n");
        while(scanf("%d%d%d%d",&a,&b,&c,&d))
        {
            if(a==-1&&b==-1&&c==-1&&d==-1) break;
            int e=a+1;
            while((e-a)%23) e++;
            while((e-b)%28) e+=23;
            while((e-c)%33) e+=23*28;
            e-=d;
            printf("Case %d: the next triple peak occurs in %d days.\n",ks++,e);
        }
    }
    return 0;
}
