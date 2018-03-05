#include<bits/stdc++.h>
using namespace std;
int father[105];
struct Edge
{
    int pre;
    int next;
    int w;
}edge[5005];
int Cmp(Edge x,Edge y)
{
    return x.w<y.w;
}
int Find(int x)
{
    if(x==father[x]) return x;
    return father[x]=Find(father[x]);
}
int Krus(int n,int m)
{
    for(int i=1;i<=n;i++) father[i]=i;
    sort(edge+1,edge+1+m,Cmp);
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        int fp=Find(edge[i].pre),fn=Find(edge[i].next);
        if(fp!=fn)
        {
            father[fp]=fn;
            sum+=edge[i].w;
        }
    }
    return sum;
}
int main()
{
    int n,m;
    while(scanf("%d",&n)&&n)
    {
        m=n*(n-1)/2;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&edge[i].pre,&edge[i].next,&edge[i].w);
        printf("%d\n",Krus(n,m));
    }
    return 0;
}