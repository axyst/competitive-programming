#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
//#include<queue>
//#include<vector>
//#include<set>
using namespace std;
//#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
//#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
//#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
//#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=20000+5;
//const int MOD=1e9+7;
typedef long long LL;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
struct node
{
    int v;
    int next;
}tree[MAXN];
int vis[MAXN],head[MAXN],dp[MAXN][2];
int ptr,n;
void init()
{
    ptr=0;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
}
void addedge(int x,int y)//y is x's son
{
    tree[ptr]=(node){y,head[x]};
    head[x]=ptr++;
}
void treedp(int cur)
{
    vis[cur]=1;
    for(int i=head[cur];i!=-1;i=tree[i].next)
    {
        int v=tree[i].v;
        if(!vis[v])
        {
            treedp(v);
            dp[cur][1]+=dp[v][0];
            dp[cur][0]+=max(dp[v][1],dp[v][0]);
        }
    }
}
int main()
{
    int n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=1;i<=n;i++) scanf("%d",&dp[i][1]);
        while(scanf("%d%d",&a,&b),a+b)
        {
            addedge(a,b);
            addedge(b,a);
        }
        treedp(1);
        printf("%d\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}