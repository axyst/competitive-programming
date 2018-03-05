#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int bom[2000];
int main()
{
    int n,temp,i,j,max1;
    while(scanf("%d",&n)!=EOF&&n)
    {
        bom[1]=0;
        max1=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            for(j=1;j<=max1;j++)
            {
                if(temp<=bom[j])
                {
                bom[j]=temp;
                break;
                }
            }
            if(j>max1) bom[++max1]=temp;
        }
        printf("%d\n",max1);
    }
    return 0;
}