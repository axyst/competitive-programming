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
vci pic[MAXN];
int vis[MAXN];
bool flag;
void dfs(int cur)
{
    if(!flag) return;
    for(int i=0;i<pic[cur].size();i++)
    {
        //cout<<pic[cur][i]<<endl;
        if(!vis[pic[cur][i]])
        {
            vis[pic[cur][i]]=-vis[cur];
            dfs(pic[cur][i]);
        }
        else if(vis[pic[cur][i]]==vis[cur]) {flag=0;return;}
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,n,m,t1,t2;scanf("%d",&t);
    while(t--)
    {
        flag=1;
        scanf("%d%d",&n,&m);
        memset(pic,0,sizeof(pic));
        memset(vis,0,sizeof(vis));
        rep(i,m)
        {
            scanf("%d%d",&t1,&t2);
            pic[t1].push_back(t2);
            pic[t2].push_back(t1);
        }
        vis[t1]=1;
        dfs(t1);
        if(flag) printf("Correct\n");
        else printf("Wrong\n");
    }
    return 0;
}
