#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=10000+5;
int a[maxn];int s[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int n,k;
   while(scanf("%d%d",&n,&k)==2)
    {
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);s[i]=a[i]+s[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
                if(s[j]-s[i-1]==k)
            {
                printf("%d %d\n",i,j);
                return 0;
            }
        }
        printf("No Solution\n");
    }
    return 0;
}