#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
//#include<queue>
//#include<vector>
//#include<set>
//#include<map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define delf int m=(l+r)>>1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fint;
//const int MAXN=1e4+5;const int MOD=1e9+7;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long int;
const int MAXNODES=100005;
int mark[MAXNODES<<2];
LL sum[MAXNODES<<2];
LL fi[200];
int cnt,n,m;
void init()
{
    fi[0]=fi[1]=1;
    for (int i=2;i<88;i++)
        fi[i]=fi[i-1]+fi[i-2];
    cnt=87;
    return ;
}

LL getnum(LL s)
{
    int l=1;
    int h=cnt;
    while (l<=h)
    {
        int m=(l+h)>>1;
        if (fi[m]>=s)
            h=m-1;
        else
            l=m+1;
    }
    LL t1=s-fi[l-1];
    LL t2=fi[l]-s;
    if (t1<=t2)
        return fi[l-1];
    else
        return fi[l];
}

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    mark[rt]=0;
    if (mark[rt<<1]==1&&mark[rt<<1|1]==1)
        mark[rt]=1;
    return ;
}


void build(int l,int r,int rt)
{
    sum[rt]=mark[rt]=0;
    if (l==r)
        return ;
    delf;
    build(lson);
    build(rson);
    return ;
}
void update(int k,LL v,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]+=v;
        mark[rt]=0;
        if(sum[rt]==getnum(sum[rt])) mark[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    if(m>=k) update(k,v,lson);
    else update(k,v,rson);
    pushup(rt);
}
void update1(int L,int R,int l,int r,int rt)
{
    if(mark[rt]) return;
    if(l==r)
    {
        sum[rt]=getnum(sum[rt]);
        mark[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) update1(L,R,lson);
    if(R>m) update1(L,R,rson);
    pushup(rt);
    
}
LL query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return sum[rt];
    int m=(l+r)>>1;
    LL ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    return ret;
}
int main()
{
    init();
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while (m--)
        {
            int p,l,r;
            LL k;
            scanf("%d",&p);
            if (p==1)
            {
                scanf("%d%I64d",&l,&k);
                update(l,k,1,n,1);
            }
            else if (p==2)
            {
                scanf("%d%d",&l,&r);
                printf("%I64d\n",query(l,r,1,n,1));
            }
            else
            {
                scanf("%d%d",&l,&r);
                update1(l,r,1,n,1);
            }
        }
    }
}