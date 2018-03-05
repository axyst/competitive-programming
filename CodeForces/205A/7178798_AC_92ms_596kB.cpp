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
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=100005;const int MOD=1e9+7;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
struct town
{
    int id;
    int num;
}in[MAXN];
bool cmp(town a,town b)
{
    return a.num<b.num;
}
int main()
{
    int n;
    scanf("%d",&n);
    rep(i,n)
    {
        scanf("%d",&in[i].num);
        in[i].id=i;
    }
    sort(in,in+n,cmp);
    rel(i,n-1)
    {
        if(in[i].num==in[0].num)
        {
            printf("Still Rozdil\n");
            return 0;
        }
    }
    printf("%d",in[0].id+1);
    return 0;
}
