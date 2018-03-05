#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int in[200000];
int main()
{
    int n,m,q,out;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    sort(in,in+n);
    while(m--)
    {
        scanf("%d",&q);
        if(in[n-1]<=q){printf("%d\n",n);continue;}
        else out=upper_bound(in,in+n,q)-in;
        printf("%d\n",out);
    }
}