#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[1010];
bool cmp(int a,int b)
{
    return a>b;
}
int main ()
{
    int n,m,cnt=0,tem=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    while(m>0)
    {
        m-=a[tem++];
        cnt++;
    }
    printf("%d",cnt);
}