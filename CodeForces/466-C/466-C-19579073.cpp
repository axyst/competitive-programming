#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
long long sum[500010];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    long long a,ans=0;
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        sum[i]=sum[i-1]+a;
    }
    long long all=sum[n];
    if(n<3||all%3!=0) {printf("0\n");return 0;}
    if(all!=0)
    {
        long long three=all/3;
        long long cnt=0;
        for(int i=1;i<n;i++)
        {
            if(sum[i]==three*2) ans+=cnt;
            if(sum[i]==three) cnt++;
        }
        printf("%I64d\n",ans);
    }
    else
    {
        long long cnt=0;
        for(int i=1;i<=n;i++)
            if(sum[i]==0) cnt++;
        printf("%I64d\n",(cnt-1)*(cnt-2)/2);
    }
    return 0;
}