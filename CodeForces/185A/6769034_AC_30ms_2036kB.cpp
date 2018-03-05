#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#define LL long long
using namespace std;
const int mod=1000000007;
//const int N=10;
//const int MAXN=1e7+5;
//int a[MAXN];
LL ans=1,ans2=1;
LL fastpow(LL base,LL po)
{
    LL a=1;
    while(po)
    {
        //if(po&1) ans=((ans%mod)*(base%mod))%mod;
        //a=((a%mod)*(a%mod))%mod;
        if(po&1) a=((a%mod)*(base%mod))%mod;
        base=((base%mod)*(base%mod))%mod;
        po>>=1;
    }
    return a;
}
int main()
{
//freopen("test.txt","r".,stdin);
    LL n;
    scanf("%I64d",&n);
    if(n==0) { printf("1\n");return 0;}
    if(n==1) { printf("3\n");return 0;}
    //ans=(fastpow(4,n)%mod-(fastpow(2,2*n-1))%mod+(fastpow(2,n-1))%mod)%mod;
    ans=fastpow(4,n)-fastpow(2,2*n-1)+fastpow(2,n-1);
    if(ans<0) ans=mod+ans;
    if(ans>mod) ans%=mod;
    printf("%I64d\n",ans);

    return 0;
}
