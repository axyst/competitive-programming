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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define delf int m=(l+r)>>1
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=4000001;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int mx[MAXNODES];
int max(int a,int b)
{
    return a>b?a:b;
}
void pushup(int rt)
{
    mx[rt]=max(mx[rt<<1],mx[(rt<<1)|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&mx[rt]);
        return;
    }
    delf;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int q,int l,int r,int rt)
{
    if(l==r)
    {
        mx[rt]=q;
        return;
    }
    delf;
    if(p<=m) update(p,q,lson);
    else update(p,q,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return mx[rt];
    delf;
    int ans=0;
    if(L<=m) ans=max(ans,query(L,R,lson));
    if(R>m) ans=max(ans,query(L,R,rson));
    return ans;
}
int main()
{
    int n,m,a,b,i;
    char c;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(i=0;i<m;i++)
        {
            scanf("%*c%c%d %d",&c,&a,&b);
            if(c=='Q')
                printf("%d\n",query(a,b,1,n,1));
            else
                update(a,b,1,n,1);
        }
    }
    return 0;
}