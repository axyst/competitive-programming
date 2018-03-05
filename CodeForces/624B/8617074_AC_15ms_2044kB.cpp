#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1e3+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
LL a[30];
bool cmp(LL a,LL b)
{
    return a>b;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n;cin>>n;int tmp;
    rep(i,n)
    {
        scanf("%I64d",a+i);
    }
    sort(a,a+n,cmp);
    bool flag=1;
    while(flag)
    {
        flag=0;
        rep(i,n)
        for(int j=0;j<n&&j!=i;j++)
        if(a[i]==a[j]&&a[j]>0&&a[i]>0)
        {
            //cout<<a[i]<<' '<<a[j]<<' '<<endl;
            a[j]--;
            flag=1;
            break;
        }
    }
    //rep(i,n) cout<<a[i]<<endl;
    LL ans=0;
    rep(i,n) ans+=a[i];
    cout<<ans<<endl;
    return 0;
}
