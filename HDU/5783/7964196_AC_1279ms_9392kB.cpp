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
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=200005;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const int mx=1e6+5;
LL a[mx];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        rel(i,n) scanf("%I64d",a+i);
        LL sum=0;
        for(int i=n;i>0;i--)
        {
            if(a[i]>=0) sum++;
            else a[i-1]+=a[i];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
