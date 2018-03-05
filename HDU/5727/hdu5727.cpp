#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
int som[13][13];
int pic[13][13];
int per[13];
int pre[13];
int vis[13];
int n,m;
bool dfs(int x)
{
    for(int i=1;i<=n;i++)
        if(pic[x][i])
        {
            if(!vis[i])
            {
                vis[i]=1;
                if(pre[i]==-1||dfs(pre[i]))
                {
                    pre[i]=x;
                    return 1;
                }
            }
        }
    return 0;
}
int hungarian()
{
    int cnt=0;
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    return n-cnt;
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {

        memset(som,0,sizeof(som));
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            som[a][b]=1;
        }
        if(!n||!m)
        {
            printf("0\n");
            continue;
        }
        //cout<<"ended"<<endl;
        for(int i=1;i<=n;i++) per[i]=i;
        int ans=INF;
        do
        {
            memset(pic,0,sizeof(pic));
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    int bef=(i==1?n:i-1);
                    if (!som[j][per[i]]&&!som[j][per[bef]])
                        pic[j][i]=1;
                }
            ans=min(ans,hungarian());
        }while(next_permutation(per+1,per+n));
        printf("%d\n",ans);
    }
    return 0;
}
