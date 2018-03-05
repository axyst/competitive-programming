#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
int a[100009];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,s,l=1,r=1,ans=0x3f3f3f3f;
    scanf("%d",&n);
    map<int,int> Hash,x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        Hash[a[i]]++;
    }
    s=Hash.size();
    while(true)
    {
        while(x.size()<s&&r<=n) x[a[r++]]++;
        if(x.size()<s) break;
        ans=min(ans,r-l);
        x[a[l++]]--;
        if(x[a[l-1]]<=0) x.erase(a[l-1]);
    }
    printf("%d\n",ans);
}