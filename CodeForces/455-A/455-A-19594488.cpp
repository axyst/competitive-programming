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
#define LL long long
using namespace std;
LL a[100005];
LL dp[100005];
int main()
{
//freopen("test.txt","r",stdin);
    int n,tmp,ma=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&tmp);
        a[tmp]++;
        ma=max(ma,tmp);
    }
    dp[0]=0,dp[1]=a[1];
    for(int i=2;i<=ma;i++) dp[i]=max(dp[i-1],dp[i-2]+a[i]*i);
    printf("%I64d\n",dp[ma]);
return 0;
}