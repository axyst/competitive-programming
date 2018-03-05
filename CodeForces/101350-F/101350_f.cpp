#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
struct node
{
    int l;
    int r;
    int id;
}nds[maxn],psp[maxn];
bool cmp1(node a,node b){return a.l<b.l;}
bool cmp2(node a,node b){return a.r<b.r;}
int no[maxn];int amo[maxn];set<int>s;
int main()
{
//#define LOCAL
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);
    while(t--)
    {
        s.clear();
        memset(amo,0,sizeof(amo));
        int n,m,ta,tb,tc;scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&ta,&tb,&tc);
            no[i]=tb;
            nds[i].l=ta-tc;nds[i].r=ta+tc;nds[i].id=i;
            psp[i].l=ta-tc;psp[i].r=ta+tc;psp[i].id=i;
        }
        sort(nds+1,nds+1+m,cmp1);
        sort(psp+1,psp+1+m,cmp2);
        int in=1;int out=1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            while(in<=m&&nds[in].l<=i)
            {
                int id=nds[in].id;
                amo[no[id]]++;
                s.insert(id);
                in++;
            }
            while(out<=m&&psp[out].r<i)
            {
                int id=psp[out].id;
                amo[no[id]]--;
                s.erase(id);
                out++;
            }
            if(s.empty()) ans++;
            else
            {
                set<int>::iterator it=s.end();it--;
                if(amo[no[*it]]>1) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}