#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1005;const int INF=0x3f3f3f3f;int c,s,q;
int d[maxn][maxn];
void floyd(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]<INF&&d[k][j]<INF)
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
}
int main()
{
    //freopen("test.txt","r",stdin);
    int x,y,z;int ks=0;
    while(scanf("%d%d%d",&c,&s,&q)==3&&c)
    {
        if(ks) printf("\n");
        printf("Case #%d\n",++ks);
        for(int i=0;i<c;i++)
        for(int j=i;j<c;j++)
            if(i==j) d[i][i]=0;
            else d[i][j]=d[j][i]=INF;
        for(int i=0;i<s;i++)
        {
            scanf("%d%d%d",&x,&y,&z);x--,y--;//注意标号从1开始
            d[x][y]=min(d[x][y],z);
            d[y][x]=d[x][y];
        }
        floyd(c);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);x--,y--;
            if(d[x][y]!=INF) printf("%d\n",d[x][y]);
            else printf("no path\n");
        }
    }
    return 0;
}
