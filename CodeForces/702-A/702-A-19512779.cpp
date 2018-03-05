#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[100050];
int a[100050];
int main()
{
    int n,M=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int j=i-1;
        if(a[i]>a[j]) dp[i]=dp[j]+1;
        else dp[i]=1;
        M=max(M,dp[i]);
    }
    printf("%d\n",M);
    return 0;
}