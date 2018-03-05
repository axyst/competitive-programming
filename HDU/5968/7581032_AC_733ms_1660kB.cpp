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
const long long MAXN=10000+5;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        rep(i,n) scanf("%d",a+i);
        int m;
        scanf("%d",&m);
        rep(i,m) scanf("%d",b+i);
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int tmp=0;
            for(int j=i;j<n;j++)
            {
                tmp^=a[j];
                c[cnt]=tmp;//c:xor sum of ai...aj,j=i...n
                d[cnt]=j-i+1;//d:len between j and i
                cnt++;//cnt:sum of subsequences
            }
        }
        for(int i=0;i<m;i++)
        {
            int mn=INF;
            int ans=0;
            for(int j=0;j<cnt;j++)
            {
                if(mn==max(b[i]-c[j],c[j]-b[i])) ans=max(ans,d[j]);
                else if(mn>max(b[i]-c[j],c[j]-b[i]))//for each query,iter cnt,find min,print len
                {
                    mn=max(b[i]-c[j],c[j]-b[i]);
                    ans=d[j];
                }
            }
            printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
