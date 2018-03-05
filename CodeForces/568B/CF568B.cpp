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
const int maxn=4005;
LL b[maxn];
LL c[maxn][maxn];
void getc(int n)
{
	for(int i=0;i<=n;++i)
	{
		c[i][0]=1;
		for(int j=1;j<=i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}
void getbell(int n)
{
	b[0]=b[1]=1;
	for(int i=2;i<=n;++i)
	{
		b[i]=0;
		for(int j=0;j<=i-1;++j)
		{
			b[i]=(b[i]+c[i-1][j]*b[j]%mod)%mod;
		}
	}
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	int n;si(n);
	getc(n+1);getb(n+1);
	LL ans=((b[n+1]-b[n])+mod)%mod;
	printf("%I64d\n",ans);
    return 0;
}