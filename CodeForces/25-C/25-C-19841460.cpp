#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#define LL long long
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,n) for(int (i)=(l);(i)<(int)(n);++(i))
#define reu(i,l,n) for(int (i)=(l);(i)<=(int)(n);++(i))
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=305;
int n;
int pic[MAXN][MAXN];
void floyd(int a,int b)
{
    rel(i,n)
        rel(j,n)
        {
            pic[i][j]=min(pic[i][j],pic[i][a]+pic[a][j]);
            pic[i][j]=min(pic[i][j],pic[i][b]+pic[b][j]);
            pic[j][i]=pic[i][j];
        }
}
int main()
{
    int all=1;
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    rel(i,n)
        rel(j,n)
    {
        scanf("%d",&pic[i][j]);
    }
    int k,a,b,c;
    scanf("%d",&k);
    rel(i,k)
    {
        scanf("%d%d%d",&a,&b,&c);
        pic[a][b]=min(pic[a][b],c);
        pic[b][a]=pic[a][b];
        floyd(a,b);
        LL ans=0;
        rel(i,n)
            rel(j,n)
            ans+=pic[i][j];
        printf("%I64d\n",ans/2);
    }
    return 0;
}