#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#define LL long long
using namespace std;
LL clo[100005];
int main()
{
//freopen("test.txt","r",stdin);
    int n,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&clo[i]);
        }
        sort(clo,clo+n);
        scanf("%d",&k);
        if(k==1)
        {
            printf("%d\n",clo[n-1]);
            return 0;
        }
        LL l=0,r=clo[n-1],ans=0;
        while(l<=r)
        {
            LL mid=(l+r)/2,sum=0;
            for(int i=0;i<n;i++)
                if(clo[i]>mid)
                {
                    LL xx=(clo[i]-mid+k-2)/(k-1);
                    sum+=xx;
                }
            if(sum<=mid)
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}