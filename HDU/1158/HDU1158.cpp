#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1000+5;int n;
int dp[15][maxn];int num[15];
int main()
{
    //freopen("test.txt","r",stdin);
    while(scanf("%d",&n)==1&&n)
    {
        int mx=-1;
        int add,sal,sub;
        scanf("%d%d%d",&add,&sal,&sub);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",num+i);
            mx=max(mx,num[i]);
        }
        for(int j=0;j<=mx;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=num[i];j<=mx;j++) dp[i][j]=INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=num[i];j<=mx;j++)//这月的人数
            {
                if(i==1) {dp[i][j]=(sal+add)*j;continue;}
                for(int k=num[i-1];k<=mx;k++)//上月的人数
                {
                    if(j>k)
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(j-k)*add+j*sal);
                    }
                    else
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+(k-j)*sub+j*sal);
                    }
                }
            }
        }
        int out=INF;
        for(int i=num[n];i<=mx;i++)
            out=min(out,dp[n][i]);
        printf("%d\n",out);
    }
    return 0;
}
