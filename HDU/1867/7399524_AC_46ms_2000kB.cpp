#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

typedef long long LL;
using namespace std;
const int MAXN=1e5+5;
int tnext[MAXN];
char a[MAXN];
char b[MAXN];
void getnext(char b[])
{
    int lb=strlen(b);
    memset(tnext,0,sizeof(tnext));
    for(int i=1;i<lb;i++)
    {
        int j=tnext[i];
        while(j&&b[j]!=b[i]) j=tnext[j];
        tnext[i+1]=(b[j]==b[i]?j+1:0);
    }
}
int kmp(char a[],char b[])
{
    getnext(b);
    int la=strlen(a);
    int j=0;
    for(int i=0;i<la;i++)
    {
        while(j&&b[j]!=a[i]) j=tnext[j];
        if(b[j]==a[i]) j++;
        if(i==la-1) return j;
    }
    return 0;
}
int main()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        int lena=strlen(a);
        int lenb=strlen(b);
        int x=kmp(a,b);
        int y=kmp(b,a);
        //printf("%d %d\n",x,y);
        if(x==y)
        {
            if(strcmp(a,b)>0)
            {
                printf("%s",b);
                printf("%s",a+y);
            }
            else
            {
                printf("%s",a);
                printf("%s",b+x);
            }
        }
        else if(x>y)
        {
            printf("%s",a);
            printf("%s",b+x);
        }
        else
        {
            printf("%s",b);
            printf("%s",a+y);
        }
        printf("\n");
    }
    return 0;
}