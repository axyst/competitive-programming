#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e4+5;
const int mod=1e9+7;
int a[maxn];int b[maxn];int val[]={1,2,5};int num[5];int lower[]={0,0,0};int last;
void solve(int a[],int v[],int n1[],int n2[],int K)
{
    a[0]=1;
    last=0;
    for (int i=0;i<K;i++)
    {
        int last2=min(last+n2[i]*v[i],INF);
        memset(b,0,sizeof(int)*(last2+1));
        for (int j=n1[i];j<=n2[i]&&j*v[i]<=last2;j++)
            for (int k=0;k<=last&&k+j*v[i]<=last2;k++)
                b[k+j*v[i]]+=a[k];
        memcpy(a,b,sizeof(int)*(last2+1));
        last=last2;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    #endif
    while ((scanf("%d%d%d",num,num+1,num+2)==3)&&(num[0]!=0||num[1]!=0|num[2]!=0))
    {
        solve(a,val,lower,num,3);
        int i;
        for(i=1;i<=last;i++) if(!a[i]) break;
        printf("%d\n",i);
    }
    return 0;
}
