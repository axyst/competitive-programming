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
const int MAXN=500000+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
struct grid
{
    int x;int y;int n;
}a[5005];
bool cmp(grid a,grid b)
{
    return a.n>b.n;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,m,n,k,tmp;
    scanf("%d",&t);
    
    while(t--)
    {
        int cnt=0;
        scanf("%d%d%d",&m,&n,&k);
        rep(i,m) rep(j,n)
        {
            scanf("%d",&tmp);
            if(tmp)
            {
                a[cnt].x=j;a[cnt].y=i;a[cnt].n=tmp;
                cnt++;
            }
        }
        sort(a,a+cnt,cmp);

        if(k<a[0].y*2+3){printf("0\n");continue;}
        int time=a[0].y+2;int ans=a[0].n;
        for(int i=1;i<cnt;i++)
        {
            time+=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)+1;
            if(time+a[i].y+1>k) break;
            ans+=a[i].n;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}