#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxm=1e5*2+5;int n;int m;
int father[maxm];
struct edge
{
    int from;int to;LL weight;
}edges[maxm];
bool cmp(edge a,edge b){return a.weight<b.weight;}
bool cmp2(edge a,edge b){return a.weight>b.weight;}
int look(int x){return father[x]==x?x:father[x]=look(father[x]);}
LL Kruskal()
{
    for(int i=0;i<=n;i++) father[i]=i;
    sort(edges,edges+m,cmp);
    //for(int i=0;i<m;i++) cout<<edges[i].weight<<endl;
    LL mx=0;LL sum=0;int nn=n;
    for(int i=0;i<m;i++)
    {
       int ft=look(edges[i].from);int tt=look(edges[i].to);
        if(ft!=tt)
        {
            father[ft]=tt;
            if(mx<=edges[i].weight) mx=edges[i].weight;
            if(--nn==1) break;
        }
    }
    sort(edges,edges+m,cmp2);
    for(int i=0;i<=n;i++) father[i]=i;
    nn=n;
    for(int i=0;i<m;i++)
    {
        int ft=look(edges[i].from);int tt=look(edges[i].to);
        if(ft!=tt)
        {
            if(mx>=edges[i].weight)
            {
                father[ft]=tt;
                sum+=edges[i].weight;
                //cout<<sum<<endl;
                if(--nn==1) break;
            }

        }
    }
    return sum;
}
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b;LL c;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%I64d",&a,&b,&c);
            edges[i].from=a;edges[i].to=b;edges[i].weight=c;
        }
        LL ans=Kruskal();
        printf("%I64d\n",ans);
    }
    return 0;
}