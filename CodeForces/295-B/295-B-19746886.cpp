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
const int N=505;
int pic[N][N],d[N][N];
LL del[N];
int n;
void Floyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)//find shortest path from (n-i)th deleted point to (n-j)th deleted point
            for(int j=0;j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    LL ans=0;
    for(int i=0;i<k+1;i++)
        for(int j=0;j<k+1;j++)
            ans+=d[i][j]; //(k+1)th query,add all shortest path between(n-i), (n-j)
    del[k]=ans;//i<k+1,j<k+1,so n-i>n-(k+1)&&n-j>n-(k+1)
    }//which means all these points still remain when the query happens
}
int main()
{
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&pic[i][j]);
    for(int i=1;i<=n;i++) scanf("%d",&del[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=pic[del[n-i]][del[n-j]];//replace shortest path from i to j with the direct path from
                                            //(n-i)th deleted point to (n-j)th deleted point
    Floyd();
    for(int i=n-1;i>=1;i--) printf("%I64d ",del[i]);
    printf("%I64d",del[0]);
    printf("\n");
    return 0;
}