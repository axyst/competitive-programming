//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
int n,q,m,tot;
int a[maxn],t[maxn];
int T[maxn],ls[maxn*30],rs[maxn*30],c[maxn*30];
void init()
{
    for(int i=1;i<=n;i++) t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-(t+1);//unique返回去重后最末元素的地址
}
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        ls[root]=build(l,mid);
        rs[root]=build(mid+1,r);
    }
    return root;
}
int update(int root,int pos,int val)
{
    int nroot=tot++;int tmp=nroot;
    c[nroot]=c[root]+val;
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            ls[nroot]=tot++;rs[nroot]=rs[root];
            nroot=ls[nroot];root=ls[root];
            r=mid;
        }
        else
        {
            rs[nroot]=tot++;ls[nroot]=ls[root];
            nroot=rs[nroot];root=rs[root];
            l=mid+1;
        }
        c[nroot]=c[root]+val;
    }
    return tmp;
}
int query(int lroot,int rroot,int k)
{
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(c[ls[lroot]]-c[ls[rroot]]>=k)
        {
            r=mid;
            lroot=ls[lroot];
            rroot=ls[rroot];
        }
        else
        {
            l=mid+1;
            k-=c[ls[lroot]]-c[ls[rroot]];
            lroot=rs[lroot];
            rroot=rs[rroot];
        }
    }
    return l;
}
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&q)==2)
    {
        tot=0;
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        init();
        T[n+1]=build(1,m);
        for(int i=n;i>=1;i--)
        {
            int pos=lower_bound(t+1,t+1+m,a[i])-t;
            T[i]=update(T[i+1],pos,1);
        }
        while(q--)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            int id=query(T[x],T[y+1],z);
            printf("%d\n",t[id]);
        }

    }
}
