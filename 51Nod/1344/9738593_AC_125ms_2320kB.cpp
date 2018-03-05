#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=50005;
LL a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1)
    {
        LL ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",a+i);
            sum+=a[i];
            ans=min(sum,ans);
        }
         cout<<-ans<<endl;
    }
}
