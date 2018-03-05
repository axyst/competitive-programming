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
struct man
{
    int money;
    int factor;
}fri[100010];
long long sum[100010];
bool cmp(man a,man b)
{
    return a.money<b.money;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n,d;
    long long ans=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&fri[i].money,&fri[i].factor);
    if(n==1){printf("%d\n",fri[1].factor);return 0;}
    sort(fri+1,fri+1+n,cmp);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+fri[i].factor;
    int l=1,r=1;
    for(;l<=n;l++)
    {
        while(r<=n&&fri[r].money-fri[l].money<d) r++;
        ans=max(ans,sum[r-1]-sum[l-1]);
    }
    printf("%I64d\n",ans);
    return 0;
}