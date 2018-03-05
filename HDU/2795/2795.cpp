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
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=4000001;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int a[MAXNODES],b[MAXNODES];
int h,w,n;
int max(int a,int b)
{
    return a>b?a:b;
}
void pushup(int now)
{
    a[now]=max(a[now<<1],a[(now<<1)+1]);
}
void build(int l,int r,int now)
{
    if(l==r)
    {
        a[now]=w;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,now<<1);
    build(mid+1,r,(now<<1)+1);
    pushup(now);
}
void update(int p,int q,int l,int r,int now)
{
    if(l==r)
    {
        a[now]-=q;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(p,q,l,mid,now<<1);
    else update(p,q,mid+1,r,(now<<1)+1);
    pushup(now);
}
int query(int k,int l,int r,int now)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    int ans=0;
    if(a[now]>=k)
    {
        if(a[now<<1]>=k) ans=query(k,l,mid,now<<1);
        else ans=query(k,mid+1,r,(now<<1)+1);
    }
    else ans=0;
    return ans;
}
int main()
{
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        if(h>n) h=n;
        build(1,h,1);
        rep(i,n)
        {
            scanf("%d",&b[i]);
            if(a[1]<b[i]) {printf("-1\n");continue;}
            int k=query(b[i],1,h,1);
            printf("%d\n",k);
            update(k,b[i],1,h,1);
        }
    }
    return 0;
}