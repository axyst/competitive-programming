//#define POJ
#ifndef POJ
#include<bits/stdc++.h>
#endif
#ifdef POJ
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#endif
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%lld",&(n))
using namespace std;
typedef long long LL;
const int mod=1e9+7;
const int maxn=1e6+5;
double A;double B;
double F(double x)
{
    return sqrt(B*B*(1-x*x/(A*A)));
}
double simpson(double a,double b)
{
    double c=a+(b-a)/2;
    return (F(a)+4*F(c)+F(b))*(b-a)/6;
}
double asr(double a,double b,double eps,double cur)
{
    double c=a+(b-a)/2;
    double L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-cur)<=eps*15) return L+R+(L+R-cur)/15.0;
    return asr(a,c,eps*0.5,L)+asr(c,b,eps*0.5,R);
}
double asr(double a,double b,double eps)
{
    return asr(a,b,eps,simpson(a,b));
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
    double eps=1e-6;
    int n;si(n);
    while(n--)
    {
        double l,r;
        scanf("%lf%lf%lf%lf",&A,&B,&l,&r);
        double ans=asr(l,r,eps);
        printf("%.3lf\n",ans*2);
    }
    return 0;
}
