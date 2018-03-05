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
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fint;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=10005;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long int;
int col[MAXNODES<<4];
int poi[MAXNODES<<2];
int li[MAXNODES],ri[MAXNODES];
bool book[MAXNODES];
void build(int l,int r,int rt)
{
    col[rt]=-1;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
int bin(int g,int m)
{
    int l=0,r=m-1;
    while(r>=l)
    {
        int mid=(l+r)>>1;
        if(poi[mid]==g) return mid;
        else if(poi[mid]>g) r=mid-1;
        else l=mid+1;
    }
}
void pushdown(int rt)
{
    if(col[rt]!=-1)
    {
        col[rt<<1]=col[rt];
        col[rt<<1|1]=col[rt];
        col[rt]=-1;
    }
}

void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        col[rt]=c;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    //pushup(rt);
}
int query(int l,int r,int rt)
{
    //if(L<=l&&r<=R) return poi[rt];
    //pushdown(rt,r-l+1);
    int ret=0;
    if(col[rt]!=-1)
    {
        if(!book[col[rt]])
        {
            book[col[rt]]=1;
            ret++;
        }
        return ret;
    }
    if(l==r) return 0;
    int m=(l+r)>>1;
    ret+=query(lson);
    ret+=query(rson);
    return ret;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int k,n,t,a,b,c;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        int cnt=0;
        rel(i,n)
        {
            scanf("%d%d",&li[i],&ri[i]);
            poi[cnt++]=li[i];
            poi[cnt++]=ri[i];
        }
        sort(poi,poi+cnt);
        int top=1;
        rel(i,cnt)
            if(poi[i]!=poi[i-1])
                poi[top++]=poi[i];
        int tmp=top;
        rel(i,tmp)
            if(poi[i]-poi[i-1]>1)
                poi[top++]=poi[i-1]+1;
        sort(poi,poi+top);
        build(0,top-1,1);
        int c=0;
        rel(i,n)
        {
            int l=bin(li[i],top);
            int r=bin(ri[i],top);
            update(l,r,++c,0,top-1,1);
        }
        memset(book,0,sizeof(book));
        printf("%d\n",query(0,top-1,1));
    }
    return 0;
}