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
const int MAXN=500000+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
int st[MAXN];
int l,n,m,tmp;
int solve(int len)
{
    int cnt=0;int cur=0;int i=0;
    while(cur<l)
    {
        cur+=len;
        while(st[i+1]<=cur) i++;
        cur=st[i];
        //cout<<cur<<endl;
        cnt++;
    }
    return cnt;
}
int main()
{
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        rel(i,n) scanf("%d",st+i);
        sort(st+1,st+n+1);
        st[0]=0,st[n+1]=l,st[n+2]=INF;
        int mx=0;
        rel(i,n+1) mx=max(mx,st[i]-st[i-1]);
        //for(int i=mx;i<l;i++)
            //cout<<solve(i)<<endl;


        int left=mx,right=l,mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(solve(mid)<=m) right=mid;
            else left=mid+1;
        }
        printf("%d\n",right);

    }
    return 0;
}