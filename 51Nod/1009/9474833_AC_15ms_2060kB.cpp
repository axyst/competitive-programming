//http://blog.csdn.net/fool_ran/article/details/42618937
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0;
        int mul=1;
        int cur=0,aft=0,bef=0;
        while(n/mul)
        {
            cur=(n/mul)%10;
            bef=n/(mul*10);
            aft=n-(n/mul)*mul;
            if(cur==0) ans+=bef*mul;
            else if(cur==1) ans+=bef*mul+aft+1;
            else ans+=(bef+1)*mul;
            mul*=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}
