//这题数组开小了UVA判的是WA？？
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxm=5005;int n;int m;
int father[maxm];int edges[maxm];int weight[maxm];
int from[maxm];int to[maxm];
int cmp(int a,int b){return weight[a]<weight[b];}
int look(int x){return father[x]==x?x:father[x]=look(father[x]);}
int solve()
{
    for(int i=0;i<m;i++) edges[i]=i;
    sort(edges,edges+m,cmp);
    int ans=INF;
    for(int l=0;l<m;l++)
    {
        for(int i=0;i<=n;i++) father[i]=i;
        int nn=n;
        for(int r=l;r<m;r++)
        {
            int e=edges[r];int ft=look(from[e]);int tt=look(to[e]);
            if(ft!=tt)
            {
                father[ft]=tt;
                if(--nn==1)//合并了n-1次说明全部连通，计算l,r边之差
                {
                    ans=min(ans,abs(weight[edges[r]]-weight[edges[l]]));
                    break;
                }
            }
        }
    }
    if(ans==INF) ans=-1;
    return ans;
}
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,c;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            from[i]=a;to[i]=b;weight[i]=c;
        }
        int ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}
