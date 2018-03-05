#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int money,type;
int price[105],weigh[105],num[105],dp[105];
void MultiplePack(int price,int weigh,int num)
{
     if(price*num>=money)
        for(int i=price;i<=money;i++)
            dp[i]=max(dp[i],dp[i-price]+weigh);//完全背包
     for(int k=1;k<num;k*=2)
     {
          for(int i=money;i>=k*price;i--)
            dp[i]=max(dp[i],dp[i-k*price]+k*weigh);//0-1背包
          num-=k;
     }
     for(int i=money;i>=num*price;i--)
         dp[i]=max(dp[i],dp[i-num*price]+num*weigh);//0-1背包
}
int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d %d",&money,&type);
          memset(dp,0,sizeof(dp));
          for(int i=1;i<=type;i++)
          {
               scanf("%d %d %d",&price[i],&weigh[i],&num[i]);
               MultiplePack(price[i],weigh[i],num[i]);
          }
          printf("%d\n",dp[money]);
     }
     return 0;
}