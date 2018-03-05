#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100000+5;
LL l[maxn],r[maxn],a[maxn];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=1;i<=n;i++) scanf("%I64d",a+i);
        l[1]=1;r[n]=n;
        for(int i=1;i<=n;i++)
        {
            int cur=i;
            while(cur>1&&a[i]<=a[cur-1]) cur=l[cur-1];
                l[i]=cur;
        }
        for(int i=n;i>=1;i--)
        {
            int cur=i;
            while(cur<n&&a[i]<=a[cur+1]) cur=r[cur+1];
            r[i]=cur;
        }
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,(r[i]-l[i]+1)*a[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
