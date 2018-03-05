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
    int t,w,next;
}tree[MAXN];
int vis[MAXN],head[MAXN],dp[MAXN][3];
int ptr,n;
void init()
{
    ptr=0;
    memset(dp,0,sizeof(dp));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}
void addedge(int x,int y,int z)
{
    tree[ptr]=(node){y,z,head[x]};
    head[x]=ptr++;
}
void dfs1(int cur)
{
    vis[cur]=1;
    for(int i=head[cur];i!=-1;i=tree[i].next)
    {
        int t=tree[i].t,w=tree[i].w;
        if(!vis[t])
        {
            dfs1(t);
            if(dp[t][2]+w>dp[cur][2])
            {
                dp[cur][0]=max(dp[cur][0],dp[cur][2]);
                dp[cur][1]=t;
                dp[cur][2]=dp[t][2]+w;
            }
            else dp[cur][0]=max(dp[cur][0],dp[t][2]+w);
        }
    }
}
void dfs2(int cur)
{
    vis[cur]=1;
    for(int i=head[cur];i!=-1;i=tree[i].next)
    {
        int t=tree[i].t,w=tree[i].w;
        if(!vis[t])
        {
            if(dp[cur][1]!=t)
            {
                if(dp[cur][2]+w>dp[t][2])
                {
                    dp[t][2]=dp[cur][2]+w;
                    dp[t][1]=cur;
                }
                else dp[t][0]=max(dp[t][0],dp[cur][2]+w);
            }
            else
            {
                if(dp[cur][0]+w>dp[t][2])
                {
                    dp[t][2]=dp[cur][0]+w;
                    dp[t][1]=cur;
                }
                else dp[t][0]=max(dp[t][0],dp[cur][0]+w);
            }
            dfs2(t);
        }
    }
}
int main()
{
    int n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,i,b);
            addedge(i,a,b);
        }
        dfs1(1);
        memset(vis,0,sizeof(vis));
        dfs2(1);
        for(int i=1;i<=n;i++) printf("%d\n",dp[i][2]);
    }
    return 0;
}