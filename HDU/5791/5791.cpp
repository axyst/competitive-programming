#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
using namespace std;
/*
设dp[i][j]表示a中前i个和b中前j个并且a[i]==b[j]匹配的子序列个数。
那么dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]
当a[i]=b[j]时，dp[i][j]+=dp[i-1][j-1]+1
*/
long long dp[1005][1005],sum1[1005][1005],sum2[1005][1005];
int a[1005],b[1005];
const long long mod=1000000007;
int main()
{
//freopen("test.txt","r",stdin);
int n,m;
while(scanf("%d%d",&n,&m)!=EOF)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) dp[i][j]=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(a[i]==b[j]) dp[i][j]+=dp[i-1][j-1]+1;
            if(dp[i][j]<0) dp[i][j]+=mod;
            if(dp[i][j]>=mod) dp[i][j]-=mod;
        }
    printf("%I64d\n",dp[n][m]);
}
return 0;
}