#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
int const maxn=100005;
int start[maxn],ans[maxn];//start DESK->X ans X->desk
int G[maxn][1];
vector<int> dep[maxn];
int t[maxn];
int vis[maxn];
void dfs(int now,int deep,int num)
{
    dep[num].push_back(ans[now]);
    if(!vis[ans[G[now][0]]])
    {
        vis[ans[G[now][0]]]=num;
        t[ans[G[now][0]]]=deep;
        dfs(G[now][0],deep+1,num);
    }
    return;
}
int main()
{
    memset(start,0,sizeof(start));
    memset(ans,0,sizeof(ans));
    memset(G,0,sizeof(G));
    memset(dep,0,sizeof(dep));
    memset(t,0,sizeof(t));
    memset(vis,0,sizeof(vis));

    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    ans[0]=0;
    int y;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&start[i+1],&y);
        ans[start[i+1]]=i+1;;
        G[start[i+1]][0]=y;
    }
    int c=1;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=c;
            t[i]=0;
            //printf("i=%d\n",i);
            dfs(start[i],1,c++);
        }
    }
    while(k--)
    {
        int s,w;
        scanf("%d%d",&s,&w);
        int circle=dep[vis[s]].size();
        if(circle==1)
            printf("%d\n",s);
        else
        {   int q=w%circle;
            printf("%d\n",dep[vis[s]][(q+t[s])%circle]);
        }

    }
    return 0;
}