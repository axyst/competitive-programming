#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[500050];
int dp[500050];
const int INF=0x3f3f3f3f;
int main()
{
    int n,ca=1;
    while(scanf("%d",&n)!=EOF)
    {
        int t1,t2;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&t1,&t2);
            a[t1]=t2;
        }
        fill(dp,dp+n,INF);
        for(int i=1;i<=n;i++) *lower_bound(dp,dp+n,a[i])=a[i];
        int j=lower_bound(dp,dp+n,INF)-dp;
        printf("Case %d:\n",ca++);
        if(j==1) printf("My king, at most 1 road can be built.\n");
        else printf("My king, at most %d roads can be built.\n",j);
        printf("\n");
    }
    return 0;
}