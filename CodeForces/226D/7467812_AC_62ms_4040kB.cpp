///brute force
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
const long long MAXN=1000+5;
typedef vector<int> vi; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int t[MAXN][MAXN];int r[MAXN*10];int c[MAXN*10];
///r,c is the mark of reversal
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,n) rep(j,m) scanf("%d",&t[i][j]);
    int flag=1;
    rep(k,300)//can't use flag??
    {
        rep(i,n)
        {
            int sum=0;
            rep(j,m) sum+=t[i][j];
            if(sum<0)
            {
                r[i]^=1;
                rep(j,m) t[i][j]*=-1;
            }
        }
        rep(i,m)
        {
            int sum=0;
            rep(j,n) sum+=t[j][i];
            if(sum<0)
            {
                c[i]^=1;
                rep(j,n) t[j][i]*=-1;
            }
        }
    }
    int cnt=0;
    rep(i,n) if(r[i]) cnt++;
    printf("%d ",cnt);
    rep(i,n) if(r[i]) printf("%d ",i+1);
    printf("\n");
    cnt=0;
    rep(i,m) if(c[i]) cnt++;
    printf("%d ",cnt);
    rep(i,m) if(c[i]) printf("%d ",i+1);
    printf("\n");
    return 0;
}
