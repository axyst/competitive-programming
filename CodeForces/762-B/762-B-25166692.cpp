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
const long long MAXN=3e5+5;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
char op[7];
int one[MAXN];
int two[MAXN];
int three[MAXN];
int main()
{
    int a,b,c,m,tmp;
    int ta=0,tb=0,tc=0,cnt=0;
    LL ans=0;
    scanf("%d%d%d%d",&a,&b,&c,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%s",&tmp,op);
        if(op[0]=='U') one[ta++]=tmp;
        else two[tb++]=tmp;
    }
    sort(one,one+ta);
    sort(two,two+tb);
    ta=min(ta,a),tb=min(tb,b);
    int i;
    for(i=0;i<ta;i++)
    {
        ans+=one[i];
        cnt++;
    }
    while(one[i]!=0) three[tc++]=one[i++];
    for(i=0;i<tb;i++)
    {
        ans+=two[i];
        cnt++;
    }
    while(two[i]!=0) three[tc++]=two[i++];
    sort(three,three+tc);
    tc=min(tc,c);
    for(i=0;i<tc;i++)
    {
        ans+=three[i];
        cnt++;
    }
    printf("%d %I64d\n",cnt,ans);
    return 0;
}