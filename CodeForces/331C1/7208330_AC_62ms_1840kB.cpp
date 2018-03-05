#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1005;const int MOD=1e9+7;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
char str[5];
int main()
{
    LL n;
    //n=1e6;
    LL cnt=0;
    scanf("%I64d",&n);
    while(n>0)
    {
        LL cal=n;
        LL mx=-1;
        LL tmp=cal;
        while(cal)
        {
        tmp=cal%10;
        cal/=10;
        mx=max(mx,tmp);
        }
        n-=mx;
        cnt++;
        //printf("%I64d\n",cnt);
    }
    printf("%I64d\n",cnt);


}
