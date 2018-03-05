#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int out[50];
int main()
{
int n,r;
while(scanf("%d%d",&n,&r)!=EOF)
{
    memset(out,0,sizeof(out));
    int flag=0;
    int cnt=0;
    if(n<0)
    {
        flag=1;
        n=-n;
    }
    while(n!=0)
    {
        out[cnt++]=n%r;
        n/=r;
    }
    if(flag) printf("-");
    for(int i=cnt-1;i>=0;i--)
    {
        if(out[i]>9) printf("%c",'A'+out[i]-10);
        else printf("%d",out[i]);
    }
    printf("\n");
}
}