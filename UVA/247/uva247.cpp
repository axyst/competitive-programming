#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=30;const int INF=0x3f3f3f3f;int n,m;
int vis[maxn];int d[maxn][maxn];
vector<string>names;
map<string,int>ids;
void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=(d[i][j]||(d[i][k]&&d[k][j]));
}
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&d[x][i]&&d[i][x])
        {
            printf(", %s",names[i].c_str());
            dfs(i);
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    string tmp,pmt;int ks=0;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        if(++ks>1) printf("\n");
        printf("Calling circles for data set %d:\n",ks);
        memset(vis,0,sizeof(vis));memset(d,0,sizeof(d));
        ids.clear();names.clear();int no=0;
        for(int i=0;i<m;i++)
        {
            cin>>tmp>>pmt;int from,to;
            if(!ids.count(tmp))
            {
                from=no;names.push_back(tmp);
                ids.insert(pair<string,int>(tmp,no++));
            }
            else from=ids[tmp];
            if(!ids.count(pmt))
            {
                to=no;names.push_back(pmt);
                ids.insert(pair<string,int>(pmt,no++));
            }
            else to=ids[pmt];
            d[from][to]=1;
        }
        floyd();
        for(int i=0;i<n;i++)
        {
            if(!vis[i])//new cc
            {
                printf("%s",names[i].c_str());
                dfs(i);
                printf("\n");
            }
        }
    }
    return 0;
}
