//#define POJ
#ifndef POJ
#include<bits/stdc++.h>
#endif
#ifdef POJ
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#endif
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%lld",&(n))
using namespace std;
typedef long long LL;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
typedef pair<int,int> pii;
vector<pii>va,vc;
vector<int>ans;
const int maxn=1e6+5;
int sum[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
    int n,k;si(n);si(k);
    int cnt=0;
    rep(i,0,n-1)
    {
        int l,r;si(l);si(r);
        va.push_back(make_pair(l,-1));
        va.push_back(make_pair(r,1));
    }
    sort(va.begin(),va.end());
    int cur=0;int sz=va.size();
    rep(i,0,sz-1)
    {
        if(va[i].second==1)
        {
            if(cnt==k) ans.push_back(va[i].first);
            cnt--;
        }
        else
        {
            cnt++;
            if(cnt==k) ans.push_back(va[i].first);
        }
    }
    sz=ans.size()/2;printf("%d\n",sz);
    rep(i,0,sz-1) printf("%d %d\n",ans[i*2],ans[i*2+1]);
    //while(~scanf("%d",&n)) continue;
    return 0;
}
