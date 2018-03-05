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
const long long MAXN=10000+5;
char tem[MAXN];
int cnt[MAXN];
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;

LL bits[70];
int main()
{
    bits[0]=1;
    for(int i=1;i<=62;i++) bits[i]=bits[i-1]<<1;
    int n;
    scanf("%d",&n);
    LL a,b;
    while(n--)
    {
        scanf("%I64d%I64d",&a,&b);
        if(a==b){printf("%I64d\n",a);continue;}
        LL mx=0;LL ans=b;
        for(int i=62;i>=0;i--)
        {
            LL tmp=bits[i];
            if(b&tmp)
            {
                mx+=tmp;
                if(mx-1>=a) ans=max(ans,(mx|(mx-1)));
            }
        }
        printf("%I64d\n",max(mx,ans));
    }
    return 0;
}
