#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int mod=10;
int a[105];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        int div=sqrt(n);
        while(n%div) div--;
        int ans=2*div+2*(n/div);
        printf("%d\n",ans);
    }
    return 0;
}