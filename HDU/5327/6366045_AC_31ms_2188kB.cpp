#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char tem[10];
int in[100000];
int sum[100000];
int main()
{
int n,a,b;
memset(in,0,sizeof(in));
for(int i=1;i<=100000;i++)
{
    int flag=1;
    sprintf(tem,"%d",i);
    int len=strlen(tem);
    for(int j=0;j<len;j++)
    {
        for(int k=j+1;k<len;k++)
            if(tem[j]==tem[k]) flag=0;
    }
    if(flag) in[i]=1;
}
sum[0]=0;
for(int i=1;i<100000;i++) sum[i]=sum[i-1]+in[i];
scanf("%d",&n);
while(n--)
{
    scanf("%d%d",&a,&b);
    printf("%d\n",sum[b]-sum[a-1]);

}
}