#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define rep(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
const int MAXN=100005;
int from[MAXN],to[MAXN];
int father[MAXN];
int Find(int x)
{
    if(x==father[x]) return x;
    return father[x]=Find(father[x]);
}
int main()
{
    //freopen("test.txt","r",stdin);
    int a,b;
    int n=0,m=0,cnt=0,ans=0;
    while(scanf("%d%d",&a,&b)&&(a!=-1&&b!=-1))
    {
        father[a]=a,father[b]=b;
        if(a&&b)
        {
            from[++m]=a;to[m]=b;
            continue;
        }
        rep(i,MAXN) if(father[i]==i)n++;
        rep(i,m)
        {
            int ff=Find(from[i]),ft=Find(to[i]);
            if(ff==ft) ans=1;
            else father[ff]=ft,cnt++;
        }
        if(!ans&&(cnt==n-1||n==0)) printf("Yes\n");
        else printf("No\n");
        memset(father,0,sizeof(father));
        n=0,m=0,cnt=0,ans=0;
    }
    return 0;
}