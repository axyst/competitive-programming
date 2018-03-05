#include<stdio.h>
long long str[100099],num[40];
int main()
{
    long long n;
    while(scanf("%I64d",&n))
    {
    for(int i=0;i<n;i++)
    {
        long long k=0;
        scanf("%I64d",&str[i]);
        while(str[i]!=0)
        {
        if(str[i]%2==1) k++;
        str[i]/=2;
        }
        num[k]++;
    }
    long long s=0;
    for(int i=1;i<34;i++) {s+=num[i]*(num[i]-1)/2;}
    printf("%I64d\n",s);
    return 0;
    }
}