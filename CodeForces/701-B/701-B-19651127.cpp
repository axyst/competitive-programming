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
const int N=1e6+5;
bool xv[N],yv[N];
LL ans[N];
int main()
{
//freopen("test.txt","r",stdin);
    LL n,m;
    int x,y,dx=0,dy=0;
    scanf("%I64d%I64d",&n,&m);
    for(int i=0;i<m;i++)
    {
        if(i==0) ans[i]=n*n;
        else ans[i]=ans[i-1];
        scanf("%d %d",&x,&y);
        if(!xv[x])
        {
            ans[i]-=(n-dy);
            xv[x]=1;
            dx++;
        }
        if(!yv[y])
        {
            ans[i]-=(n-dx);
            yv[y]=1;
            dy++;
        }
    }
    for(int i=0;i<m;i++)
    {
        printf("%I64d",ans[i]);
        if(i!=m) printf(" ");
    }
    printf("\n");
    return 0;
}