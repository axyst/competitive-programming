#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int str[100500];
int main()
{
    int t;
    scanf("%d",&t);
    {
    while(t--)
    {
        int n,s,len,sum=0,head=1,tail=1;
        scanf("%d%d",&n,&s);
        len=n+1;
        for(int i=0;i<n;i++) scanf("%d",&str[i]);
        while(1)
        {
            while(tail<n&&sum<s) sum+=str[tail++];
            if(sum<s) break;
            len=min(len,tail-head);
            sum-=str[head++];
        }
        if(len>n) len=0;
        printf("%d\n",len);
    }
    return 0;
    }
}