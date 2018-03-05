#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%lld",&(n))
using namespace std;
typedef long long LL;
const int maxn=362885;
struct sta
{
    int num;
    int id;
}st[maxn];
bool cmp(sta a,sta b){return a.num<b.num;}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int n;si(n);
    rep(i,0,n-1)
    {
        si(st[i].num);
        st[i].id=i;
    }
    sort(st,st+n,cmp);
    LL ans=0;
    rep(i,0,n-2) ans+=max(st[i].id-st[i+1].id,st[i+1].id-st[i].id);
    printf("%I64d\n",ans);
    return 0;
}