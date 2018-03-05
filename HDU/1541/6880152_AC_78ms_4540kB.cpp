#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
//#include<queue>
//#include<vector>
//#include<set>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=400001;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int c[MAXNODES];
int ans[MAXNODES];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int v)
{
    for(int i=x;i>0&&i<=MAXNODES;i+=lowbit(i))
        c[i]+=v;
}
int sum(int x)
{
    int s=0;
    for(int i=x;i>0&&i<=MAXNODES;i-=lowbit(i))
        s += c[i];
    return s;
}
int main()
{
    int x,y,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        memset(c,0,sizeof(c));
        rep(i,n)
        {
            scanf("%d%d",&x,&y);
            ans[sum(x+1)]++;
            add(x+1,1);
        }
        rep(i,n) printf("%d\n",ans[i]);
    }
    return 0;
}
