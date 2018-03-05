#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[510];
int b[510];
int sum[250100];
int c[510];
int main()
{
int t=1,l,n,m,s;
while(scanf("%d%d%d",&l,&n,&m)!=EOF)
{
    for(int i=0;i<l;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<m;i++) scanf("%d",&c[i]);
    int cnt=0;
    for(int i=0;i<l;i++)
        for(int j=0;j<n;j++)
            sum[cnt++]=a[i]+b[j];
    sort(sum,sum+cnt);
    //sort(c,c+m);
    int num;
    scanf("%d",&num);
    printf("Case %d:\n",t++);
    while(num--)
    {
        scanf("%d",&s);
        int flag=0,tem;
        for(int i=0;i<m;i++)
        {
            tem=s-c[i];
            flag=binary_search(sum,sum+cnt,tem);
            if(flag!=0) break;
        }
        if(flag!=0) printf("YES\n");
        else printf("NO\n");
    }
}
return 0;
}