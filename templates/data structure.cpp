//树状数组 RMQ 线段树 treap splay
//主席树
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
//BIT 每次操作O(logn)
int vis[maxs];
int lowbit(int x){return x & -x;}
void add(int x,int v)
{
    while(x<=maxs)
    {
        vis[x]+=v;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=vis[x];
        x-=lowbit(x);
    }
    return ret;
}
// sum
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    void init(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void init(vector<int> a) {
        init(a.size());
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
};
// min
struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;
    void init(int n) {
        this->n = n;
        bit.assign(n, INF);
    }
    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }
    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
    void init(vector<int> a) {
        init(a.size());
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }
};
// 2D sum
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;
    // init(...) { ... }
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }
    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};
//RMQ O(nlogn)预处理 O(1)查询
const int maxn=100010;
int st[25][maxn];
void RMQinit(int n)
{
    int tlog=log2(n);
    for(int i=1;i<=n;i++) scanf("%d",&st[0][i]);
    for(int i=1;i<=tlog;i++)
    {
        int len=1<<(i-1),nlim=n-(1<<i)+1;
        for(int j=1;j<=nlim;j++)
        st[i][j]=max(st[i-1][j],st[i-1][j+len]);
    }
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(st[k][L],st[k][R-(1<<k)+1]);
}
//sequence tree O(logn)
#include<bits/stdc++.h>
using namespace std;
#define lson (cur*2)
#define rson (cur*2+1)
typedef long long LL;
const int INF=0x3f3f3f3f;
int Left;int Right;int v;int op;
const int maxn=(20005)<<4;
struct Node
{
    int sumv[maxn];int minv[maxn];int maxv[maxn];
    int addv[maxn];int setv[maxn];
    void pushup(int cur,int curl,int curr)//更新当前结点
    {
        if(curr>curl)//根据子结点的值，更新当前结点的值
        {
            sumv[cur]=sumv[lson]+sumv[rson];
            minv[cur]=min(minv[lson],minv[rson]);
            maxv[cur]=max(maxv[lson],maxv[rson]);
        }
        if(setv[cur]>=0)//如果当前结点有置数标记，根据置数标记的值，更新当前结点的值
        {
            minv[cur]=maxv[cur]=setv[cur];
            sumv[cur]=setv[cur]*(curr-curl+1);
        }
        if(addv[cur]!=0)//如果当前结点有加法标记，根据加法标记的值，更新当前结点的值（先置后加）
        {
            minv[cur]+=addv[cur];
            maxv[cur]+=addv[cur];
            sumv[cur]+=addv[cur]*(curr-curl+1);
        }
    }
    void pushdown(int cur)//向子结点传递标记
    {
        if(setv[cur]>=0)//如果当前结点有置数标记，把标记传给子结点，清空【子结点的加法标记】，和当前结点的置数标记
        {
            setv[lson]=setv[rson]=setv[cur];
            addv[lson]=addv[rson]=0;
            setv[cur]=-1;
        }
        if(addv[cur]!=0)//如果当前结点有加法标记，把标记传给子结点，清空当前结点的加法标记
        {
            addv[lson]+=addv[cur];
            addv[rson]+=addv[cur];
            addv[cur]=0;
        }
    }
    void update(int cur,int curl,int curr)
    {
        if(Left<=curl&&Right>=curr)
        {
            if(op==1) addv[cur]+=v;
            else
            {
                setv[cur]=v;
                addv[cur]=0;
            }
        }
        else
        {
            pushdown(cur);
            int mid=curl+(curr-curl)/2;
            if(Left<=mid) update(lson,curl,mid);
            else pushup(lson,curl,mid);
            if(Right>mid) update(rson,mid+1,curr);
            else pushup(rson,mid+1,curr);
        }
        pushup(cur,curl,curr);
    }
    int query(int cur,int curl,int curr,int &sm,int &mn,int &mx)
    {
        pushup(cur,curl,curr);
        if(Left<=curl&&Right>=curr)
        {
            sm=sumv[cur];
            mn=minv[cur];
            mx=maxv[cur];
        }
        else
        {
            pushdown(cur);
            int mid=curl+(curr-curl)/2;
            int lsm=0,lmn=INF,lmx=-INF;
            int rsm=0,rmn=INF,rmx=-INF;
            if(Left<=mid) query(lson,curl,mid,lsm,lmn,lmx);
            else pushup(lson,curl,mid);
            if(Right>mid) query(rson,mid+1,curr,rsm,rmn,rmx);
            else pushup(rson,mid+1,curr);
            sm=lsm+rsm;
            mn=min(lmn,rmn);
            mx=max(lmx,rmx);
        }
    }
}nds[25];//开二维矩阵，row=25（实际上可以拼接成一维线段树）
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int r,c,m;
    int q,w,x,y,z;
    while(scanf("%d%d%d",&r,&c,&m)==3)
    {

        memset(nds,0,sizeof(nds));
        for(int i=1;i<=r;i++)
        {
            memset(nds[i].setv,-1,sizeof(nds[i].setv));
            nds[i].setv[1]=0;
        }
        while(m--)
        {
            scanf("%d%d%d%d%d",&op,&w,&Left,&y,&Right);
            if(op==3)
            {
                int sm=0,mn=INF,mx=-INF;
                for(int i=w;i<=y;i++)
                {
                    int tsm,tmn,tmx;
                    nds[i].query(1,1,c,tsm,tmn,tmx);
                    sm+=tsm;mn=min(mn,tmn);mx=max(mx,tmx);
                }
                printf("%d %d %d\n",sm,mn,mx);
            }
            else
            {
                scanf("%d",&v);
                for(int i=w;i<=y;i++) nds[i].update(1,1,c);
            }
        }
    }
    return 0;
}
//Treap
struct Treap
{
    struct node
    {
        int v,tot,sz,rnd,ch[2];
    }*t;
    int sz,root,tmp;
    void init(long long int n)
    {
        t=(node*)malloc(sizeof(node)*n+10);
    }
    void update(int x)
    {
        t[x].sz=t[t[x].ch[0]].sz+t[t[x].ch[1]].sz+t[x].tot;
    }
    void turn(int &x,int k)
    {
        int y=t[x].ch[k^1];
        t[x].ch[k^1]=t[y].ch[k];
        t[y].ch[k]=x;
        update(x);
        update(y);
        x=y;
    }
    void insert(int &x,int v)
    {
        if(!x) t[++sz].v=v,t[sz].rnd=rand(),t[sz].tot=t[sz].sz=1,x=sz;
        else
        {
            if(t[x].sz++,t[x].v==v)t[x].tot++;
            else if(insert(t[x].ch[tmp=v>t[x].v],v),t[t[x].ch[tmp]].rnd>t[x].rnd)turn(x,tmp^1);
        }
    }
    void del(int &x,int v)
    {
        if(!x)return;
        if(t[x].v==v)
        {
            if(t[x].tot>1)t[x].tot--,t[x].sz--;
            else
            {
                if(!(t[x].ch[0]&&t[x].ch[1]))x=t[x].ch[0]|t[x].ch[1];
                else turn(x,tmp=t[t[x].ch[0]].rnd>t[t[x].ch[1]].rnd),t[x].sz--,del(t[x].ch[tmp],v);
            }
        }
        else t[x].sz--,del(t[x].ch[v>t[x].v],v);
    }
    int askRank(int x,int v)
    {
        if(t[x].v==v)return t[t[x].ch[0]].sz+1;
        if(t[x].v<v)return t[t[x].ch[0]].sz+t[x].tot+askRank(t[x].ch[1],v);
        else return askRank(t[x].ch[0],v);
    }
    int askKth(int x,int v)
    {
        if(!x)return 0;
        if(v<=t[t[x].ch[0]].sz)return askKth(t[x].ch[0],v);
        else if(v>t[t[x].ch[0]].sz+t[x].tot)return askKth(t[x].ch[1],v-t[t[x].ch[0]].sz-t[x].tot);
        else return t[x].v;
    }
    int pre(int v)
    {
        insert(root,v);
        tmp=askKth(root,askRank(root,v)-1);
        del(root,v);
        return tmp;
    }
    int find(int x,int v)
    {
        return t[x].v==v?x:find(t[x].ch[t[x].v<v],v);
    }
    int sub(int v)
    {
        insert(root,v);
        tmp=askKth(root,askRank(root,v)+t[find(root,v)].tot);
        del(root,v);
        return tmp;
    }
} treap;

