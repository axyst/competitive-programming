#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define A tv[0]
#define B tv[1]
using namespace std;
int tv[1010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&tv[i]);
        int ans=0,tail;
        sort(tv,tv+n);
        for(tail=n-1;tail>2;tail-=2)
        {
        int tem,ans1,ans2;
        ans1=A+B*2+tv[tail];
        ans2=A*2+tv[tail]+tv[tail-1];
        tem=min(ans1,ans2);
        ans+=tem;
        }
        if(tail==0) ans+=A;
        if(tail==1) ans+=B;
        if(tail==2) ans+=A+B+tv[2];//boat needn't return
        printf("%d\n",ans);
    }
    return 0;
}