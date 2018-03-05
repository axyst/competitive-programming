#include<bits/stdc++.h>
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
int sq(int a)
{
    for(int i=3;i<=a;i++)
        if(a%i==0) return i;
    return 0;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int n;
    while(~si(n))
    {
        printf("%d\n",sq(n)-1);
    }
    return 0;
}
