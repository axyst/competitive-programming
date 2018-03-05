#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pi 3.1415926535897932
#define e 0.000001
using namespace std;
double rad[10050];
double out[10050];
int main()
{
    int t,cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,f;
        double sum=0,r,l,mid,ans;
        scanf("%d%d",&n,&f);
        f++;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&rad[i]);
            rad[i]*=rad[i];
            sum+=rad[i];
        }
        r=sum/f;
        l=0;
        while(r-l>e)
        {
            mid=(l+r)/2;
            int tem=0;
            for(int i=0;i<n;i++) tem+=(int)rad[i]/mid;
            if(tem<f) r=mid;
            else
            {
                l=mid;
                ans=mid;
            }
        }
        out[cnt++]=ans*pi;
    }
    for(int i=0;i<cnt;i++) printf("%.4f\n",out[i]);
    return 0;
}