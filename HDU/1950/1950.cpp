#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=40015;
const int INF=0x3f3f3f3f;
int s[MAXN];
int dp[MAXN];
int main()
{
    int t;int n;int k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            dp[i]=INF;
        }
        for(int i=0;i<n;i++)
        {
            k=lower_bound(dp,dp+n,s[i])-dp;
            dp[k]=s[i];
            ans=max(ans,k+1);
        }
        printf("%d\n",ans);
    }
}