#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
struct p
{
  int val;
  double exp;
}a[2*100005];
double sum[2*100005];
int c[2*100005];
int d[2*100005];
bool cmp(p a,p b)
{
  return a.val<b.val;
}
bool cmp2(const int&a,const int&b)
{
  return a>b;
}
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  for (int i=0;i<n;i++) scanf("%d",&a[i].val);
  for (int i=0;i<n;i++) scanf("%lf",&a[i].exp);
  //sort(a,a+n,cmp);
  for (int i=0;i<n;i++) d[i]=a[i].val;
  for (int i=0;i<n;i++) c[i]=d[i]-k;
  sum[1]=a[0].exp;
  for (int i=1;i<n;i++) sum[i+1]=sum[i]+a[i].exp;
  //for (int i=1;i<=n;i++) printf("%lf ",sum[i]);
  double ans=0;
  for (int i=1;i<=n;i++)
  {
     int t=d[i];
     int l=upper_bound(c,c+i,d[i],cmp2)-c;
     int r=lower_bound(d,d+i+1,d[i],cmp2)-d;
    /*int l=1;int r=i+2;
    while (r-l>1)
    {
      int mid=(r+l)/2;
      if (c[mid]>=a[i].val) l=mid;
      else r=mid;
    }
    int ll=l;
    l=0; r=i+1;
    while (r-l>1)
    {
      int mid=(r+l)/2;
      if (c[mid]>c[i]) l=mid;
      else r=mid;
    }
    int rr=r;*/
    ans+=(sum[r]-sum[l])*1.0*(1-a[i].exp);
    //cout<<l<<" "<<r<<endl;

  }
  printf("%.6lf\n",ans);




}