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
const int MAXNODES=4000001;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int c[MAXNODES];
int aa[MAXNODES];
struct Node{
   int v;
   int order;
}in[MAXNODES];
int n;
int lowbit(int x)
{
    return x&(-x);
}

void update(int t,int value)
{
    for(int i=t;i<=n;i+=lowbit(i))
    {
        c[i]+=value;
    }
}
int getsum(int x)
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
    while(scanf("%d",&n)!=EOF&&n)
    {
        //离散化
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&in[i].v);
            in[i].order=i;
        }
        sort(in+1,in+n+1,cmp);
        for(int i=1;i<=n;i++) aa[in[i].order]=i;
        //树状数组求逆序
        memset(c,0,sizeof(c));
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            update(aa[i],1);
            ans+=i-getsum(aa[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}