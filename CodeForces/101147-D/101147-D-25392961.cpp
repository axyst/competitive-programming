#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=1e5+5;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
LL c(LL mx,LL mn)
{
    LL a=max(mx,mn);
    LL b=min(mx,mn);
    LL ans=1;
    LL time=min(b,a-b);
    LL t2=time;
    //cout<<a<<' '<<time<<endl;
    for(LL i=0;i<t2;i++)
    {
        ans=ans*a;
        a=a-1;
    }
    for(LL i=0;i<t2;i++)
    {
        ans=ans/time;
        time=time-1;
    }
    //cout<<a<<' '<<time<<' '<<ans<<endl;
    return ans;
}
int main()
{
    freopen("popcorn.in","r",stdin);
    LL t;
    scanf("%I64d",&t);
    LL a,b;
    while(t>0)
    {
        scanf("%I64d%I64d",&a,&b);
        printf("%I64d\n",c(a,b));
        t--;
    }
    return 0;
}
close