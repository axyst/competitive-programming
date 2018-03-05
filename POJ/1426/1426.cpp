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
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=1e6+5;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
bool vis[MAXN];bool flag;
unsigned long long ans;
void dfs(unsigned long long cur,int n,int dep)
{
    if(!flag) return;
    if(cur%n==0){ans=cur;flag=0;return;}
    if(dep>=19) return;
    dfs(cur*10,n,dep+1);
    dfs(cur*10+1,n,dep+1);
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(scanf("%d",&n)&&n)
    {
        flag=1;
        dfs(1,n,0);
        printf("%I64u\n",ans);
    }
    return 0;
}