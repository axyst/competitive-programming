#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int lcm(int a,int b)
{
    int t;
    if(b>a)
    {
        t=b;b=a;a=t;
    }
    int x=a;
    while(x%b!=0) x+=a;
    return x;
}
int a[100000];
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        scanf("%d",&a[0]);
        for(int i=1;i<m;i++)
        {
            scanf("%d",&a[i]);
            a[i]=lcm(a[i-1],a[i]);
        }
        printf("%d\n",a[m-1]);
    }
}