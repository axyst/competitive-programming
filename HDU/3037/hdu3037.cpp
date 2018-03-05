#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const LL maxn=100000+5;
char buf[100000],*p1=buf,*p2=buf;
inline char nc()
{
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x)
{
    //bool IsN=false;
    char c=nc();x=0;
    if(c==EOF) return false;
    //if(c=='-') isN=true;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    //if(isN) x=-x;
    return true;
}
inline bool rea(LL & x)
{
    //bool IsN=false;
    char c=nc();x=0;
    if(c==EOF) return false;
    //if(c=='-') isN=true;
    for(;!isdigit(c);c=nc());
    for(;isdigit(c);x=x*10+c-'0',c=nc());
    //if(isN) x=-x;
    return true;
}
LL F[maxn];
void init(LL p)
{
    F[0] = 1;
    for(int i = 1;i <= p;i++)
        F[i] = F[i-1]*i % (p);
}
LL inv(LL a,LL m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
LL Lucas(LL n,LL m,LL p)
{
    LL ans = 1;
    while(n&&m)
    {
        LL a = n%p;
        LL b = m%p;
        if(a < b)return 0;
        ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
        n /= p;
        m /= p;
    }
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;rea(t);
    while(t--)
    {
        LL n,m,p;
        rea(n);rea(m);rea(p);
        init(p);
        printf("%I64d\n",Lucas(n+m,m,p));
    }
    return 0;
}
