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
const int MAXN=1e3+10;const long long MOD=1e9+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
LL dp[1005][1005];
long long  c(LL n,LL m)
{
  if (n==1||m==0||n==m) return dp[n][m]=1;
  if (dp[n][m]) return dp[n][m];
  return dp[n][m]=(c(n-1,m-1)%MOD+c(n-1,m)%MOD+MOD)%MOD;
}
LL fastpow(LL base,LL po)
{
    LL a=1;
    while(po)
    {
        if(po&1) a=((a%MOD)*(base%MOD))%MOD;
        base=((base%MOD)*(base%MOD))%MOD;
        po>>=1;
    }
    return a;
}
int main()
{
    freopen("galactic.in","r",stdin);
    LL t,n,k;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&n,&k);
        if(k>n)
        {
            printf("0\n");
            continue;
        }
        LL ans=0;
        LL flag=1;
        LL tmp;
        for(LL i=0;i<k;i++)
        {
            tmp=c(k,k-i);
            tmp%=MOD;
            tmp*=fastpow(k-i,n);
            tmp%=MOD;
            tmp*=flag;
            if(tmp<0) tmp=(tmp+MOD)%MOD;
            ans+=tmp;
            ans%=MOD;
            if(flag==-1)flag=1;
            else flag=-1;
            //printf("%I64d\n",tmp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}