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
int a[5000];
int vis[5000];
int main()
{
    int t;
    LL a,b,c,m,n,mx,mn;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld%lld%lld",&n,&m,&a,&b,&c);
        if(a<c) swap(a,c);
        LL large=max(a,b),small=min(b,c);
        if(b>=a-b+c) mx=large*(n-m-1)+m*b;
        else
        {
            if(m%2==0) mx=large*(n-m-1)+m/2*(a+c);
            else mx=large*(n-m-1)+max(b,c)+(m-1)/2*(a+c);
        }
        if(b<=a-b+c) mn=small*(m-1)+(n-m)*b;
        else
        {
            if((n-m)%2==0) mn=small*(m-1)+(n-m)/2*(a+c);
            else mn=small*(m-1)+min(a,b)+(n-m-1)/2*(a+c);
        }
        printf("Case #%d: %lld %lld\n",i,mx,mn);
    }
    return 0;
}
