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
int main()
{
    int n;
    scanf("%d",&n);
    int a=0,b=0;
    rep(i,n)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        if(t1>t2) a++;
        if(t2>t1) b++;
    }
    if(a>b) printf("Mishka\n");
    else if(b>a) printf("Chris\n");
    else printf("Friendship is magic!^^\n");
    return 0;
}
