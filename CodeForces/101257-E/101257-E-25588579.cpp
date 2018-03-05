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
const int MAXN=1e5+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int a[5],b[5];
int main()
{
    rep(i,3) scanf("%d",a+i);
    rep(i,3) scanf("%d",b+i);
    int cnt=0;
    rep(i,3)
    {
        rep(j,3)
        if(a[i]==b[j])
        {
            cnt++;
            continue;
        }
    }
    if(!cnt) cout<<6<<endl;
    if(cnt==2) cout<<4<<endl;
    if(cnt==1) cout<<6<<endl;

    return 0;
}
close