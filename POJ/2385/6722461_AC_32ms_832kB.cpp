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
int dp[35][1005];//step,time
int tree[1005];
int main()
{
    int t,w,cnt=0;
    scanf("%d%d",&t,&w);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&tree[i]);
        if(tree[i]==1) cnt++;
        dp[0][i]=cnt;
    }
    //for(int i=1;i<=t;i++) printf("%d\n",dp[0][i]);
    for(int i=1;i<=w;i++)
        for(int j=1;j<=t;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]);
            if(i%2==0&&tree[j]==1) dp[i][j]++;
            else if(i%2!=0&&tree[j]==2) dp[i][j]++;
        }
    dp[w][t]=max(dp[w][t],dp[0][t]);
    printf("%d\n",dp[w][t]);
    return 0;
}
