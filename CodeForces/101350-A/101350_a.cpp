#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=2*1e5+5;
char str[maxn];
int zeros[maxn];
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        scanf("%s",str);int cnt=1;int zzz=0;
        for(int i=0;i<n;i++)
            if(str[i]=='0') cnt++;
            else zeros[zzz++]=cnt,cnt=1;
        zeros[zzz++]=cnt;
        LL odd=0;LL even=0;
        for(int i=0;i<zzz;i+=2) odd+=zeros[i];
        for(int i=1;i<zzz;i+=2) even+=zeros[i];
        LL ans=odd*even;
        for(int i=0;i<zzz;i++) ans-=2*zeros[i];
        ans+=zeros[0];ans+=zeros[zzz-1];ans+=zzz;ans--;
        printf("%I64d\n",ans);
    }
    return 0;
}