#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[200050];
int main ()
{
    int n,mi=0x3f3f3f3f;
    long long cnt=0,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
         mi=min(mi,a[i]);
    }
    ans=1LL*mi*n;
    int now=0,len=0;
    for(int i=0;i<n;i++)
    {
        a[i]-=mi;
        if(a[i]==0)
        {
            if(now)
                {
                    len=max(now,len);
                    now=0;
                }
        }
        else now++;
    }
    if(now) len=max(len,now);
    int num=0,j=0;
    while(a[j]&&j<n) j++,num++;
    j=n-1;
    while(a[j]&&j>=0) j--,num++;
    len=max(len,num);
    cnt=ans+len;
    printf("%I64d\n",cnt);
    return 0;
}