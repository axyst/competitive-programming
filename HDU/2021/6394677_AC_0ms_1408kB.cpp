#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,sum=0,temp=0,t;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) return 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            temp+=t/100;
            t-=((t/100)*100);
            temp+=t/50;
            t-=((t/50)*50);
            temp+=t/10;
            t-=((t/10)*10);
            temp+=t/5;
            t-=((t/5)*5);
            temp+=t/2;
            t-=((t/2)*2);
            temp+=t;
            sum+=temp;
            temp=0;
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}