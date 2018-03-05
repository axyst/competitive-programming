#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[7];
int f[120005];
int v,k;
void ZeroOnePack(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
       if(f[i-cost]+weight>f[i]) f[i]=f[i-cost]+weight;
}
void CompletePack(int cost,int weight)
{
    for(int i=cost;i<=v;i++)
        if(f[i-cost]+weight>f[i]) f[i]=f[i-cost]+weight;
}
void MultiplePack(int cost ,int weight,int amount)
{
    if(cost*amount>=v) CompletePack(cost,weight);
    else
    {
        for(int k=1;k<amount;)
        {
            ZeroOnePack(k*cost,k*weight);
            amount-=k;
            k<<=1;
        }
        ZeroOnePack(amount*cost,amount*weight);
    }
}
int main()
{
    int tol;
    int iCase=0;
    while(1)
    {
        iCase++;
        tol=0;
        for(int i=1;i<7;i++)
        {
            scanf("%d",&a[i]);
            tol+=a[i]*i;
        }
        if(tol==0) break;
        if(tol%2==1)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",iCase);
            continue;
        }
        else
        {
            v=tol/2;
            memset(f,0,sizeof(f));
            for(int i=1;i<7;i++)
              MultiplePack(i,i,a[i]);
            if(f[v]==v)
              printf("Collection #%d:\nCan be divided.\n\n",iCase);
            else printf("Collection #%d:\nCan't be divided.\n\n",iCase);
        }
    }
    return 0;
}