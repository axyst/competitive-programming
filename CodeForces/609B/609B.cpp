#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int book[10];
int main ()
{
    memset(book,0,sizeof(book));
    int n,m,tem;
    long long cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tem);
        book[tem]++;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
            if(i!=j) cnt+=book[i]*book[j];
    }
    printf("%I64d\n",cnt);
}