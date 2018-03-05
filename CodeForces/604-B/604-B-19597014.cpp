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
LL bell[100005];
int main()
{
//freopen("test.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);//n个，可放k个盒子，每个最多放2个
    for(int i=0;i<n;i++) scanf("%I64d",&bell[i]);//升序
    LL ans=bell[n-1];
    if(n<=k){printf("%I64d\n",ans);return 0;}//不放箱
    else if(n/k<2)//部分放箱
    {
        for(int i=0;i<(n%k);i++)
            ans=max(ans,bell[i]+bell[2*(n%k)-i-1]);//前2*n%k要放箱
    }
    else//全放箱
    {
        for(int i=0;i<n/2;i++)
            ans=max(ans,bell[i]+bell[n-i-1]);//首尾放箱
    }
    printf("%I64d\n",ans);
    return 0;
}