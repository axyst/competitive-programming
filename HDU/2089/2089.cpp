#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
//#include<queue>
//#include<vector>
//#include<set>
using namespace std;
//#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
//#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
//#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
//#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1000000+5;
//const int MOD=1e9+7;
typedef long long LL;
//typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
int dp[7][3];
int digit[7];
int todigit(int n)
{
    int len=0;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    digit[len]=0;
    return len-1;
}
int dfs(int pos,int status,int limit)
{
    if(pos<0) return status!=2;
    if(!limit&&~dp[pos][status]) return dp[pos][status];
    int ans=0;
    int len=limit?digit[pos]:9;
    for(int i=0;i<=len;i++)
    {
        int ts=status;
        if(i==4) ts=2;
        else if(ts==0&&i==6) ts=1;
        else if(ts==1&&i==2) ts=2;
        else if(ts==1&&i!=2&&i!=6) ts=0;
        ans+=dfs(pos-1,ts,limit&&i==len);
    }
    return limit?ans:dp[pos][status]=ans;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)&&a+b)
    {
        memset(dp,-1,sizeof(dp));
        int ans=dfs(todigit(b),0,1)-dfs(todigit(a-1),0,1);
        printf("%d\n",ans);
    }
    return 0;
}