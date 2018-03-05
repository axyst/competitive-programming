#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int a[100010];
int sum[100010];
int q[100010];
int main()
{
    //freopen("test.txt","r",stdin);
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0) sum[0]=a[0];
        else sum[i]=sum[i-1]+a[i];
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&q[i]);
    for(int i=0;i<m;i++) printf("%d\n",lower_bound(sum,sum+n,q[i])-sum+1);
    return 0;
}