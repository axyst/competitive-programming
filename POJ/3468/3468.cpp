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
#define LL long long
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=100005;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
LL lazy[MAXNODES<<2];
LL sum[MAXNODES<<2];
void pushup(int rt)
{
    sum[rt]=(sum[rt<<1]+sum[(rt<<1)|1]);
}
void pushdown(LL rt,LL m)
{
    if(lazy[rt])
    {
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        sum[rt<<1]+=(m-(m>>1))*lazy[rt];
        sum[rt<<1|1]+=(m>>1)*lazy[rt];
        lazy[rt]=0;
    }
}
void build(LL l,LL r,LL rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        scanf("%I64d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(LL L,LL R,LL c,LL l,LL r,LL rt)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]+=c;
        sum[rt]+=c*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt);
}
LL query(LL L,LL R,LL l,LL r,LL rt)
{
    if(L<=l&&r<=R) return sum[rt];
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    LL ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    return ret;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n,q;
    char tmp;
    LL a,b,c;
    memset(lazy,0,sizeof(lazy));
    memset(sum,0,sizeof(sum));
    scanf("%d%d",&n,&q);
    build(1,n,1);
    while(q--)
    {
        scanf("%*c%c",&tmp);
        if(tmp=='Q')
        {
            scanf("%I64d%I64d",&a,&b);
            printf("%I64d\n",query(a,b,1,n,1));
        }
        else
        {
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
    }
    return 0;
}