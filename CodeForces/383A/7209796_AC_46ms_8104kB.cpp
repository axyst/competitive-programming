#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
//static const LL INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=200000+5;
//typedef vector<LL> vi; typedef pair<LL, LL> pii;
//typedef vector<pair<LL, LL> > vpii;
typedef long long LL;
LL a[MAXN];
struct cow
{
    LL cnum;
    LL znum;
    LL id;
}in[MAXN];

int main()
{
    LL n,tmp;
    //LL ansz=0;LL ansc=0;
    LL ansc=0;LL ansz=0;
    int zflag=0;int cflag=0;
    scanf("%I64d",&n);/*
    LL cnt=0;
    rep(i,n)
    {
        scanf("%d",&tmp);
        if(tmp) cnt++;
    }
    printf("%d\n",cnt);*/
///1:facing right
///cnum:right to left
///0:facing left
///znum:left to right
///more zero:one first more one:zero first
///wipe out the fewer number
///if there is only one kind of number,the answer won't decrease
    rep(i,n)
    {
        scanf("%d",&a[i]);
        if(!a[i]) zflag=1;
        if(a[i]) cflag=1;
    }
    if(!zflag||!cflag){printf("0\n");return 0;}
    LL mxc=0;LL mxz=0;
    LL cone=0;LL czero=0;
    rep(i,n)
    {
        if(!a[i]) in[i].znum=mxz,czero++;
        else mxz++;
        ansz+=in[i].znum;
    }
    for(LL i=n-1;i>-1;i--)
    {
        if(a[i])
        {
            in[i].cnum=mxc,cone++;
        }
        else
        {
            mxc++;
        }
        ansc+=in[i].cnum;
    }
    //rep(i,n) printf("id:%d cnum:%d znum:%d\n",in[i].id,in[i].cnum,in[i].znum);
    if(cone>czero) printf("%I64d",ansz);
    else printf("%I64d",ansc);
}
