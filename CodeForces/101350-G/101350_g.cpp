#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MAXN=100000+5;
LL x[25];LL y[25];
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
        LL n,m;int k;scanf("%I64d%I64d%d",&n,&m,&k);
        for(int i=0;i<k;i++) scanf("%I64d%I64d",x+i,y+i);
        int upper=1<<k;LL ans=(n+1)*n/2*(m+1)*m/2;
        for(int i=1;i<upper;i++)
        {
            int cur=i;int oe=0;
            LL mnx=inf,mny=inf,mxx=-1,mxy=-1;
            while(cur){oe+=(cur&1);cur>>=1;}
            for(int j=0;j<k;j++)
            {
                if((i>>j)&1)
                {
                    mnx=min(mnx,x[j]);
                    mny=min(mny,y[j]);
                    mxx=max(mxx,x[j]);
                    mxy=max(mxy,y[j]);
                }
            }
            LL now=mnx*mny*(n-mxx+1)*(m-mxy+1);
            if(oe&1) ans-=now;
            else ans+=now;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}