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
int book[100005];
int main()
{
//freopen("test.txt","r",stdin);
    int n,t,ans=0;
    scanf("%d%d",&n,&t);
    book[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&book[i]);
        book[i]+=book[i-1];
    }
    if(book[n]<=t)
    {
        printf("%d\n",n);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(book[m]-book[i]<=t) l=m+1;
            else r=m-1;
        }
        ans=max(l-i,ans);
    }
    printf("%d\n",ans-1);
    return 0;
}