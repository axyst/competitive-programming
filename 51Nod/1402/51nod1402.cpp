#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1000000+5;
int x[55];int t[55];int pos[maxn];int pt[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int T,n,m;scanf("%d",&T);
   while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(pos,-1,sizeof(pos));
        int ans=0;int out=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",x+i,t+i);
            pos[x[i]]=t[i];
        }
        pos[1]=0;
        for(int i=1;i<=n;i++)
        {
            ans++;
            if(~pos[i]) ans=min(ans,pos[i]);
            pt[i]=ans;
        }
        ans=n;
        for(int i=n;i>=1;i--)
        {
            ans++;
            if(~pos[i]) ans=min(ans,pos[i]);
            pt[i]=min(pt[i],ans);
            out=max(out,pt[i]);
        }
        printf("%d\n",out);
    }
    return 0;
}