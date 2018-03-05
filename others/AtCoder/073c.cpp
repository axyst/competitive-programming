//Atc:similiar to CF but...
//default compiler is GCC,use %lld
//no ONLINE_JUDGE definition
//some questions don't have English editorial
#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%lld",&(n))
using namespace std;
typedef long long LL;
const int maxn=200000+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
typedef pair<LL,LL> pll;
pll val[maxn];
multiset<LL>m1,m2;
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL n,x,y;
    sl(n);
    //while(~sl(n))
    {
        //m1.clear();m2.clear();
        //memset(val,0,sizeof(val));
        for(LL i=0;i<n;i++)
        {
            sl(x);sl(y);
            if(x>y) swap(x,y);
            val[i].first=x;val[i].second=y;
            m1.insert(x);
            m2.insert(y);
        }
        sort(val,val+n);
        LL ans=(*m1.rbegin()-*m1.begin())*(*m2.rbegin()-*m2.begin());
        for(LL i=0;i<n;i++)
        {
            m1.erase(m1.find(val[i].first));
            m2.erase(m2.find(val[i].second));
            m1.insert(val[i].second);
            m2.insert(val[i].first);
            ans=min(ans,(*m1.rbegin()-*m1.begin())*(*m2.rbegin()-*m2.begin()));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
