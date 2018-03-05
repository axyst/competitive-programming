#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
int thenext[maxn];
int a[maxn];int b[maxn];

int kmp(int la,int lb,int p)
{
    //a,b start from 1
    int mx=0;
    int j=0;
    thenext[1] = 0;
    for(int i=2;i<=lb;i++)
    {
        while(j>0&&b[j+1]!=b[i]) j=thenext[j];
        if(b[j+1]==b[i]) j++;
        thenext[i]=j;
    }
    //for (int i = 1; i<=lb; i++)
    //    printf("%d ", thenext[i]);

    int ans=0;
    for(int st=1;st<=p;st++)
    {
        j=0;
        for(int i=st;i<=la;i+=p)
        {
            while(j>0&&b[j+1]!=a[i]) j=thenext[j];

            if(b[j+1]==a[i]) j++;
            //if(j==lb) return (i-lb+1);
            if(j==lb)
            {
                ans++;
                j=thenext[j];
            }
            //printf("i=%d j=%d\n", i, j);
        }
    }
    //return -1;
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;si(t);
    for(int ks=1;ks<=t;ks++)
    {
        int n,m,p;si(n);si(m);si(p);
        for(int i=1;i<=n;i++) si(a[i]);
        for(int i=1;i<=m;i++) si(b[i]);
        int ans=kmp(n,m,p);
        printf("Case #%d: %d\n",ks,ans);
    }
    return 0;
}