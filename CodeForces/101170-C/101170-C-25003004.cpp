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
const long long MAXN=100005;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
struct shield
{
    double l;
    double r;
    double fac;
}input[105];
bool cmp(shield a,shield b)
{
    return a.l<b.l;
}
int main()
{
    double x,y;
    scanf("%lf%lf",&x,&y);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&input[i].l,&input[i].r);
        scanf("%lf",&input[i].fac);
   }
    sort(input,input+n,cmp);
    double sum=0,lr=0;
    for(int i=0;i<n;i++)
    {
        sum+=(input[i].l-lr);
        lr=input[i].r;
        sum+=input[i].fac*(input[i].r-input[i].l);
    }
    sum+=(y-input[n-1].r);
    //cout<<sum<<endl;
    double ans=x/sum;
    printf("%lf\n",ans);
    return 0;
}
close