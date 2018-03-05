#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int m;
    double a,b,c;
    scanf("%d",&m);
    while(m--)
    {
        int flag=1;
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a+b<=c||b+c<=a||a+c<=b) flag=0;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}