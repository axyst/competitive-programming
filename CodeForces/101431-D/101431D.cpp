#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=2020;
vector<int>g1[maxn],g2[maxn];
int main()
{
    //freopen("test.txt","r",stdin);
    int x,n;
    while(scanf("%d%d",&n,&x)==2)
    {
        if(n<x+1)
        {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int w=i%n+1;
            for(int j=1;j<=x;j++)
            {
                g1[i].push_back((i-1)*x+j);
                g2[w].push_back((i-1)*x+j);
                w=w%n+1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<g1[i].size();j++)
                printf("%d ",g1[i][j]);
            for(int j=0;j<g2[i].size();j++)
            {
                printf("%d ",g2[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}