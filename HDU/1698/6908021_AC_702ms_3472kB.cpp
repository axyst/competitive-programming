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
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fint;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=100005;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long int;
int lazy[MAXNODES<<2];
int sum[MAXNODES<<2];
void pushup(int rt)
{
    sum[rt]=(sum[rt<<1]+sum[(rt<<1)|1]);
}
void pushdown(int rt,int m)
{
    if(lazy[rt])
    {
        lazy[rt<<1]=lazy[rt];
        lazy[rt<<1|1]=lazy[rt];
        sum[rt<<1]=(m-(m>>1))*lazy[rt];
        sum[rt<<1|1]=(m>>1)*lazy[rt];
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    sum[rt]=1;
    if(l==r) return;
    delf;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]=c;
        sum[rt]=c*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    delf;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt);
}
int main()
{
    //freopen("test.txt","r",stdin);
    int k,n,t,a,b,c;
    scanf("%d",&k);
    rel(i,k)
    {
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
    }
    return 0;
}