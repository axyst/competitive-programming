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
const long long MAXN=100+5;
typedef vector<int> vi; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int dp[MAXN][3];
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    rep(i,n) scanf("%d",a+i);
    if(a[0]==1||a[0]==3) dp[0][1]=1;
    if(a[0]==2||a[0]==3) dp[0][2]=1;
    rep(i,n)
    {
        dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        if(a[i]==1||a[i]==3)
        {
            dp[i][1]=max(dp[i-1][2],dp[i-1][0])+1;
        }
        if(a[i]==2||a[i]==3)
        {
            dp[i][2]=max(dp[i-1][1],dp[i-1][0])+1;
        }
    }
    int ans=max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    printf("%d\n",n-ans);
    return 0;
}
