#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int w[1050],d[1050];
int main()
{
    int n,m;
    while(scanf("%d",&n)&&n)
    {
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
        sort(w,w+n);
        scanf("%d",&m);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        m-=5;
        for(int i=0;i<n-1;i++)
            for(int j=m;j-w[i]>=0;j--)
                d[j]=max(d[j],d[j-w[i]]+w[i]);
        printf("%d\n",m+5-w[n-1]-d[m]);
    }
    return 0;
}