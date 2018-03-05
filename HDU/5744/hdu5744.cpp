#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int odd=0,even=0;
        for(int i=0;i<n;i++)
        {
            int a;scanf("%d",&a);
            if(a&1) odd++,even+=(a-1);
            else even+=a;
        }
        even/=2;
        if(odd) printf("%d\n",(even/odd)*2+1);
        else printf("%d\n",even*2);
    }
    return 0;
}