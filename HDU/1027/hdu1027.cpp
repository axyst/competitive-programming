#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1000+5;
const int mod=1e9+7;
int a[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    #endif
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++) a[i]=i;
        int cnt=0;
        do
        {
            cnt++;
            if(cnt==m)
            {
                for(int i=1;i<n;i++) printf("%d ",a[i]);
                printf("%d\n",a[n]);
                break;
            }
        }while(next_permutation(a+1,a+1+n));
    }
    return 0;
}
