#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
LL fact[1000],C[35][35],dp[35][35];
int main()
{
    int n=11;
    fact[0]=1;
    for(int i=1;i<=n*n;++i) fact[i]=fact[i-1]*3%MOD;
    C[0][0]=1;
    for(int i=1;i<35;++i)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;++j)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    for(int i=1;i<=10;++i)
    {
        for(int j=0;j<=10;++j)
        {
            dp[i][j]=fact[i*j];
            if(i==1&&j==0) dp[i][j]=1;
            for(int ii=1;ii<=i;++ii)
            {
                for(int jj=0;jj<=j;++jj)
                {
                    if(i==ii&&j==jj) continue;
                    dp[i][j]-=C[i-1][ii-1]*C[j][jj]%MOD*dp[ii][jj]%MOD*fact[(i-ii)*(j-jj)]%MOD;
                    dp[i][j]=(dp[i][j]%MOD+MOD)%MOD;
                }
            }
        }
    }
    int m;
    while(~scanf("%d%d",&n,&m)) printf("%I64d\n",dp[n][m]);
    return 0;
}
