#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f;
int pic[105][105];
int use[105],power[105],dp[1000005];
bool vis[105];
int n;
void dij()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++) use[i]=pic[0][i];
    for(int i=0;i<=n;i++)
    {
        int tem=INF,pos=-1;
        for(int j=0;j<=n;j++)
            if(!vis[j]&&tem>use[j]) tem=use[pos=j];
        if(pos==-1) break;
        vis[pos]=1;
        for(int j=0;j<=n;j++)
            if(use[j]>use[pos]+pic[pos][j])
                use[j]=use[pos]+pic[pos][j];
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,m,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                pic[i][j]=(i==j?0:INF);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<pic[a][b])
                pic[a][b]=pic[b][a]=c;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&power[i]);
            sum+=power[i];
        }
        dij();//最短路求出0到每个发电站的油耗量
        for(int i=1;i<=sum;i++) dp[i]=INF;
        dp[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=sum;j>=power[i];j--)
                dp[j]=min(dp[j],dp[j-power[i]]+use[i]);//01背包找出最小油耗量
        int x=sum/2+1;//必须大于一半
        int mn=INF;
        for(int i=x;i<=sum;i++)
            mn=min(dp[i],mn);
        if(mn==INF) printf("impossible\n");
        else printf("%d\n",mn);
    }
    return 0;
}