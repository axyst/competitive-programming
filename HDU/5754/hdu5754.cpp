#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1005;
int d[2005][2005];
int h[maxn][maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(d,0,sizeof(d));
    memset(h,0,sizeof(h));
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
        if(d[i][j]==0)
            for(int k=1;k<=1000;k++)
            {
                d[i+k][j+k]=1;
                 d[i][j+k]=1;
                  d[i+k][j]=1;
            }
    for(int i=1000;i>=3;i=i-3)
    {
        h[i][i]=1;
        h[i-2][i-1]=2;
        h[i-1][i-2]=2;
    }
    int t,op,n,m;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&op,&n,&m);
        int flag=-1;
        if(op==1)
        {
            if(m&1&&n&1) flag=0;
            else flag=1;
        }
        else if(op==2)
        {
            if(n==m) flag=0;
            else flag=1;
        }
        else if(op==3)
        {
            if(h[n][m]==0) flag=2;
            if(h[n][m]==1) flag=0;
            if(h[n][m]==2) flag=1;
        }
        else if(op==4)
        {
            if(!d[n][m]) flag=0;
            else flag=1;
        }
        if(flag==0) printf("G\n");
        if(flag==1) printf("B\n");
        if(flag==2) printf("D\n");
    }
    return 0;
}
