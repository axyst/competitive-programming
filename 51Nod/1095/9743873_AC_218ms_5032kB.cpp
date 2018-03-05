#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=10005;
string str[maxn];
string tmp;
map<string,int>mp;
map<string,int>vis;
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q;
    while(scanf("%d",&n)==1)
    {
        mp.clear();
        vis.clear();
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
            if(vis[str[i]]) continue;
            vis[str[i]]=1;
            sort(str[i].begin(),str[i].end());
            mp[str[i]]++;
        }
        scanf("%d",&q);
        while(q--)
        {
            int ans=0;
            cin>>tmp;
            if(vis[tmp]) ans--;
            sort(tmp.begin(),tmp.end());
            ans+=mp[tmp];
            printf("%d\n",ans);
        }
    }
    return 0;
}
