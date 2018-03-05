#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int a[5][maxn];
LL sum[5][maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int n;LL p;
    scanf("%d%I64d",&n,&p);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j]=(sum[i][j-1]+a[i][j])%p;
        }
    set<int>s;
    LL ans=(sum[1][n]+a[2][n]+a[3][n])%p;
    for(int i=1;i<=n;i++)
    {
        LL rot=(sum[1][i]-sum[2][i-1]+p)%p;
        s.insert(rot);
        rot=(sum[2][i]+sum[3][n]-sum[3][i-1]+p)%p;
        set<int>::iterator it=s.lower_bound(p-rot);
        if(it!=s.begin())
            ans=max(ans,(rot+*(--it))%p);
    }
    printf("%I64d\n",ans);
    return 0;
}
