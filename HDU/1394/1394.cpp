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
const int MAXNODES=5005;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int b[MAXNODES];
int a[MAXNODES<<2];
int max(int a,int b)
{
    return a>b?a:b;
}
void pushup(int now)
{
    a[now]=(a[now<<1]+a[(now<<1)|1]);
}
void build(int l,int r,int now)
{
    if(l==r)
    {
        a[now]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(now);
}
void update(int p,int l,int r,int now)
{
    if(l==r)
    {
        a[now]++;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(p,lson);
    else update(p,rson);
    pushup(now);
}
int query(int L,int R,int l,int r,int now)
{
    if(L<=l&&R>=r) return a[now];
    int mid=(l+r)>>1,ret=0;
    if(L<=mid) ret+=query(L,R,lson);
    if(R>mid) ret+=query(L,R,rson);
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0,ans;
        build(0,n-1,1);
        rep(i,n)
        {
            scanf("%d",&b[i]);
            sum+=query(b[i]+1,n-1,0,n-1,1);
            update(b[i],0,n-1,1);
        }
        ans=sum;
        rep(i,n)
        {
            sum+=(n-1-2*b[i]);
            if(sum<ans) ans=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}