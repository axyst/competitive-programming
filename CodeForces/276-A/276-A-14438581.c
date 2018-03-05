#include<stdio.h>
struct can{long long fun;long long tim;};
struct can res;
int main()
{
int n,k;
long long max1=-1000000000,temp;
scanf("%d%d",&n,&k);
for(int i=0;i<n;i++)
{scanf("%d%d",&res.fun,&res.tim);
if(res.tim>k) temp=res.fun-res.tim+k;
    else temp=res.fun;
if(temp>max1) max1=temp;
}
printf("%I64d\n",max1);
}