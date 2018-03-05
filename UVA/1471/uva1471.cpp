#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
int a[maxn],g[maxn],f[maxn];
struct st
{
    int a;int g;
    bool operator <(const st &rhs) const
    {
        return a<rhs.a;
    }
};
set<st>s;
int main()
{
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        if(n==1){printf("1\n");continue;}

        g[0]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1]) g[i]=g[i-1]+1;
            else g[i]=1;
        }

        f[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i+1]>a[i]) f[i]=f[i+1]+1;
            else f[i]=1;
        }

        s.clear();
        s.insert((st){a[0],g[0]});
        int ans=1;
        for(int i=1;i<n;i++)
        {
            st tst=(st){a[i],g[i]};
            set<st>::iterator it=s.lower_bound(tst);
            bool keep=1;
            if(it!=s.begin())
            {
                st lst=*(--it);
                int len=f[i]+lst.g;
                ans=max(ans,len);
                if(tst.g<=lst.g) keep=0;
            }

            if(keep)
            {
                s.erase(tst);s.insert(tst);
                it=s.find(tst);it++;
                while(it!=s.end()&&it->a>tst.a&&it->g<=tst.g) s.erase(it++);
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
