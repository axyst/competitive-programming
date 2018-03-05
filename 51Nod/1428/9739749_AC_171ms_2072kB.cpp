#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=10005;
struct st
{
    LL a;LL b;
}sts[maxn];
bool cmp(st a,st b)
{
   if(a.b==b.b)return a.a<b.a;
   return a.b<b.b;
}
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%I64d%I64d",&sts[i].a,&sts[i].b);
        sort(sts,sts+n,cmp);
        int ans=1;int mx=1;
        for(int i=0;i<n;i++)
        {
            mx=1;
            for(int j=i+1;j<n;j++)
                if(sts[i].b>sts[j].a) mx++;
            ans=max(mx,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
