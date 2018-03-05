#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct cube
{
    int x;
    int y;
    int high;
}a[300];
int dp[300];
bool cmp(cube a,cube b)
{
    if(a.x*a.y<b.x*b.y) return 1;
    else return 0;
}
int main()
{
    int t,ca=1;
    while(scanf("%d",&t)&&t)
    {
        int cnt=0;
        int t1,t2,t3;
        for(int i=0;i<t;i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            a[cnt].x=t1,a[cnt].y=t2,a[cnt++].high=t3;
            a[cnt].x=t2,a[cnt].y=t1,a[cnt++].high=t3;
            a[cnt].x=t1,a[cnt].y=t3,a[cnt++].high=t2;
            a[cnt].x=t3,a[cnt].y=t1,a[cnt++].high=t2;
            a[cnt].x=t3,a[cnt].y=t2,a[cnt++].high=t1;
            a[cnt].x=t2,a[cnt].y=t3,a[cnt++].high=t1;
        }
        //cnt--;
        sort(a,a+cnt,cmp);
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            dp[i]=a[i].high;
            for(int j=0;j<i;j++)
                if(a[i].x>a[j].x&&a[i].y>a[j].y)
                    dp[i]=max(dp[i],dp[j]+a[i].high);
            ans=max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",ca++,ans);
    }
    return 0;
}