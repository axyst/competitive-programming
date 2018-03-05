#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
const int MAXN=305;bool vis[MAXN];
int p[MAXN],r[MAXN];
char a[MAXN][MAXN];
int n;
void look(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    rep(i,n) if(a[x][i]=='1') look(i);//mark possible change
}
int main()
{
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    rep(i,n) scanf("%d",&p[i]);
    rep(i,n) scanf("%s",a[i]);
    rep(i,n) if(!vis[i])
    {
        look(i);
        int cnt=0;
        rep(j,n) if(vis[j]) r[cnt++]=p[j];
        sort(r,r+cnt);//get better permutation
        cnt=0;
        rep(j,n) if(vis[j]) p[j]=r[cnt++];
        memset(vis,0,sizeof(vis));
    }
    rep(i,n) printf("%d ",p[i]);
    return 0;
}