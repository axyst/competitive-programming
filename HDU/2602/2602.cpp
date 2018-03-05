#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int value[1050],volume[1050],d[1050];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        memset(d,0,sizeof(d));
        int n,v;
        scanf("%d%d",&n,&v);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&value[i]);
        }for(int i=1;i<=n;i++)
        {
            scanf("%d",&volume[i]);
        }
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++)
            for(int j=v;j>=volume[i];j--)
                d[j]=max(d[j],d[j-volume[i]]+value[i]);
        printf("%d\n",d[v]);
    }
    return 0;
}