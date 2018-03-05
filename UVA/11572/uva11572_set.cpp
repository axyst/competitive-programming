#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
int a[maxn];
int main()
{
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);set<int>s;
    while(t--)
    {
        s.clear();
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        int l=0,r=0,ans=1;
        while(l<n)
        {
            while(!s.count(a[r])&&r<n) s.insert(a[r++]);
            ans=max(ans,r-l);
            s.erase(a[l++]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
