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
int a[1050];
int main()
{
    //freopen("test.txt","r",stdin);
    int n,len;
    double ans=0;
    scanf("%d%d",&n,&len);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++) if(ans<(a[i+1]-a[i])*0.5) ans=(a[i+1]-a[i])*0.5;
    if(ans<a[0]*1.0||ans<(len-a[n-1])*1.0)
        ans=max(a[0],len-a[n-1])*1.0;
    printf("%.10lf",ans);
    return 0;
}