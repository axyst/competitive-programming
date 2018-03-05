#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
map<LL,int>vis;
int dfs(LL cur,int flag)
{
    if(vis[cur]) return vis[cur];
    if(cur>=n) return flag;
    for(LL i=2;i<=9;i++)
        if(dfs(i*cur,flag))
        {
            flag=!flag;
            break;
        }
    vis[cur]=flag;
    return flag;
}
int main()
{
    while(scanf("%I64d",&n)!=EOF)
    {
        vis.clear();
        if(n==1)
        {
            cout<<"Stan wins."<<endl;
            continue;
        }
        int flag=1;
        flag=dfs(1,1);
        if(flag==1)cout<<"Ollie wins."<<endl;
        else cout<<"Stan wins."<<endl;
    }
    return 0;
}