#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define LL long long
const int MAXN=501;
LL a[MAXN][MAXN];
int main()
{
    //freopen("test.txt","r",stdin);
    int n,ti,tj,tmp;
    LL ans,sum=0,tem=0,rsum=0,csum=0,dsum1=0,dsum2=0;
    scanf("%d",&n);
    rep(i,n)
        rep(j,n) scanf("%I64d",&a[i][j]);
    if(n==1) {printf("1\n");return 0;}

    rep(i,n)
        rep(j,n)
        {
            if(a[i][j]==0) {ti=i;tj=j;break;}
        }
    rep(i,n) tem+=a[ti][i];
    if(ti==0) tmp=1;
    else tmp=ti-1;
    rep(i,n) sum+=a[tmp][i];
    ans=sum-tem;
    a[ti][tj]=ans;

    tem=0;
    rep(i,n)
        rep(j,n)
        {
            tem+=a[i][j];
            if(j==n-1)
            {
                if(i==0) rsum=tem;
                if(i!=0&&tem!=rsum)
                {
                    //printf("%I64d\n",tem);
                    ans=-1;
                    goto l1;
                }
                tem=0;
            }
        }
        tem=0;
    rep(i,n)
        rep(j,n)
        {
            tem+=a[j][i];
            if(j==n-1)
            {
                if(i==0) csum=tem;
                if(i!=0&&tem!=csum)
                {
                    ans=-1;
                    goto l1;
                }
                tem=0;
            }
        }
    if(rsum!=csum){ans=-1;goto l1;}
    rep(i,n)
    {
        dsum1+=a[i][i];
        dsum2+=a[i][n-1-i];
    }
    if(dsum1!=dsum2) ans=-1;
    if(dsum1!=rsum) ans=-1;
    if(ans<=0) ans=-1;
    l1:printf("%I64d\n",ans);
}
