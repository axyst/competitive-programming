#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int v[1050],wei[1050],d[10050];
const int M=0x3f3f3f3f;
int main()
{
    int t,w,n;
    scanf("%d",&t);
    while(t--)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        w=t2-t1;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&v[i],&wei[i]);
        for(int i=1;i<=w;i++) d[i]=M;
        d[0]=0;
        for(int i=0;i<n;i++)
            for(int j=wei[i];j<=w;j++)
                d[j]=min(d[j],d[j-wei[i]]+v[i]);
        if(d[w]==M)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",d[w]);
    }
    return 0;
}