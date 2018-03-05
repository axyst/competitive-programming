#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=50005;
char op[maxn<<3];//题意是最多50000个结点，不是字符串最长50000！开太小会RE
int vis[maxn];int nc;
char *p;int ks;
struct nodes
{
    string s;//结点用string存可简化很多
    int ls,rs;int nhash;
    bool operator <(const nodes &rhs) const
    {
        if(nhash!=rhs.nhash) return nhash<rhs.nhash;
        if(ls!=rhs.ls) return ls<rhs.ls;
        return rs<rhs.rs;
}
}node[maxn];
map<nodes,int>ids;//快速查找结点
void print(int cur)
{
    if(vis[cur])//访问过，打印编号
    {
        printf("%d",cur+1);
        return;
    }
    vis[cur]=1;
    printf("%s",node[cur].s.c_str());//string转char
    if(node[cur].ls!=-1)//有子树
    {
        printf("(");
        print(node[cur].ls);
        printf(",");
        print(node[cur].rs);
        printf(")");
    }
}
int build_tree()
{
    int u=nc++;
    nodes &cur=node[u];
    cur.ls=-1;cur.rs=-1;cur.nhash=0;cur.s="";
    while(isalpha(*p))
    {
        cur.s.push_back(*p);
        cur.nhash=cur.nhash*27+*p-'a'+1;//这个hash函数选择得不好会被卡数据
        p++;
    }

    if(*p=='(')//有子树
    {
        //cout<<p<<endl;
        p++;
        cur.ls=build_tree();
        p++;
        cur.rs=build_tree();
        p++;
    }

    if(ids.count(cur)!=0)//旧结点
    {
        u--,nc--;
        return ids[cur];
    }
    return ids[cur]=u;//新增结点
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t;scanf("%d",&t);
    for(ks=1;ks<=t;ks++)
    {
        nc=0;ids.clear();memset(vis,0,sizeof(vis));
        scanf("%s",op);
        p=op;//存放当前打印位置的全局指针
        int u=build_tree();
        print(u);
        printf("\n");
    }
    return 0;
}