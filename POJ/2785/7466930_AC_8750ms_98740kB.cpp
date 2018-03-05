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
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=4000+5;
typedef vector<int> vi; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
LL a[MAXN],b[MAXN],c[MAXN],d[MAXN];
LL e[MAXN*MAXN],f[MAXN*MAXN];
int main()
{
    int n;
    LL cnt=0;LL ans=0;
    LL temp;
    scanf("%d",&n);
    rep(i,n) scanf("%I64d%I64d%I64d%I64d",a+i,b+i,c+i,d+i);
    rep(i,n) rep(j,n)
    {
        e[cnt]=a[i]+b[j];
        f[cnt]=c[i]+d[j];
        cnt++;
    }
    sort(f,f+cnt);
    rep(i,cnt) ans+=(upper_bound(f,f+cnt,-e[i])-lower_bound(f,f+cnt,-e[i]));
    printf("%I64d\n",ans);
    return 0;
}
