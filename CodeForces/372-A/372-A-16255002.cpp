/*
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
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int in[500000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&in[i]);
        sort(in+1,in+n+1);
        int j=n/2+1;
        int out=0;
        for(int i=1;i<=n/2&&j<=n;)
        {
            if(in[j]>=2*in[i])
            {
                out++;
                j++;
                i++;
            }
            else j++;
        }
        printf("%d\n",n-out);
    }
}