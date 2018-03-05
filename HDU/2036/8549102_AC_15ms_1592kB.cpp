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
const int MAXN=1e3*2+10;const long long MOD=1e9+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double eps=1e-6;
struct point
{
    double x,y;
}p[105];
double xmult(point p1,point p2,point p0)
{
    return(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0) return 0;
        double sum=0;
        rel(i,n) scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=2;i<n;i++)
        {
            double x=xmult(p[1],p[i],p[i+1])*0.5;
            sum+=x;
        }
        printf("%.1lf\n",sum);
    }
    return 0;
}