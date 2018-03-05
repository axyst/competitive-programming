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
const long long MAXN=200000+5;
typedef vector<int> vi; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
struct point
{
    int num;
    int pos;
}s[MAXN];
char op[MAXN];
int main()
{
    int n;
    char tmp;
    scanf("%d",&n);
    scanf("%s",op);
    rep(i,n)
    {
        if(op[i]=='R') s[i].pos=0;
        else s[i].pos=1;
    }
    rep(i,n) scanf("%d",&s[i].num);
    //rep(i,n) printf("%d %d\n",s[i].pos,s[i].num);
    int ans=INF;
    rep(i,n-1)
    {
        if(s[i+1].pos==1&&s[i].pos==0)
            ans=min(ans,(s[i+1].num-s[i].num)/2);
        //printf("%d\n",ans);
    }
    if(ans==INF) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
