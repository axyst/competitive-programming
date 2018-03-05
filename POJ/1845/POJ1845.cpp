#define POJ
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
const LL mod=9901;
LL fpow(LL a,LL p)
{
	LL res=1;
	while(p)
	{
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
LL sum(LL p,LL n)
{
	if(n==0) return 1;
	if(n&1) return (1+fpow(p,(n>>1)+1))*sum(p,n>>1)%mod;
	else return ((1+fpow(p,(n>>1)+1))*sum(p,(n-1)>>1)%mod+fpow(p,n>>1))%mod;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL a,b;
    while(~scanf("%I64d%I64d",&a,&b))
    {
    	LL ans=1,tot;LL up=sqrt(a);
    	for(LL i=2;i<=up;i++)
    	{
    		if(a%i==0)
    		{
                tot=0;
	    		while(a%i==0)
	    		{
	    			tot++;
	    			a/=i;
	    		}
	    		ans=ans*sum(i%mod,b*tot)%mod;
    		}
    	}
    	if(a>1) ans=ans*sum(a%mod,b)%mod;
    	printf("%I64d\n",ans);
    }
    return 0;
}
