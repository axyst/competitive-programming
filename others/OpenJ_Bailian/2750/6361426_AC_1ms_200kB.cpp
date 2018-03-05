#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int n,cnt=0,a;
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("0 0\n");
        return 0;
    }
    a=n;
    while(n>2)
    {
        n-=4;
        cnt++;
    }
    if(n==2) cnt++;
    printf("%d ",cnt);
    printf("%d\n",a/2);
}