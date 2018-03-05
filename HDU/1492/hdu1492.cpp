#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
LL a[5];
//#define LOCAL
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL n;
    while(scanf("%I64d",&n)&&n)
    {
        memset(a,0,sizeof(a));
        while(n%2==0) {a[0]++;n/=2;}a[0]++;
        while(n%3==0) {a[1]++;n/=3;}a[1]++;
        while(n%5==0) {a[2]++;n/=5;}a[2]++;
        while(n%7==0) {a[3]++;n/=7;}a[3]++;
        printf("%I64d\n",a[0]*a[1]*a[2]*a[3]);
    }
    return 0;
}

