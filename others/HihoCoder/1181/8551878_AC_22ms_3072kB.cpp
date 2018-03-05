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
const int MAXN=1e3+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
vector<vector<int> >pic;
vci deg;
vci path;
int pathsize;
int n,m,t1,t2;
void dfs(int cur)
{
    rel(i,n)
    {
        if(!pic[cur][i]) continue;
        pic[cur][i]--;
        pic[i][cur]--;
        dfs(i);
    }
    path.push_back(cur);
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        pathsize=0;
        pic.assign(n+1,vector<int>(n+1,0));
        deg.assign(n+1,0);
        path.clear();
        rep(i,m)
        {
            scanf("%d%d",&t1,&t2);
            pic[t1][t2]++;
            pic[t2][t1]++;
            deg[t1]++;
            deg[t2]++;
        }
        dfs(t1);
        printf("%d",path[0]);
        for(int i=1;i<path.size();i++) printf(" %d",path[i]);
        printf("\n");
    }
    return 0;
}
