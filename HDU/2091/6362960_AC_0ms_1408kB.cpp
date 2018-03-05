#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
char n;
int r,flag=0;
while(1)
{
    scanf("%s",&n);
    if(n=='@') break;
    scanf("%d",&r);
    if(flag)printf("\n");
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<r-i+1;j++)printf(" ");
        for(int j=1;j<=2*i-1;j++)
        {
            if(i!=r&&j>1&&j<2*i-1) printf(" ");
            else putchar(n);
        }
        printf("\n");
    }
    flag=1;
}
}