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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fint;
//const int MAXN=1e4+5;const int MOD=1e9+7;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long int;
const int MAXNODES=1<<17;
int a[MAXNODES<<2];
int op[MAXNODES<<2];
int spow(int x)
{
    int ret=1;
    rep(i,x) ret<<=1;
    return ret;
}
void pushup(int rt)
{
    if(!op[rt])a[rt]=(a[rt<<1]^a[(rt<<1)|1]);
    else a[rt]=(a[rt<<1]|a[(rt<<1)|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&a[rt]);
        op[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    if(!op[rt<<1]) op[rt]=1;
    else op[rt]=0;
    pushup(rt);
}
void update(int p,int q,int l,int r,int rt)
{
    if(l==r)
    {
        a[rt]=q;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,q,lson);
    else update(p,q,rson);
    pushup(rt);
}/*
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r) return a[rt];
    int m=(l+r)>>1,ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    return ret;
}*/
int main()
{
    //freopen("test.txt","r",stdin);
    int n,m,t1,t2;
    scanf("%d%d",&n,&m);
    n=spow(n);
    build(1,n,1);
    rep(i,m)
    {
        scanf("%d%d",&t1,&t2);
        update(t1,t2,1,n,1);
        printf("%d\n",a[1]);
    }
    return 0;
}