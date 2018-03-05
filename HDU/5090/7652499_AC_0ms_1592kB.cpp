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
const long long MAXN=10005;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int a[5000];
int vis[5000];
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        memset(vis,0,sizeof(vis));
        rep(i,n)scanf("%d",a+i);
        rep(i,n)
        for(int j=0;;j++)
        {
            if(a[i]>n) break;
            if(!vis[a[i]])
            {vis[a[i]]=1;break;}
            a[i]+=k;
        }
        sort(a,a+n);
        int flag=1;
        rep(i,n)
        {
            if((a[i]-i-1)!=0) {flag=0;break;}
        }
        flag?printf("Jerry\n"):printf("Tom\n");
    }
    return 0;
}
