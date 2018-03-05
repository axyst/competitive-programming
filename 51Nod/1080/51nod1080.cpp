#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=50000+5;
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int n;
   while(scanf("%d",&n)==1)
    {
        bool flag=0;
        int div=sqrt(n)+1;
        for(int i=0;i<=div;i++)
        {
            int j=sqrt(n-i*i);
            if(j*j+i*i==n&&i<=j)
            {
                printf("%d %d\n",i,j),flag=1;
            }
        }
        if(!flag) printf("No Solution\n");
    }
    return 0;
}