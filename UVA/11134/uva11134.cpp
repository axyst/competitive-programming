#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5005;
struct node
{
    int xl;int yl;int xr;int yr;
    int x;int y;
}nd[maxn];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&nd[i].xl,&nd[i].yl,&nd[i].xr,&nd[i].yr);
            nd[i].x=-1,nd[i].y=-1;
        }
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            int putx=-1,mnx=n+1;
            for(int j=0;j<n;j++)
                if(nd[j].x<0&&nd[j].xl<=i&&nd[j].xr<mnx)
                    mnx=nd[putx=j].xr;
            if(putx<0||i>mnx){flag=0;break;}
            nd[putx].x=i;
        }
        if(flag)
        for(int i=1;i<=n;i++)
        {
            int puty=-1,mny=n+1;
            for(int j=0;j<n;j++)
                if(nd[j].y<0&&nd[j].yl<=i&&nd[j].yr<mny)
                    mny=nd[puty=j].yr;
            if(puty<0||i>mny){flag=0;break;}
            nd[puty].y=i;
        }
        if(flag)
        {
            for(int i=0;i<n;i++)
                printf("%d %d\n",nd[i].x,nd[i].y);
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
