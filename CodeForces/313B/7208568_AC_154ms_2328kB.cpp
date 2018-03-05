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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
char str[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%s",str+1);

    int n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i-1]==str[i]) cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1];
        //printf("%d %d %d\n",cnt[i],cnt[i-1],i);
    }
    //rep(i,n) printf("%d\n",cnt[i]);
    int m,a,b;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cnt[b]-cnt[a]);
    }

}
