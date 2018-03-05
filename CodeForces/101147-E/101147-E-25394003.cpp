#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1e5+10;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
vci dp[MAXN];
int a[MAXN];
int out[MAXN];
int vis[MAXN];
void bfs(int n)
{
    queue<int>q;
    q.push(n);
    memset(vis,0,sizeof(vis));
    memset(out,-1,sizeof(out));
    vis[n]=1;out[n]=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        int sz=dp[f].size();
        for(int i=0;i<sz;i++)
        {
            int nx=dp[f][i];
            if(!vis[nx]&&
               (nx+a[nx]==f||nx-a[nx]==f))
            {
                vis[nx]=1;
                out[nx]=out[f]+1;
                q.push(nx);
            }
        }
    }
}
int main()
{
    freopen("jumping.in","r",stdin);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            dp[min(n,i+a[i])].push_back(i);
            dp[max(0,i-a[i])].push_back(i);
        }
        bfs(n);
        for(int i=1;i<=n;i++)  printf("%d\n",out[i]);
    }
    return 0;
}