int main()
{
    int n;
    scanf("%d",&n);
    treap.init(n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        switch(a)
        {
        case 1:
            treap.insert(treap.root,b);
            break;
        case 2:
            treap.del(treap.root,b);
            break;
        case 3:
            printf("%d\n",treap.askRank(treap.root,b));
            break;
        case 4:
            printf("%d\n",treap.askKth(treap.root,b));
            break;
        case 5:
            printf("%d\n",treap.pre(b));//小于b，且最大的数
            break;
        case 6:
            printf("%d\n",treap.sub(b));//大于b，且最小的数
            break;
        }
    }
    return 0;
}
//Splay
struct splaytree
{
    LL son[maxn][2],pre[maxn],val[maxn];
    LL rt,Size;//size为节点的标志
    inline void Rotate(LL x,LL c)
    {
      LL y=pre[x];
      son[y][!c]=son[x][c];
      pre[son[x][c]]=y;
      pre[x]=pre[y];
      if(pre[x])  son[pre[y]][son[pre[y]][1]==y]=x;
      son[x][c]=y;
      pre[y]=x;
    }
    inline void Splay(LL x,LL goal)
    {
        while(pre[x]!=goal)
        {
            if(pre[pre[x]]==goal)
            {
                if(son[pre[x]][0]==x)
                     Rotate(x,1);
                else
                    Rotate(x,0);
            }
            else
            {
               LL y=pre[x],z=pre[y];
               if(son[z][0]==y)
               {
                  if(son[y][0]==x)
                      Rotate(y,1),Rotate(x,1);
                  else
                      Rotate(x,0),Rotate(x,1);
               }
               else
               {
                   if(son[y][1]==x)
                      Rotate(y,0),Rotate(x,0);
                   else
                      Rotate(x,1),Rotate(x,0);
               }
            }
        }
        if(goal==0) rt=x;
    }
    inline void Newnode(LL y,LL &x,LL a)
    {
        x=++Size;
        pre[x]=y;
        val[x]=a;
        son[x][0]=son[x][1]=0;
    }
    inline void init()
    {
        Size=0;
        Newnode(0,rt,-inf);
        Newnode(rt,son[rt][1],inf);
    }
    inline void Insert(LL a)//插入后即进行splay，同步更新
    {
        LL x=rt;
        while(son[x][val[x]<a]) x=son[x][val[x]<a];
        Newnode(x,son[x][val[x]<a],a);
        Splay(Size,0);
    }
    inline void Delete_pos(LL x)//删除节点
    {
        Splay(x,0);
        LL tmp=son[rt][1];
        while(son[tmp][0]) tmp=son[tmp][0];//找到根节点右子树最小元素（往左找）
        Splay(tmp,rt);//将它移到根节点的右儿子
        son[tmp][0]=son[rt][0];//将后继作为根节点，根节点删除。
        pre[son[rt][0]]=tmp;
        pre[tmp]=0;
        rt=tmp;//后继成为根节点
    }
    inline LL Find(LL a)//找位置
    {
        LL x=rt;
        while(x)
        {
            if(val[x]==a) return x;
            if(val[x]>a) x=son[x][0];
            else x=son[x][1];
        }
        return 0;
    }
    inline LL fx_min(LL a)//找比a大的最小值
    {
        LL x=rt,minn=inf;
        while(x)
        {
            if(val[x]==a) return a;
            if(val[x]>a) minn=min(minn,val[x]);
            if(val[x]>a) x=son[x][0];
            else x=son[x][1];
        }
        return minn;
    }
    inline LL fx_max(LL a)//找比a小的最大值
    {
        LL x=rt,maxx=-inf;
        while(x)
        {
            if(val[x]==a) return a;
            if(val[x]<a) maxx=max(maxx,val[x]);
            if(val[x]<a) x=son[x][1];
            else x=son[x][0];
        }
        return maxx;
    }
}spt;
//主席树(persistent segment tree)
///给出一个序列，查询区间内有多少个不相同的数
#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int maxn=1e6+5;
const int MAXN=30010;
const int M=MAXN*100;
int n,q,tot;
int a[MAXN];
int T[MAXN],lson[M],rson[M],c[M];
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if(l != r)
    {
        int mid=(l+r)>>1;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+ val;
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(pos<=mid)
        {
            lson[newroot]=tot++;
            rson[newroot]=rson[root];
            newroot=lson[newroot];
            root=lson[root];
            r=mid;
        }
        else
        {
            rson[newroot]=tot++;
            lson[newroot]=lson[root];
            newroot=rson[newroot];
            root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+ val;
    }
    return tmp;
}
int query(int root,int pos)
{
    int ret=0;
    int l=1,r=n;
    while(pos<r)
    {
        int mid=(l+r)>>1;
        if(pos<=mid)
        {
            r=mid;
            root=lson[root];
        }
        else
        {
            ret += c[lson[root]];
            root=rson[root];
            l=mid+1;
        }
    }
    return ret+c[root];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
        tot=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        T[n+1]=build(1,n);
        map<int,int>mp;
        for(int i=n;i>=1;i--)
        {
            if(mp.find(a[i])==mp.end())
            {
                T[i]=update(T[i+1],i,1);
            }
            else
            {
                int tmp=update(T[i+1],mp[a[i]],-1);
                T[i]=update(tmp,i,1);
            }
            mp[a[i]]=i;
        }
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(T[l],r));
        }
    }
    return 0;
}
///静态区间第k大
const int MAXN=100010;
const int M=MAXN*30;
int n,q,m,tot;
int a[MAXN],t[MAXN];
int T[MAXN],lson[M],rson[M],c[M];
void Init_hash()
{
    for(int i=1;i<=n;i++)
    t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if(l!=r)
    {
        int mid=(l+r)>>1;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int hash(int x)
{
    return lower_bound(t+1,t+1+m,x)-t;
}
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+ val;
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(pos<=mid)
        {
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else
        {
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int left_root,int right_root,int k)
{
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(c[lson[left_root]]-c[lson[right_root]]>=k)
        {
            r=mid;
            left_root=lson[left_root];
            right_root=lson[right_root];
        }
        else
        {
            l=mid+1;
            k-=c[lson[left_root]]- c[lson[right_root]];
            left_root=rson[left_root];
            right_root=rson[right_root];
        }
    }
    return l;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&q)==2)
    {
        tot=0;
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        Init_hash();
        T[n+1]=build(1,m);
        for(int i=n;i;i--)
        {
            int pos=hash(a[i]);
            T[i]=update(T[i+1],pos,1);
        }
        while(q--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",t[query(T[l],T[r+1],k)]);
        }
    }
    return 0;
}
// Sqrt Decomposition (Mo's algorithm)  分块 (一层sqrt(n)叉的线段树)
// query only 每次O(logn)
int n;
vector<int> a (n);

int len = (int) sqrt (n + .0) + 1; // size of the blocks
vector<int> b (len);
for (int i=0; i<n; ++i)
b[i / len] += a[i];

for (;;) {
    int l, r;
    // read input data for the next query
    int sum = 0;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r)
        for (int i=l; i<=r; ++i)
            sum += a[i];
    else {
        for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
        sum += a[i];
        for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
        for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
    }
}
// Mo 离线操作O((m+n)√n) 预处理O(mlogm) (m为查询次数）
bool cmp(pair<int, int> p, pair<int, int> q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
}
void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}