#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#define LL long long
using namespace std;
int CD[500];
int GCD(int a,int b)
{
    return b==0?a:GCD(b,a%b);
}
int bsearch(int l,int r,int k,int a[])
{
    while(a[l]<a[r])
    {
        int m=l+(r-l+1)/2;
        if(k>=a[m]) l=m;
        else r=m-1;
    }
    return l;
}
int main()
{
//freopen("test.txt","r",stdin);
    int a,b,cnt=0;
    scanf("%d%d",&a,&b);
    a=GCD(a,b);
    b=sqrt(a);
    for(int i=1;i<=b;i++)
    {
        if(a%i==0)
        {
            CD[cnt++]=i;
            CD[cnt++]=a/i;
        }
    }
    sort(CD,CD+cnt);
    //for(int j=0;j<cnt;j++) printf("%d\n",CD[j]);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int lo,hi;
        scanf("%d%d",&lo,&hi);
        int mid=bsearch(0,cnt-1,hi,CD);
        //int mid=upper_bound(CD,CD+cnt,hi)-CD-1;
        int ans=CD[mid];
        if(lo>ans) printf("-1\n");
        else printf("%d\n",ans);
        //printf("%d\n",ans);
    }
    return 0;
}