#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100000+5;
const int mod=1e9+7;
int a[maxn];int b[maxn];int vis[maxn];
vector<int>pria;vector<int>prib;
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int ks=1;int m,n;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(vis,0,sizeof(vis));pria.clear();prib.clear();
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<m;i++) scanf("%d",b+i);
        for(int i=0;i<n;i++)
        {
            int cur=i,sz=1;
            if(!vis[i])
            {
                vis[i]=1;
                while(i!=a[cur])
                {
                    cur=a[cur];
                    vis[cur]=1;
                    sz++;
                }
                pria.push_back(sz);
            }
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int cur=i,sz=1;
            if(!vis[i])
            {
                vis[i]=1;
                while(i!=b[cur])
                {
                    cur=b[cur];
                    vis[cur]=1;
                    sz++;
                }
                prib.push_back(sz);
            }
        }
        LL ans=1;int asz=pria.size();int bsz=prib.size();
        for(int i=0;i<asz;i++)
        {
            LL sum=0;
            for(int j=0;j<bsz;j++)
                if(pria[i]%prib[j]==0)
                    sum=(sum+prib[j])%mod;
            ans=(ans*sum)%mod;
        }
        printf("Case #%d: %I64d\n",ks++,ans);
    }
    return 0;
}
