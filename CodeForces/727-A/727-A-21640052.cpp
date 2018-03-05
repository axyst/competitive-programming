#include<bits/stdc++.h>
#define rep(i,a) for(int i=0;i<a;i++)
#define rel(i,a) for(int i=1;i<=a;i++)
using namespace std;
typedef long long LL;
const int MAXN=200000;
LL out[MAXN];
LL a,b;
LL k=1;
int main()
{
    scanf("%I64d%I64d",&a,&b);
    out[0]=b;
    while(a<b)
    {
        if(b%2)
        {
            out[k++]=(b-1)/10;
            b=(b-1)/10;
        }
        else
        {
            out[k++]=b/2;
            b/=2;
        }
    }
    if(a==b&&(out[k-1]*2==out[k-2]||out[k-1]*10+1==out[k-2])) printf("YES\n");
    else {printf("NO\n");return 0;}
    printf("%I64d\n",k);
    for(int i=k-1;i>=0;i--) printf("%I64d\n",out[i]);
}