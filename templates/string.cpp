//KMP Manacher AC自动机 后缀数组(SA) 后缀自动机(SAM)
//Z-algorithm
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
/*
*kmpNext[]的意思：next'[i]=tnext[tnext[...[tnext[i]]]]
*（直到next'[i]<0或者x[tnext'[i]]!=x[i]）
*这样的预处理可以快一些
 */
void preKMP(char x[],int m,int kmpNext[])
{
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j&&x[i]!=x[j])
        {
            j=kmpNext[j];
        }
        if(x[++i]==x[++j])
        {
            kmpNext[i]=kmpNext[j];
        }
        else
        {
            kmpNext[i]=j;
        }
    }
    return ;
}
//返回x在y中出现的次数，可以重叠
int kmpNext[10010];

int KMP_Count(char x[],int m,char y[],int n)
{
    //  x是模式串，y是主串
    int i,j;
    int ans=0;
    preKMP(x,m,kmpNext);
    i=j=0;
    while(i<n)
    {
        while(-1!=j&&y[i]!=x[j])
        {
            j=kmpNext[j];
        }
        i++,j++;
        if(j >= m)
        {
            ans++;
            j=kmpNext[j];
        }
    }
    return ans;
}
/*
* 扩展KMP
*tnext[i]:x[i...m-1]的最长公共前缀
*extend[i]:y[i...n-1]与x[0...m-1]的最长公共前缀
 */
void pre_EKMP(char x[],int m,int tnext[])
{
    tnext[0]=m;
    int j=0;
    while(j+1<m&&x[j]==x[j+1])j++;
    tnext[1]=j;
    int k=1;
    for(int i=2;i<m;i++)
    {
        int p=tnext[k]+k-1;
        int L=tnext[i-k];
        if(i+L<p+1)tnext[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<m&&x[i+j]==x[j])j++;
            tnext[i]=j;
            k=i;
        }
    }
}
void EKMP(char x[],int m,char y[],int n,int tnext[],int extend[])
{
    pre_EKMP(x,m,tnext);
    int j=0;
    while(j<n&&j<m&&x[j]==y[j])j++;
    extend[0]=j;
    int k=0;
    for(int i=1;i<n;i++)
    {
        int p=extend[k]+k-1;
        int L=tnext[i-k];
        if(i+L<p+1)extend[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<n&&j<m&&y[i+j]==x[j])j++;
            extend[i]=j;
            k=i;
        }
    }
}
//Manacher最长回文子串
const int MAXN=110010;
char Ma[MAXN*2];
int Mp[MAXN*2];
int Manacher(char s[],int len)
{
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0;i<len;i++)
	{
		Ma[l++]=s[i];
		Ma[l++]='#';
	}
	l--;int mxlen=0;
	int mx=0,id=0;
	for(int i=1;i<l;i++)
	{
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx)
		{
			mx=i+Mp[i];
			id=i;
		}
		mxlen=max(mxlen,Mp[i]);
	}
	return mxlen;
}
/*
*abaaba
*i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
*Ma[i]: $ # a # b # a # a $ b  #  a  #
*Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1
 */
