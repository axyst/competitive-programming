 By lyracol, contest: 2017 ACM Arabella Collegiate Programming Contest, problem: (J) Lazy Physics Cat, Accepted, #

#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1000+5;
const double pi=acos(-1.0);
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int l,a;scanf("%d%d",&l,&a);
        double ans=pi*a*l*l/180*0.5-l*l*sin(pi*a/180)*0.5;
        printf("%.6lf\n",ans);
    }
    return 0;
}

