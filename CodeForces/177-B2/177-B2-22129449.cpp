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
const int MAXN=1e5+5;const int MOD=1e9+7;
typedef vector<int> vi; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii; typedef long long LL;
int main()
{
    LL n;
    //n=1e9;
    scanf("%I64d",&n);
    LL cnt=n;
      for(int i=2;i*i<=n;i++)
    while(n!=i)
    {
      if(n%i==0)
      {
        //printf("%d %d\n",i,n/i);
        cnt+=n/i;
        n=n/i;
      }
      else
        break;
    }
    cnt++;
    printf("%I64d\n",cnt);
}