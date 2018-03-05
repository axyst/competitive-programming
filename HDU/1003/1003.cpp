#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100050];
int dp[100050];
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        dp[0]=a[0];
        int ma,st,ed;
        ma=dp[0];
        st=ed=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>dp[i-1]+a[i])
            {
                dp[i]=a[i];
            }
            else
            {
                dp[i]=dp[i-1]+a[i];

            }
            //dp[i]=max(a[i],dp[i-1]+a[i]);
            //ma=max(ma,dp[i]);
            if(ma<dp[i]) {ma=dp[i];ed=i;}
        }
        int ans=0;
        for(int i=ed;i>=0;i--)
            {
                ans+=a[i];
                if(ans==ma) st=i;
            }
        printf("Case %d:\n",j);
        printf("%d %d %d\n",ma,st+1,ed+1);
        if(j!=t) printf("\n");
    }
    return 0;
}