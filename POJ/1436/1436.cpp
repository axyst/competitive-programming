#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define delf int m=(l+r)>>1
const int MAXN=8005;
int color[MAXN*2<<2];bool mark[MAXN][MAXN];
struct edge
{
    int y1;int y2;int x;int id;
}s[MAXN];
bool cmp(edge a,edge b){return a.x<b.x;}
void pushdown(int rt)
{
    if(color[rt])
    {
        color[rt<<1]=color[rt<<1|1]=color[rt];
        color[rt]=0;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&R>=r){color[rt]=c;return;}
    pushdown(rt);
    delf;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
}
void query(int L,int R,int c,int l,int r,int rt)
{
    if(color[rt]){mark[c][color[rt]]=1;return;}
    if(l==r) return;
    delf;
    if(L<=m) query(L,R,c,lson);
    if(R>m) query(L,R,c,rson);
}
int main()
{
    int d,n,a,b,c;
    scanf("%d",&d);
    while(d--)
    {
        scanf("%d",&n);
        rel(i,n)
        {
            scanf("%d%d%d",&a,&b,&c);
            s[i].y1=a;s[i].y2=b;s[i].x=c;s[i].id=i;
        }
        sort(s+1,s+n+1,cmp);
        memset(color,0,sizeof(color));
        memset(mark,0,sizeof(mark));
        rel(i,n)
        {
            query(s[i].y1*2,s[i].y2*2,s[i].id,0,MAXN*2,1);
            update(s[i].y1*2,s[i].y2*2,s[i].id,0,MAXN*2,1);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mark[i][j])
                {
                    for(int k=1;k<=n;k++)
                        if(mark[i][k]&&mark[j][k]) ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}