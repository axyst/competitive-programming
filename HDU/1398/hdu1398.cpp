#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int kind=17;
int a[maxn];int b[maxn];int val[20];
void solve(int a[],int v[],int K,int n)
{
    a[0]=1;
    for (int i=1;i<=K;i++)
    {
        memset(b,0,sizeof(b));
        for (int j=0;j*v[i]<=n;j++)
            for (int k=0;k+j*v[i]<=n;k++)
                b[k+j*v[i]]+=a[k];
        memcpy(a,b,sizeof(b));
    }
}
//#define LOCAL
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    for(int i=1;i<=kind;i++)
        val[i]=i*i;
    int n;
    while(scanf("%d",&n)==1&&n>0)
    {
        solve(a,val,kind,n);
        printf("%d\n",a[n]);
        memset(a,0,sizeof(a));
    }
    return 0;
}

