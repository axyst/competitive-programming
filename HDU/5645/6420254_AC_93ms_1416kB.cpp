#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int str[500];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {

        int n=0,cnta=0,cntb=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&str[i]);
        double ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                if(str[i]>str[j]) cnta++;
                else if(str[i]<=str[j]) cntb++;
                //printf("%d %d %d %d\n",i,j,cnta,cntb);
            }
        }
        ans=double(cnta)/double(cnta+cntb);
        printf("%f\n",ans);
    }
}