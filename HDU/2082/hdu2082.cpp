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
const int maxn=100+5;
int a[maxn];int v[maxn];int n1[maxn];int n2[maxn];const int K=26;
int b[maxn];
void solve()
{
    int P=50;
    a[0]=1;
    int last=0;
    for(int i=0;i<K;i++)
    {
        int last2=min(last+n2[i]*v[i],P);
        memset(b,0,sizeof(int)*(last2+1));
        for (int j=0;j<=n2[i]&&j*v[i]<=last2;j++)
            for (int k=0;k<=last&&k+j*v[i]<=last2;k++)
                b[k+j*v[i]]+=a[k];
        memcpy(a,b,sizeof(int)*(last2+1));
        last=last2;
    }
    int sum=0;
    for(int i=1;i<=50;i++) sum+=a[i];
    printf("%d\n",sum);
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
    
    int t;si(t);
    for(int i=0;i<K;i++) v[i]=i+1;
    while(t--)
    {
        for(int i=0;i<K;i++) scanf("%d",n2+i);
        solve();
    }
    //while(1) continue;
    return 0;
}
