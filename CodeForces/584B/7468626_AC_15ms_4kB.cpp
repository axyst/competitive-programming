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
const int MAXN=2000000+5;
const LL MOD=1e9+7;
typedef vector<int> vi; typedef pair<char, LL> pii;
typedef vector<pair<int, int> > vpii;
int main()
{
    LL a;
    scanf("%I64d",&a);
    LL b=1,c=1;
    rep(i,a) {b*=27;c*=7;b%=MOD;c%=MOD;}
    printf("%I64d\n",(b-c)>0?b-c:(b-c+MOD)%MOD);
}
