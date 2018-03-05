#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
LL dp[13][13];
LL mul[13];
LL combi(LL n,LL m)
{
    if (n==1||m==0||n==m) return dp[n][m]=1;
    if (dp[n][m]) return dp[n][m];
    return dp[n][m]=(combi(n-1,m-1)+combi(n-1,m));
}
char str[5];
//#define LOCAL
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    mul[1]=1;
    for(LL i=2;i<=10;i++) mul[i]=mul[i-1]*i;
    int t;scanf("%d",&t);
    while(t--)
    {
        LL a,b;
        scanf("%s",str);
        scanf("%I64d%I64d",&a,&b);
        combi(a,b);
        if(str[0]=='A')
            printf("%I64d\n",mul[b]*dp[a][b]);
        else if(str[0]=='C') printf("%I64d\n",dp[a][b]);
    }
    return 0;
}

