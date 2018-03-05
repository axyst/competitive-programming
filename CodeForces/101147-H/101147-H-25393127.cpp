#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int dp[15][15][15];

int main()
{
    freopen("commandos.in","r",stdin);
    
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);
        int f,y,x,h;
        int i,j,k;

        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d %d",&f,&y,&x,&h);
            dp[f][y][x]=h;
            
        }


        int Max=0;
        for(i=10;i>=1;i--)
            for(j=1;j<=10;j++)
                for(k=1;k<=10;k++)
                {
                    int t;
                    t=max(dp[i+1][j][k],dp[i][j-1][k]);
                    t=max(t,dp[i][j][k-1]);
                    dp[i][j][k]=dp[i][j][k]+t;
                    if(dp[i][j][k]>Max)
                        Max=dp[i][j][k];
                }

        printf("%d\n",Max);
    }
    return 0;
}