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
#define LL long long
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
//const int MAXN=1e4+5;const int MOD=1e9+7;
const int MAXNODES=20005;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
LL cnt[MAXNODES];
LL s[MAXNODES];
struct Node{
   int v;
   int x;
}in[MAXNODES];
int n;
int lowbit(int x)
{
    return x&(-x);
}

void update(LL *c,int t,int value)
{
    for(int i=t;i<=MAXNODES;i+=lowbit(i))
    {
        c[i]+=value;
    }
}
int getsum(LL *c,int x)
{
    int temp=0;
    for(int i=x;i>=1;i-=lowbit(i))
    {
        temp+=c[i];
    }
    return temp;
}
bool cmp(Node a ,Node b)
{
    return a.v<b.v;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        rep(i,n) scanf("%d%d",&in[i].v,&in[i].x);
        sort(in,in+n,cmp);
        memset(cnt,0,sizeof(cnt));
        memset(s,0,sizeof(s));
        LL ans=0,tot=0;
        rep(i,n)
        {
            update(cnt,in[i].x,1);
            update(s,in[i].x,in[i].x);
            tot+=in[i].x;
            LL s1=getsum(cnt,in[i].x);
            LL s2=getsum(s,in[i].x);
            ans+=in[i].v*(s1*in[i].x-s2-in[i].x*(i+1-s1)+tot-s2);
        }
        printf("%I64d",ans);
    }
    return 0;
}