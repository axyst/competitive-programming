#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
#define lson (cur*2)
#define rson (cur*2+1)
int n,k;
int a[105];
int d[10005];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(d,0,sizeof(d));
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        int bef=sum;
        sum/=2;
        for(int i=1;i<=n;i++)
            for(int j=sum;j>=a[i];j--)
                d[j]=max(d[j],d[j-a[i]]+a[i]);
        int ans=abs(bef-2*d[sum]);
        printf("%d\n",ans);
    }
    return 0;
}
