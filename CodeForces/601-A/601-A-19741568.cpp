#include<bits/stdc++.h>
using namespace std;
int w[410][410];
int s[410][410];
const int INF=0x3f3f3f3f;
int n,m;
void floyd(int x,int a[410][410])
{
    for(int k=1;k<=x;k++)
        for(int i=1;i<=x;i++)
            for(int j=1;j<=x;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
int main()
{
    scanf("%d%d",&n,&m);
    int t1,t2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                w[i][j]=INF;
                s[i][j]=(i==j?INF:1);
            }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&t1,&t2);
        w[t1][t2]=1;
        w[t2][t1]=1;
        s[t1][t2]=INF;
        s[t2][t1]=INF;
    }
    floyd(n,w);
    floyd(n,s);
    int ans1=w[1][n],ans2=s[1][n];
    //printf("%d %d\n",ans1,ans2);
    if(ans1==INF||ans2==INF) printf("-1\n");
    else printf("%d\n",max(ans1,ans2));
    return 0;
}