#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
int a[maxn],lst[maxn];
map<int,int>m;
int main()
{
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        m.clear();
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            if(!m.count(a[i])) lst[i]=-1;
            else lst[i]=m[a[i]];
            m[a[i]]=i;
        }
        int l=0,r=0,ans=1;
        while(r<n)
        {
            while(lst[r]<l&&r<n) r++;
            ans=max(ans,r-l);
            l++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
