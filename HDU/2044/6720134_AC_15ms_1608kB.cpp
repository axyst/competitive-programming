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
int a[100];
long long dp[100][100];
int main()
{
    //freopen("test.txt","r",stdin);
    for(int i=1;i<=50;i++) a[i]=i;
    for(int i=50;i>=1;i--)
        for(int j=i+1;j<=50;j++)
        {
            if(j==i+1) dp[i][j]=1;
            else if(j==i+2) dp[i][j]=2;
            else dp[i][j]=dp[i+1][j]+dp[i+2][j];
        }
        /*
            for(int i=1;i<=50;i++)
                for(int j=i+1;j<=50;j++)
                    printf("%d %d %d\n",i,j,dp[i][j]);*/
    int n;

    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%I64d\n",dp[a][b]);
    }

    return 0;
}