char s[MAXN];
int main()
{
	while(scanf("%s",s)==1)
	{
		int len=strlen(s);
		Manacher(s,len);
		int ans=0;
		for(int i=0;i<2*len+2;i++)
			ans=max(ans,Mp[i]-1);
		printf("%d\n",ans);
	}
	return 0;
}
//AC自动机(字典树+KMP)
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
//======================
// HDU 2222
// 求目标串中出现了几个模式串
//====================
struct Trie
{
    int tnext[500010][26],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i=0;i<26;i++)
            tnext[L][i]=-1;
        end[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(tnext[now][buf[i]-'a']==-1)
                tnext[now][buf[i]-'a']=newnode();
            now=tnext[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for(int i=0;i<26;i++)
            if(tnext[root][i]==-1)
                tnext[root][i]=root;
            else
            {
                fail[tnext[root][i]]=root;
                Q.push(tnext[root][i]);
            }
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            for(int i=0;i<26;i++)
                if(tnext[now][i]==-1)
                    tnext[now][i]=tnext[fail[now]][i];
                else
                {
                    fail[tnext[now][i]]=tnext[fail[now]][i];
                    Q.push(tnext[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        int res=0;
        for(int i=0;i<len;i++)
        {
            now=tnext[now][buf[i]-'a'];
            int temp=now;
            while(temp!=root)
            {
                res+=end[temp];
                end[temp]=0;
                temp=fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for(int i=0;i<L;i++)
        {
            printf("id=%3d,fail=%3d,end=%3d,chi=[",i,fail[i],end[i]);
            for(int j=0;j<26;j++)
                printf("%2d",tnext[i][j]);
            printf("]\n");
        }
    }
};
char buf[1000010];
Trie ac;
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ac.init();
        for(int i=0;i<n;i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("%d\n",ac.query(buf));
    }
    return 0;
}
/*
* 后缀数组
* DC3算法，复杂度O(n)
* 所有的相关数组都要开三倍
* Str ：需要处理的字符串(长度为Len)
* Suffix[i] ：Str下标为i ~ Len的连续子串(即后缀)
* Rank[i]:Suffix[i]在所有后缀中的排名
* SA[i]:满足Suffix[SA[1]]<Suffix[SA[2]] ……<Suffix[SA[Len]],即排名为i的后缀为Suffix[SA[i]] (与Rank是互逆运算)
* Heigth[i]:表示Suffix[SA[i]]和Suffix[SA[i-1]]的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀
* Height[Rank[i]]：后缀Suffix[i]和它前一名的后缀的最长公共前缀
*/
const int MAXN=2010;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAXN*3],wb[MAXN*3],wv[MAXN*3],wss[MAXN*3];
int c0(int *r,int a,int b)
{
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b)
{
    if(k==2)
        return r[a]<r[b]||(r[a]==r[b]&&c12(1,r,a+1,b+1));
    else return r[a]<r[b]||(r[a]==r[b]&&wv[a+1]<wv[b+1]);
}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0;i<n;i++)wv[i]=r[a[i]];
    for(i=0;i<m;i++)wss[i]=0;
    for(i=0;i<n;i++)wss[wv[i]]++;
    for(i=1;i<m;i++)wss[i]+=wss[i-1];
    for(i=n-1;i >= 0;i--)
        b[--wss[wv[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n;
    int *san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++)if(i %3!=0)wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc)dc3(rn,san,tbc,p);
    else for(i=0;i<tbc;i++)san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb)wb[ta++]=san[i]*3;
    if(n%3==1)wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++)wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta&&j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++)sa[p]=wa[i++];
    for(;j<tbc;p++)sa[p]=wb[j++];
}
//str和sa也要三倍
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    for(int i=n;i<n*3;i++)
    str[i]=0;
    dc3(str,sa,n+1,m);
    int i,j,k=0;
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k) k--;
        j=sa[rank[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rank[i]]=k;
    }
}
//后缀自动机
const int CHAR=26;
const int MAXN=250010;
struct SAM_Node
{
    SAM_Node *fa,*tnext[CHAR];
    int len;
    int id,pos;
    SAM_Node(){}
    SAM_Node(int _len)
    {
        fa=0;
        len=_len;
        memset(tnext,0,sizeof(tnext));
    }
};
SAM_Node SAM_node[MAXN*2],*SAM_root,*SAM_last;
int SAM_size;
SAM_Node *newSAM_Node(int len)
{
    SAM_node[SAM_size]=SAM_Node(len);
    SAM_node[SAM_size].id=SAM_size;
    return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node *p)
{
    SAM_node[SAM_size]=*p;
    SAM_node[SAM_size].id=SAM_size;
    return &SAM_node[SAM_size++];
}
void SAM_init()
{
    SAM_size=0;
    SAM_root=SAM_last=newSAM_Node(0);
    SAM_node[0].pos=0;
}
void SAM_add(int x,int len)
{
    SAM_Node *p=SAM_last,*np=newSAM_Node(p->len+1);
    np->pos=len;
    SAM_last=np;
    for(;p&&!p->tnext[x];p=p->fa)
    p->tnext[x]=np;
    if(!p)
    {
        np->fa=SAM_root;
        return;
    }
    SAM_Node *q=p->tnext[x];
    if(q->len==p->len+1)
    {
        np->fa=q;
        return;
    }
    SAM_Node *nq=newSAM_Node(q);
    nq->len=p->len+1;
    q->fa=nq;
    np->fa=nq;
    for(;p&&p->tnext[x]==q;p=p->fa)
        p->tnext[x]=nq;
}
void SAM_build(char *s)
{
    SAM_init();
    int len=strlen(s);
    for(int i=0;i<len;i++)
    SAM_add(s[i]-'a',i+1);
}
//加入串后进行拓扑排序。
char str[MAXN];
int topocnt[MAXN];
SAM_Node *topsam[MAXN*2];
int main()
{
    int n=strlen(str);
    SAM_build(str);
    memset(topocnt,0,sizeof(topocnt));
    for(int i=0;i<SAM_size;i++)
    topocnt[SAM_node[i].len]++;
    for(int i=1;i<=n;i++)
    topocnt[i]+=topocnt[i-1];
    for(int i=0;i<SAM_size;i++)
    topsam[--topocnt[SAM_node[i].len]]=&SAM_node[i];
}
//Z-Algorithm http://codeforces.com/blog/entry/3107
//Given a string S of length n, the Z Algorithm produces an array Z where Z[i] is the length of the longest prefix-substrings
//(which means that the substring is also a prefix of S) starting from i. O(n) to init,O(1) to query
void getz()
{
    int L=0, R=0;
    for (int i=1;i<n;i++)
    {
        if (i > R)
        {
            L=R=i;
            while (R<n && s[R-L]==s[R]) R++;
            z[i]=R-L;
            R--;
        }
        else
        {
            int k=i-L;
            if (z[k]<R-i+1) z[i]=z[k];
            else
            {
                L=i;
                while (R<n && s[R-L] == s[R]) R++;
                z[i]=R-L;
                R--;
            }
        }
    }
}
// Rabin-Karp
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}