#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[50];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=1;i-j>=1&&j<=m;j++) dp[i]+=dp[i-j];//注意i-j>=1
        printf("%d\n",dp[n]);
    }
    return 0;
}