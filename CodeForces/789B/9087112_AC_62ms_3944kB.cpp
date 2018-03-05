#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<LL,int>vis;
int main()
{
    vis.clear();
    LL b;int q,l,m,tmp;
    scanf("%I64d%d%d%d",&b,&q,&l,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&tmp);
        vis[tmp]=1;
    }
    if(abs(b)>l||(!b&&vis[0])||(q==1&&vis[b])||(q==-1&&vis[b]&&vis[-b])
       ||(!q&&b&&vis[b]&&vis[0])||(!b&&vis[0]))
    {
        printf("0\n");
        return 0;
    }
    else if((q==1&&!vis[b])||(q==-1&&(!vis[b]||!vis[-b]))||(!q&&b&&!vis[0])||!b)
    {
        printf("inf\n");
        return 0;
    }
    else if(!q&&b&&!vis[b])
    {
        printf("1\n");
        return 0;
    }
    int cnt=0;
    for(;abs(b)<=l;b*=q)
        if(!vis[b]) cnt++;
    printf("%d\n",cnt);
    return 0;
}