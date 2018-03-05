#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

typedef long long LL;
using namespace std;
const int MAXN=200005;
const int MOD=10007;
int thenext[MAXN];
int dp[MAXN];
char a[MAXN];

int main()
{
    int n,len;
    scanf("%d",&n);
    while(n--)
    {
        memset(thenext,0,sizeof(thenext));
        memset(dp,0,sizeof(dp));
        scanf("%d",&len);
        scanf("%s",a+1);
        int j=0;
        for(int i=2;i<=len;i++)
        {
            while(j>0&&a[j+1]!=a[i]) j=thenext[j];
            if(a[j+1]==a[i]) j++;
            thenext[i]=j;
        }
        int ans=0;
        for(int i=1;i<=len;i++)
        {
            dp[i]=dp[thenext[i]]+1;
            ans=(ans+dp[i])%MOD;
        }
        ans%=MOD;
        printf("%d\n",ans);
    }
    return 0;
}