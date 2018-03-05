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
const int MAXNODES=50005;
int msum[MAXNODES<<2];
int lsum[MAXNODES<<2];
int rsum[MAXNODES<<2];
int col[MAXNODES<<2];
int max(int a,int b){return a>b?a:b;}
void pushdown(int rt,int m)
{
    if(col[rt]==-1) return;
    col[rt<<1]=col[rt<<1|1]=col[rt];
    msum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=col[rt]?0:m-(m>>1);
    msum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=col[rt]?0:(m>>1);
    col[rt]=-1;
}
void pushup(int rt,int m)
{
    lsum[rt]=lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1];
    if(lsum[rt]==m-(m>>1)) lsum[rt]+=lsum[rt<<1|1];
    if(rsum[rt]==(m>>1)) rsum[rt]+=rsum[rt<<1];
    msum[rt]=max(lsum[rt<<1|1]+rsum[rt<<1],max(msum[rt<<1],msum[rt<<1|1]));
}
void build(int l,int r,int rt)
{
    msum[rt]=lsum[rt]=rsum[rt]=r-l+1;
    col[rt]=-1;
    if (l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        msum[rt]=lsum[rt]=rsum[rt]=c?0:r-l+1;
        col[rt]=c;
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt,r-l+1);
}
int query(int len,int l,int r,int rt)
{
    if(l==r) return l;
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(msum[rt<<1]>=len) return query(len,lson);
    else if(lsum[rt<<1|1]+rsum[rt<<1]>=len) return m-rsum[rt<<1]+1;
    else return query(len,rson);
}
int main()
{
    int n,m,flag,a,b;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while (m--)
        {
            scanf("%d",&flag);
            if (flag==1)
            {
                scanf("%d",&a);
                if(msum[1]<a) printf("0\n");
                else
                {
                    int id=query(a,1,n,1);
                    printf("%d\n",id);
                    update(id,id+a-1,1,1,n,1);
                }
            }
            else
            {
                scanf("%d%d",&a,&b);
                update(a,a+b-1,0,1,n,1);
            }
        }
    }
    return 0;
}