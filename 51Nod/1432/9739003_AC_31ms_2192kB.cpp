#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1000005;
LL a[maxn];
bool cmp(int a,int b){return a>b;}
int main()
{
    ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;LL m;
    while(scanf("%d%I64d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%I64d",a+i);
        sort(a,a+n,cmp);
        int L=0,R=n-1;
        int ans=0;
        while(L<R)
        {
            if(a[L]+a[R]<=m) R--;
            L++;
            ans++;
        }
        if(L==R) ans++;
        printf("%d\n",ans);
    }
}
