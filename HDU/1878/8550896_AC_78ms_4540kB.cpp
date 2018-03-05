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
vci pic[MAXN];
bool vis[MAXN];
int deg[MAXN];
void dfs(int cur)
{
    vis[cur]=1;
    for(int i=0;i<pic[cur].size();i++)
    {
        //cout<<pic[cur][i]<<endl;
        if(!vis[pic[cur][i]])
        {
            dfs(pic[cur][i]);
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n,m,t1,t2;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(pic,0,sizeof(pic));
        memset(vis,0,sizeof(vis));
        memset(deg,0,sizeof(deg));
        rep(i,m)
        {
            scanf("%d%d",&t1,&t2);
            pic[t1].push_back(t2);
            pic[t2].push_back(t1);
            deg[t1]++;deg[t2]++;
        }
        dfs(1);
//        rel(i,n)
//        for(int j=0;j<pic[i].size();j++)
//        {
//            cout<<i<<' '<<pic[i][j]<<endl;
//        }
        //rel(i,n) cout<<vis[i]<<endl;
        rel(i,n) if(deg[i]&1){printf("0\n");goto l1;}
        rel(i,n) if(!vis[i]){printf("0\n");goto l1;}
        printf("1\n");
        l1:continue;
    }
    return 0;
}
