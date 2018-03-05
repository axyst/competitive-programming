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
char str[MAXN][MAXN];
int main()
{
    //freopen("test.txt","r",stdin);
    int cnt=-1;int mx=-1;
    while(gets(str[++cnt]))
    {
        int tmp=strlen(str[cnt]);
        mx=max(mx,tmp);
    }
    rep(i,mx+2) printf("*");
    printf("\n");
    int flag=0;
    rep(i,cnt)
    {
        printf("*");
        int len=strlen(str[i]);
        rep(j,(mx-len+flag)/2) printf(" ");
        printf("%s",str[i]);
        rep(j,(mx-len+!flag)/2) printf(" ");
        printf("*\n");
        if((mx-len)%2) flag=!flag;
    }
    rep(i,mx+2) printf("*");
    printf("\n");
    return 0;
}
