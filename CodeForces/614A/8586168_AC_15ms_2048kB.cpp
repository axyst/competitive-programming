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
const int MAXN=1e3+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
LL dp[500];
LL out[500];
int main()
{
    //freopen("test.txt","r",stdin);
    LL l,r,k;scanf("%I64d%I64d%I64d",&l,&r,&k);
    dp[0]=1;int cnt=1;
    bool flag=1;bool oflag=0;
    if(l==1) oflag=1;
    while(dp[cnt]<1e18)
    {
        dp[cnt]=dp[cnt-1]*k;
        if(dp[cnt]>=l&&dp[cnt]<=r)
        {
            //printf("%I64d ",dp[cnt]);
            out[cnt]=dp[cnt];
            flag=0;
        }
        LL x=1e18/k;
        if(dp[cnt]>x) break;
        if(dp[cnt]>r) break;
        cnt++;
    }
    if(oflag) printf("1 ");
    else if(flag) {printf("-1\n");return 0;}
    rel(i,cnt)
    {
        if(out[i])printf("%I64d ",out[i]);
    }
    return 0;
}
