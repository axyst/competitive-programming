#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("1.txt","r",stdin);
    long long d,ans=0,k,a,b,t;
    scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t);
    if(d<=k) {printf("%I64d\n",d*a);return 0;}
    d-=k,ans+=k*a;

    long long one=min(b*k,a*k+t);
    ans+=d/k*one,d%=k;
    ans+=min(b*d,a*d+t);

    printf("%I64d\n",ans);
    //fclose(stdin);
    return 0;
}