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
const int MAXN=1e4+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
char pic[10][10];
bool vis[10];
int n,k;
int cnt;
int rail;
void dfs(int dep)
{
    if(rail==k){cnt++;return; }
    if(dep==n) return;
    for(int i=0;i<n;i++)
    {
        if(vis[i]||pic[dep][i]!='#') continue;
        vis[i]=1;
        rail++;
        dfs(dep+1);
        vis[i]=0;
        rail--;
    }
    dfs(dep+1);
}
int main()
{
    while(scanf("%d%d",&n,&k)&&(n!=-1&&k!=-1))
    {
        cnt=0;
        rail=0;
        memset(vis,0,sizeof(vis));
        rep(i,n) scanf("%s",&pic[i]);
        dfs(0);
        printf("%d\n",cnt);
    }
    return 0;
}
