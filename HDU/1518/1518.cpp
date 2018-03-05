#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
typedef long long LL;
using namespace std;
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
const long long MAXN=10000+15;
int a[MAXN];
bool vis[MAXN];
bool flag;
int sum;int n;
void dfs(int cur,int dep,int len)
{
    if(dep==5)
    {
        flag=1;
        return;
    }
    if(len==sum)
    {
        dfs(0,dep+1,0);
        if(flag) return;
    }
    for(int i=cur;i<n;i++)
    {
        if(!vis[i]&&len+a[i]<=sum)
        {
            vis[i]=1;
            dfs(i+1,dep,len+a[i]);
            if(flag) return;
            vis[i]=0;
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        rep(i,n)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%4)
        {
            l1:printf("no\n");
            continue;
        }
        sum/=4;
        for(int i=0;i<n;i++) if(a[i]>sum) goto l1;
        memset(vis,0,sizeof(vis));
        flag=0;
        dfs(0,1,0);
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}