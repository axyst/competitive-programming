#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define LL long long
int a[101];
int main()
{
    //freopen("test.txt","r",stdin);
    a[0]=1;
    int base=0,sum=1;
    for(int i=1;i<100;)
    {
        for(int j=0;j<(base);j++)a[i+j]=sum;
        i+=base;
        sum+=2;
        base+=4;
    }
    //for(int i=0;i<100;i++) printf("%d %d\n",i,a[i]);
    a[2]=5;
    int x;
    scanf("%d",&x);
    printf("%d\n",a[x-1]);
}