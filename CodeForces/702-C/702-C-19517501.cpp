#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 100000000000
long long  a[100050],b[100050];
int my_bound(int left,int right,int key)
{
    int l=left,r=right,k=key,m;
    while(l+1<r)
    {
        m=(l+r)/2;
        if(k<=b[m]) r=m;
        else l=m;
    }
    return r;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%I64d",&b[i]);
    b[0]=INF;
    long long ans=-1;
    for(int i=1;i<=n;i++)
    {
        int t1=my_bound(1,m,a[i]);
        long long t2=0;
        if(a[i]!=b[t1])
            t2=min(abs(b[t1]-a[i]),abs(b[t1-1]-a[i]));
        ans=max(ans,t2);
    }
    printf("%I64d\n",ans);
    return 0;
}