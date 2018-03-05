#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int pic[55][55];
int vis[55];
char str[10];
int n;
void addedge(int from,int to)
{
    if(str[from]=='0'||str[to]=='0') return;
    int nf=(str[from]-'A')*2+(str[from+1]=='+'?1:0);
    int nt=(str[to]-'A')*2+(str[to+1]=='+'?1:0);
    pic[nf^1][nt]++;//nf^1(parity flip) connects nf,nf is with nt
}
int dfs(int cur)
{
    vis[cur]=1;
    for(int i=0;i<52;i++)
        if(pic[cur][i])
        {
            if(vis[i]==1) return 1;
            if(!vis[i]&&dfs(i)==1) return 1;
        }
    vis[cur]=-1;
    return 0;
}
bool hascycle()
{
    for(int i=0;i<52;i++)
        if(!vis[i]&&dfs(i)) return 1;
    return 0;
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(pic,0,sizeof(pic));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            for(int j=0;j<4;j++)
                for(int k=0;k<4;k++)
                if(j!=k) addedge(j*2,k*2);
        }
        if(hascycle()) printf("unbounded\n");
        else printf("bounded\n");
    }
    return 0;
}
