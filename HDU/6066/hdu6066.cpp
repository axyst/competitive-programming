#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int maxn=1e6+5;
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t,a;si(t);int ans=0;
    while(t--)
    {
        si(a);
        if(a<=35) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
