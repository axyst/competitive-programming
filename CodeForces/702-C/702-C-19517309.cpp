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
   //freopen("1.txt","r",stdin);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
   for (int j=1;j<=m;j++) scanf("%I64d",&b[j]);
   b[0]=INF;
   long long  ans=-1,dis;
   for (int i=1;i<=n;i++)
   {
       int r=my_bound(1,m,a[i]);
       if (a[i]!=b[r]) dis=min(abs(b[r]-a[i]),abs(b[r-1]-a[i]));
       else dis=0;
       if (dis>ans) ans=dis;
   }
   printf("%I64d\n",ans);
   //fclose(stdin);
}