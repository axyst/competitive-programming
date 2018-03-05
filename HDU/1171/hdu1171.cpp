#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
const int mod=1e9+7;
int a[maxn];int b[maxn];int val[55];int num[55];int last;
void solve(int a[],int v[],int n2[],int K)
{
    a[0]=1;
    last=0;
    for (int i=0;i<K;i++)
    {
        int last2=last+n2[i]*v[i];
        memset(b,0,sizeof(int)*(last2+1));
        for (int j=0;j<=n2[i];j++)
            for (int k=0;k<=last;k++)
                b[k+j*v[i]]+=a[k];
        memcpy(a,b,sizeof(int)*(last2+1));
        last=last2;
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
    int n;
    while(scanf("%d",&n)&&n>=0)
    {
        for(int i=0;i<n;i++) scanf("%d%d",val+i,num+i);
        solve(a,val,num,n);
        int i;
        for(i=last/2;i>=0;i--) if(a[i]) break;
        int aa=last-i;int bb=i;
        if(aa<bb) swap(aa,bb);
        printf("%d %d\n",aa,bb);
    }
    return 0;
}
