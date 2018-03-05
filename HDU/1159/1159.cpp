#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1015;
const int INF=0x3f3f3f3f;
int dp[MAXN][MAXN];
char a[MAXN],b[MAXN];
int main()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int l1=strlen(a);int l2=strlen(b);
        for(int i=1;i<=l1;i++)
            for(int j=1;j<=l2;j++)
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        printf("%d\n",dp[l1][l2]);
    }
}