#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

typedef long long LL;
using namespace std;
const int MAXN=1000005;
int thenext[MAXN];
int a[MAXN];
int b[10005];
int kmp(int a[],int b[],int la,int lb)
{
    //a,b start from 1
    int mx=0;
    int j=0;
    for(int i=2;i<=lb;i++)
    {
        while(j>0&&b[j+1]!=b[i]) j=thenext[j];
        if(b[j+1]==b[i]) j++;
        thenext[i]=j;
    }
    j=0;
    for(int i=1;i<=la;i++)
    {
        while(j>0&&b[j+1]!=a[i]) j=thenext[j];
        if(b[j+1]==a[i]) j++;
        if(j==lb) return (i-lb+1);
    }
    return -1;
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++) scanf("%d",&a[i]);
        for(int i=1;i<=y;i++) scanf("%d",&b[i]);
        int ans=kmp(a,b,x,y);
        printf("%d\n",ans);
    }
    return 0;
}
