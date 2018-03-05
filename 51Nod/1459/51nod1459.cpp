#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=600+5;
int d[maxn][maxn];
int out[maxn][maxn];
int p[maxn];
int n,m,s,e;
void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]<INF&&d[k][j]<INF)
                {
                    if(d[i][k]+d[k][j]<d[i][j])
                    {
                        d[i][j]=d[i][k]+d[k][j];
                        out[i][j]=out[i][k]+out[k][j]-p[k];
                    }
                    else if(d[i][k]+d[k][j]==d[i][j])
                        out[i][j]=max(out[i][k]+out[k][j]-p[k],out[i][j]);
                }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   while(scanf("%d%d%d%d",&n,&m,&s,&e)==4)
    {
        int a,b,c;
        for(int i=0;i<n;i++) {scanf("%d",p+i);out[i][i]=p[i];}
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) if(i==j) d[i][j]=0;else d[i][j]=INF;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            d[a][b]=d[b][a]=c;
            out[a][b]=out[b][a]=p[a]+p[b];
        }
        floyd();
        printf("%d %d\n",d[s][e],out[s][e]);
    }
    return 0;
}