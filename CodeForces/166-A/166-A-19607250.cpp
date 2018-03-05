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
struct man
{
    int p;
    int t;
}men[55];
int has[55];
bool cmp(man a,man b)
{
    if(a.p>b.p) return 1;
    else if(a.p==b.p)
        if(a.t<b.t) return 1;
        else return 0;
    else return 0;
}
int upperbound(int l,int r,man k)
{
    while(l<r)
    {
        int m=l+(r-l+1)/2;
        if(men[m].p>k.p) l=m;
        else if(men[m].p==k.p&&men[m].t<=k.t) l=m;
        else r=m-1;
    }
    return l;
}
int main()
{
//freopen("test.txt","r",stdin);
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d%d",&men[i].p,&men[i].t);
    sort(men+1,men+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int up=upperbound(i,n,men[i]);
        for(int j=i;j<=up;j++) has[j]=up-i+1;
        //printf("%d %d %d\n",i,up,has[i]);
        i=up;
    }
    //for(int i=1;i<=n;i++) printf("%d\n",has[i]);
    printf("%d\n",has[k]);
    return 0;
}