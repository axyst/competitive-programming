#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef int LL;
const int inf=0x3f3f3f3f;
const int maxn=1000+5;
const int mod=29;
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;cin>>t;int a,b;
    while(t--)
    {
        cin>>a>>b;
        if(a<b) cout<<"WeWillEatYou"<<endl;
        else cout<<"FunkyMonkeys"<<endl;

    }
    return 0;
}