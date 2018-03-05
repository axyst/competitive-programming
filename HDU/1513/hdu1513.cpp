#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=5000+5;
char a[maxn];char b[maxn];int d[maxn];
int m,n;
int solve()
{
    memset(d,0,sizeof(d));
    for(int i=1;i<=m;i++)
    {
        int lst=0;int len;
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]) len=lst+1;
            else len=max(d[j],d[j-1]);
            lst=d[j];
            d[j]=len;
        }
    }
    return d[n];
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        m=n;
        scanf("%s",a+1);
        for(int i=1;i<=n;i++) b[i]=a[n-i+1];
        //printf("%s",b+1);
        printf("%d\n",n-solve());
    }
    return 0;
}
