#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
typedef long long LL;
using namespace std;
const int MAXN=200001;
const int MOD=1e9+7;
int p[MAXN],a[MAXN],d[MAXN],vis[MAXN];
int sum=0,cnt=0;
LL ans=1LL,num=0LL;
void dfs(int cur,int val)
{
    vis[val]=cnt;
    d[val]=cur;
    if(vis[a[val]]&&vis[a[val]]==cnt)
    {
        sum=(cur-d[a[val]]+1);
        num+=sum;
        ans=(ans%MOD*(p[sum]-2)%MOD)%MOD;
    }
    else if(!vis[a[val]]) dfs(cur+1,a[val]);
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<MAXN;i++) p[i]=(p[i-1]%MOD*2)%MOD;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            cnt++;
            dfs(0,i);
        }
    ans=(ans%MOD*p[n-num]%MOD)%MOD;
    printf("%I64d\n",ans);
}