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
const int MAXNODES=50005;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int a[MAXNODES<<2];
void pushup(int rt)
{
    a[rt]=(a[rt<<1]+a[(rt<<1)|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&a[rt]);
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
        a[rt]+=q;
        return;
    }
    delf;
    if(p<=m) update(p,q,lson);
    else update(p,q,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r) return a[rt];
    delf;
    int ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    return ret;
}
int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    rel(i,t)
    {
        printf("Case %d:\n",i);
        scanf("%d",&n);
        build(1,n,1);
        char tmp[10];
        while(scanf("%s",tmp))
        {
            if(tmp[0]=='E') break;
            scanf("%d%d",&a,&b);
            if(tmp[0]=='Q') printf("%d\n",query(a,b,1,n,1));
            if(tmp[0]=='S') update(a,-b,1,n,1);
            if(tmp[0]=='A') update(a,b,1,n,1);
        }
    }
    return 0;
}