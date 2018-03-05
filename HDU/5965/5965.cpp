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
char s[MAXN];int dp[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        int ans=0;
        for(int i=0;i<=2&&i<=s[0]-'0';i++)
        {
            dp[0]=i;
            bool flag=1;
            for(int j=1;j<n;j++)
            {
                int num=s[j-1]-'0'-dp[j-1]-dp[j-2];
                if(num>2||num<0)
                {
                    flag=0;
                    break;
                }
                dp[j]=num;
            }
            if(flag&&dp[n-2]+dp[n-1]==s[n-1]-'0')
            {
                int now=1;
                for(int j=0;j<n;j++)
                {
                    if(dp[j]==1) now*=2;
                    now%=MOD;
                }
                ans+=now;ans%=MOD;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}