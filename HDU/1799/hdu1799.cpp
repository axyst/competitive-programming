#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MAXN=2000+5;
const LL MOD=1007;
LL dp[MAXN][MAXN];
void com()
{
    for(int i=0;i<MAXN;i++){dp[i][i]=1;dp[i][1]=i%MOD;}
    for(int i=2;i<MAXN;i++)
        for(int j=1;j<i;j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
}
//#define LOCAL
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);LL n,m;
    com();
    while(t--)
    {
        scanf("%I64d%I64d",&m,&n);
        printf("%I64d\n",dp[n+1][m+1]);
    }
    return 0;
}

