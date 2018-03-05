#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const double eps=1e-6;
typedef long long LL;
double cal(double a)
{
    return a*a*a*a*8+a*a*a*7+a*a*2+a*3+6;
}
int main()
{
    int t;double k;
    scanf("%d",&t);
    while(t--)
    {
        double l=0.0;double r=100.0;
        double mid=(r+l)/2;
        scanf("%lf",&k);
        if(k<cal(0)||k>cal(100))
        {
            printf("No solution!\n");
            continue;
        }
        while(r-l>eps)
        {
            if(cal(mid)>k) r=mid;
            else l=mid;
            mid=(r+l)/2;
        }
        printf("%.4lf\n",mid);
    }
}