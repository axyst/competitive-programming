#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dis[155],len[155][155];
bool vis[155];
void Dij(int st,int ed)
{
    int k,tem;
    memset(vis,0,sizeof(vis));
    for(int i=st;i<=ed;i++) dis[i]=(i==st?0:INF);
    for(int i=st;i<=ed;i++)
    {
        tem=INF;
        for(int j=st;j<=ed;j++)
            if(!vis[j]&&dis[j]<tem) tem=dis[k=j];
        vis[k]=1;
        if(tem==INF) break;
        for(int j=st;j<=ed;j++)
            dis[j]=min(dis[j],dis[k]+len[k][j]);
    }
}
int main()
{
    int n,iter,tdis,flag;
    char a[30],b[30],fro[30],to[30];
    map<string,int>pic;
    while(scanf("%d",&n)&&n!=-1)
    {
        pic.clear();
        memset(len,INF,sizeof(len));
        flag=0;
        scanf("%s%s",fro,to);
        if(strcmp(fro,to)==0) flag=1;
        pic[fro]=1;
        pic[to]=2;
        iter=3;
        for(int i=1;i<=n;i++)
        {
            scanf("%s%s%d",a,b,&tdis);
            if(!pic[a]) pic[a]=iter++;
            if(!pic[b]) pic[b]=iter++;
            len[pic[a]][pic[b]]=len[pic[b]][pic[a]]=tdis;
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        Dij(1,iter);
        if(dis[2]==INF) printf("-1\n");
        else printf("%d\n",dis[2]);
    }
    return 0;
}