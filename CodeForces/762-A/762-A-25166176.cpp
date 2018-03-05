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
const long long MAXN=1e6+5;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
LL out[MAXN];
int main()
{
    LL n,k;
    int cnt=0;
    scanf("%I64d%I64d",&n,&k);
    for(LL i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            out[++cnt]=i;
            if(cnt==k)
            {
                printf("%I64d\n",i);
                return 0;
            }
        }
        if(i*i==n)
        {
            if(k>cnt*2-1) printf("-1\n");
            else  printf("%I64d\n",n/out[2*cnt-k]);
            return 0;
        }
    }
    if(k>cnt*2) printf("-1\n");
    else  printf("%I64d\n",n/out[2*cnt-k+1]);
    return 0;
}