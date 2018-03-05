#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int pic[25][25];
bool nset[25];
int ans,n;
void dfs(int num,int add)
{
    int change=add;
    nset[num]=1;
    for(int i=0;i<n;i++)
    {
        if(!nset[i]) change+=pic[i][num];
        else change-=pic[i][num];
    }
    ans=max(ans,change);
    if(change>add)
    for(int i=num+1;i<n;i++)
    {
        dfs(i,change);
        nset[i]=0;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&pic[i][j]);
        memset(nset,0,sizeof(nset));
        ans=0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}