#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100050];
long long two[50];
int main()
{
    long long in=1;
    for(int i=0;i<=32;i++)
    {
        two[i]=in;
        in*=2;
    }
    int n;
    long long M=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<=32;k++)
        {
            if(a[i]>two[k]) continue;
            int up=upper_bound(a,a+i,two[k]-a[i])-a;
            int down=lower_bound(a,a+i,two[k]-a[i])-a;
            M+=up-down;
        }
    }
    printf("%I64d\n",M);
    return 0;
}