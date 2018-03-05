#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char str[30];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(m==n) {printf("1\n");continue;}
        if(m>n) swap(m,n);
        //if(n==2*m) {printf("2\n");continue;}
        int cnt=1;
        while(n!=2*m)
        {
            if(m>n) swap(m,n);
            int ten=n,tem=m;
            n=max(ten-tem,tem);
            m=min(ten-tem,tem);
            cnt++;
        }
        cnt++;
        printf("%d\n",cnt);
    }
}