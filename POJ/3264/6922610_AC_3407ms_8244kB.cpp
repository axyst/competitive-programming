#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
using namespace std;
const int MAXN=200001;
int mx[MAXN][20];int mn[MAXN][20];//max:2^20
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void rmq(int n)
{
    rel(j,20)
    rel(i,n)
    {
        if(i+(1<<j)-1<=n)
        {
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()
{
    int n,q,st,ed,m1,m2;
    scanf("%d%d",&n,&q);
    rel(i,n)
    {
        scanf("%d",&mx[i][0]);
        mn[i][0]=mx[i][0];
    }
    rmq(n);
    while(q--)
    {
        scanf("%d%d",&st,&ed);
        int k=(int)(log(ed-st*1.0+1)/log(2.0));
        m1=max(mx[st][k],mx[ed-(1<<k)+1][k]);
        m2=min(mn[st][k],mn[ed-(1<<k)+1][k]);
        printf("%d\n",m1-m2);
    }
}