#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=29;
LL a[maxn];
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
        scanf("%d",&a[0]);LL tot=a[0];
        LL ans=a[0];
        for(int i=1;i<n;i++)
        {
            scanf("%I64d",a+i);
            tot=gcd(a[i],tot);
            ans+=a[i];
            //cout<<tot<<endl;
        }
        printf("%I64d %I64d\n",ans,tot);
    }
    return 0;
}