#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
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
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t,n,a;rea(t);
    while(t--)
    {
        rea(n);
        int o=0,e=0;
        rep(i,1,n)
        {
            rea(a);
            if(a&1) o++;
            else e++;
        }
        if(o>=e) printf("2 1\n");
        else printf("2 0\n");
    }
    return 0;
}
