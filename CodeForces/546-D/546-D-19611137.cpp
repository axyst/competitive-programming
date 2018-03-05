#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#define LL long long
using namespace std;
const int MAXN=5000001;
bool vis[MAXN];
LL sum[MAXN];
void Prime()
{
    memset(vis,0,sizeof(vis));
    memset(sum,0,sizeof(sum));
    vis[1]=1;
    for(int i=2;i<MAXN;i++)
    {
        if(!vis[i])
            for(int j=i;j<MAXN;j+=i)
            {
                int tmp=j;
                while(tmp%i==0)
                {
                    sum[j]++;
                    tmp/=i;
                }
                vis[j]=1;
            }
    }
    for(int i=2;i<MAXN;i++) sum[i]+=sum[i-1];
}
int main()
{
    Prime();
//freopen("test.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL a,b;
        scanf("%I64d%I64d",&a,&b);
        printf("%I64d\n",sum[a]-sum[b]);
    }
    return 0;
}