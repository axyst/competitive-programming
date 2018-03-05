#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=4*1e6+5;
const int MOD=1e9+7;
int cnt;
int vis[maxn];
int ans[maxn];
int lst[maxn];
int dis[maxn];
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int n;
    while(~scanf("%d",&n))
    {
        cnt=0;
        memset(vis,0,sizeof(vis));
        memset(lst,-1,sizeof(lst));
        for(int i=0;i<=1e6;i++) dis[i]=inf;
        queue<int>q;
        vis[1]=dis[1]=1;
        q.push(1);

        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            int zero=(fr*10)%n;
            int one=(fr*10+1)%n;
            if(dis[zero]>dis[fr]+1)
            {
                dis[zero]=dis[fr]+1;
                lst[zero]=fr;
                if(!vis[zero])
                {
                    vis[zero]=1;
                    q.push(zero);
                }
            }
            if(dis[one]>dis[fr]+1)
            {
                dis[one]=dis[fr]+1;
                lst[one]=fr;
                if(!vis[one])
                {
                    vis[one]=1;
                    q.push(one);
                }
            }
            vis[fr]=0;
        }

        int cur=lst[0];
        int last=0;
        while(~cur)
        {
            int tmp=(cur*10)%n;
            if(tmp==last) ans[cnt++]=0;
            else ans[cnt++]=1;
            last=cur;
            cur=lst[last];
        }
        ans[cnt++]=1;
        for(int i=cnt-1;i>=0;i--) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}