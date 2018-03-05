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
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=10005;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int main()
{
    int t;LL n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        LL l=0,r=2e9,mid,sum,ans;
        while(l<=r)
        {
            mid=(l+r)/2;
            sum=(1+mid)*mid/2;
            if(sum<=n) ans=sum,l=mid+1;
            else r=mid-1;
        }
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}
