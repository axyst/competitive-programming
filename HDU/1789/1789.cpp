#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long LL;
const int MAXN=1005;
struct score
{
    int day;
    int sco;
}a[MAXN];
int vis[MAXN];
bool cmp(score a,score b)
{
    if(a.sco!=b.sco) return a.sco>b.sco;
    else return a.day<b.day;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        rep(i,n) scanf("%d",&a[i].day);
        rep(i,n) scanf("%d",&a[i].sco);
        sort(a,a+n,cmp);
        int cnt=0,j;
        rep(i,n)
        {
            for(j=a[i].day;j>0;j--)
            {
                if(vis[j]==0)
                    {vis[j]=1;break;}
            }
            if(j==0) cnt+=a[i].sco;
        }
        printf("%d\n",cnt);
    }
    return 0;
}