#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
unsigned long long str[10];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        for(int i=0;i<4;i++) scanf("%I64d",&str[i]);
        sort(str,str+4);
        for(int i=0;i<4;i++) if(str[i]==0) flag=1;
        if(flag)   {printf("No\n");continue;}
        if(1LL*str[0]+1LL*str[1]>1LL*str[3]-1LL*str[2]) {printf("Yes\n");continue;}
        else if(1LL*str[0]+1LL*str[1]<=1LL*str[3]-1LL*str[2]) printf("No\n");
    }
}