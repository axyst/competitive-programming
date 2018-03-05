#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#define long long LL
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,n) for(int (i)=(l);(i)<(int)(n);++(i))
#define reu(i,l,n) for(int (i)=(l);(i)<=(int)(n);++(i))
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=101;
int col[MAXN][MAXN][MAXN];
int n,m,maxc;
void floyd()
{
    rel(k,n)
    rel(i,n)
    rel(j,n)
    {
        rel(q,maxc)
        {
        if(!col[i][k][q]||!col[k][j][q]) continue;
        if(!col[i][j][q])
        {
            col[i][j][q]=1;
            col[j][i][q]=1;
        }
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    //memset(col,0,sizeof(col));
    scanf("%d%d",&n,&m);
    int a,b,c;
    maxc=-1;
    rel(i,m)
    {
        scanf("%d%d%d",&a,&b,&c);
        col[a][b][c]=1;
        col[b][a][c]=1;
        maxc=max(maxc,c);
    }
    floyd();
    int q;
    scanf("%d",&q);
    int u,v;
    rel(i,q)
    {
        scanf("%d%d",&u,&v);
        int ans=0;
        rel(j,maxc)
            if(col[u][v][j]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
