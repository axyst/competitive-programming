#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<long long,long long> PLL;
const int INF=0x3f3f3f3f;
const int maxn=1005;
const int mod=1e9+7;
int w[maxn];
map<PLL,int>vis;
struct Point
{
    LL x;LL y;
}p[maxn];
bool cmp(Point a,Point b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
LL gcd(LL a,LL b)
{
    while(b)
    {
        LL t=a%b;
        a=b;
        b=t;
    }
    return a;
}
LL fpow(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%I64d %I64d\n",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        LL ans=0;
        for(int i=0;i<n;i++)
        {
            vis.clear();
            LL cur=0;
            for(int j=i+1;j<n;j++)
            {
                if(p[i].x==p[j].x&&p[i].y==p[j].y) cur++;
                else
                {
                    LL dx=p[j].x-p[i].x;
                    LL dy=p[j].y-p[i].y;
                    LL gg=gcd(dx,dy);
                    PLL tmp;tmp.first=dx/gg;tmp.second=dy/gg;
                    vis[tmp]++;
                }
            }
            if(cur)
            {
                ans+=((fpow(2,cur)-1)%mod);
                ans%=mod;
            }
            map<PLL,int>::iterator it;
            for(it=vis.begin();it!=vis.end();it++)
            {
                LL tmp=((fpow(2,it->second)-1)*(fpow(2,cur)))%mod;
                ans+=tmp;
                ans%=mod;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
