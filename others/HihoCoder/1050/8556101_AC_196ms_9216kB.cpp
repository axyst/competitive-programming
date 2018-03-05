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
const int MAXN=1e5+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
bool vis[MAXN];
vci pic[MAXN];
int ans;
int bfs(int n)
{
    ans=0;
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(n);
    q.push(0);
    int ret;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        if(!p&&!q.empty())
        {
            ans++;
            q.push(0);
            continue;
        }
        else if(!p) break;
        for(int i=0;i<pic[p].size();i++)
        {
            if(!vis[pic[p][i]])
            {
                q.push(pic[p][i]);
                vis[pic[p][i]]=1;
            }
        }
        ret=p;
    }
    return ret;
}
int main()
{
    int n,t1,t2;scanf("%d",&n);
    rep(i,n-1)
    {
        scanf("%d%d",&t1,&t2);
        pic[t1].push_back(t2);
        pic[t2].push_back(t1);
    }
    bfs(bfs(1));
    printf("%d\n",ans);
    return 0;
}
