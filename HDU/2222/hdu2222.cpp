#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=500005;
const double eps=1e-6;
char str[maxn*2];
struct Trie
{
    int nxt[maxn][30],fail[maxn],las[maxn];
    int root,len;
    int newnode()
    {
        for(int i=0;i<26;i++) nxt[len][i]=-1;
        las[len++]=0;
        return len-1;
    }
    void init()
    {
        len=0;
        root=newnode();
    }
    void insert(char buf[])
    {
        int l=strlen(buf);
        int now=root;
        for(int i=0;i<l;i++)
        {
            if(nxt[now][buf[i]-'a']==-1)
                nxt[now][buf[i]-'a']=newnode();
            now=nxt[now][buf[i]-'a'];
        }
        las[now]++;
    }
    void build()
    {
        queue<int>q;
        fail[root]=root;
        for(int i=0;i<26;i++)
            if(nxt[root][i]==-1) nxt[root][i]=root;
        else
        {
            fail[nxt[root][i]]=root;
            q.push(nxt[root][i]);
        }
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=0;i<26;i++)
                if(nxt[now][i]==-1)
                nxt[now][i]=nxt[fail[now]][i];
            else
            {
                fail[nxt[now][i]]=nxt[fail[now]][i];
                q.push(nxt[now][i]);
            }
        }
    }
    int query(char buf[])
    {
        int l=strlen(buf);
        int now=root;int ret=0;
        for(int i=0;i<l;i++)
        {
            now=nxt[now][buf[i]-'a'];
            int tmp=now;
            while(tmp!=root)
            {
                ret+=las[tmp];
                las[tmp]=0;
                tmp=fail[tmp];
            }
        }
        return ret;
    }
};
Trie ac;
int main()
{
    ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        ac.init();
        for(int i=0;i<n;i++)
        {
            cin>>str;
            ac.insert(str);
        }
        ac.build();
        cin>>str;
        cout<<ac.query(str)<<endl;
    }
}
