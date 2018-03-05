#include<bits/stdc++.h>
using namespace std;
#define lson (cur*2)
#define rson (cur*2+1)
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=500005;
struct Node
{
    pii max_sub;
    int max_prefix;int max_suffix;
}node[maxn<<2];
LL prefix_sum[maxn];//use LL
LL intersum(int a,int b){return prefix_sum[b]-prefix_sum[a-1];}//use LL
pii cmp(pii a,pii b)
{
    LL sa=intersum(a.first,a.second);
    LL sb=intersum(b.first,b.second);
    if(sa==sb) return a<b?a:b;
    return sa>sb?a:b;
}
void setval(int cur,int curl,int curr)
{
    node[cur].max_sub=pii(curl,curl);
    node[cur].max_prefix=node[cur].max_suffix=curl;
}
void pushup(int cur,int curl,int curr)
{
    LL lv=intersum(curl,node[lson].max_prefix);
    LL rv=intersum(curl,node[rson].max_prefix);
    if(lv>rv) node[cur].max_prefix=node[lson].max_prefix;
    else if(lv<rv) node[cur].max_prefix=node[rson].max_prefix;
    else node[cur].max_prefix=min(node[lson].max_prefix,node[rson].max_prefix);

    lv=intersum(node[lson].max_suffix,curr);
    rv=intersum(node[rson].max_suffix,curr);
    if(lv>rv) node[cur].max_suffix=node[lson].max_suffix;
    else if(lv<rv) node[cur].max_suffix=node[rson].max_suffix;
    else node[cur].max_suffix=min(node[lson].max_suffix,node[rson].max_suffix);

    node[cur].max_sub=cmp(node[lson].max_sub,node[rson].max_sub);
    node[cur].max_sub=cmp(node[cur].max_sub,pii(node[lson].max_suffix,node[rson].max_prefix));

}
void build(int cur,int curl,int curr)
{
    if(curl==curr)setval(cur,curl,curr);
    else
    {
        int mid=curl+(curr-curl)/2;
        build(lson,curl,mid);
        build(rson,mid+1,curr);
        pushup(cur,curl,curr);
    }
}
pii query_p(int cur,int curl,int curr,int left,int right)
{
    if(node[cur].max_prefix<=right) return pii(curl,node[cur].max_prefix);
    int mid=curl+(curr-curl)/2;
    if(right<=mid) return query_p(lson,curl,mid,left,right);
    pii tmp=query_p(rson,mid+1,curr,left,right);
    tmp.first=curl;
    return cmp(tmp,pii(curl,node[lson].max_prefix));
}
pii query_s(int cur,int curl,int curr,int left,int right)
{
    if(node[cur].max_suffix>=left) return pii(node[cur].max_suffix,curr);
    int mid=curl+(curr-curl)/2;
    if(left>mid) return query_s(rson,mid+1,curr,left,right);
    pii tmp=query_s(lson,curl,mid,left,right);
    tmp.second=curr;
    return cmp(tmp,pii(node[rson].max_suffix,curr));
}
pii query(int cur,int curl,int curr,int left,int right)
{
    //printf("cur:%d,curl:%d,curr:%d,left:%d,right:%d\n",cur,curl,curr,left,right);
    if(curr<=right&&curl>=left)
    {
        return node[cur].max_sub;
    }
    int mid=curl+(curr-curl)/2;
    if(right<=mid)
    {
        return query(lson,curl,mid,left,right);
    }
    if(left>mid)
    {
        return query(rson,mid+1,curr,left,right);
    }

    pii lval=query_s(lson,curl,mid,left,right);
    pii rval=query_p(rson,mid+1,curr,left,right);
    pii mval=cmp(query(lson,curl,mid,left,right),query(rson,mid+1,curr,left,right));
    return cmp(mval,pii(lval.first,rval.second));
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n,m,a,b,tmp;int ks=1;
    while(scanf("%d%d",&n,&m)==2)
    {
        prefix_sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            prefix_sum[i]=prefix_sum[i-1]+tmp;
        }
        build(1,1,n);
        printf("Case %d:\n",ks++);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            pii ans=query(1,1,n,a,b);
            printf("%d %d\n",ans.first,ans.second);
        }
    }
    return 0;
}
