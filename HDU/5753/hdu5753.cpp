#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
double a[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lf",a+i);
        if(n==1)
        {
            printf("%.6lf\n",a[0]);
            continue;
        }
        double ans=a[0]*0.5+a[n-1]*0.5;
        for(int i=1;i<n-1;i++) ans+=a[i]/3;
        printf("%.6lf\n",ans);
    }
    return 0;
}
