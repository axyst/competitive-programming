#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
char n[105];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",n)!=EOF)
    {
        int len=strlen(n);
        if(len>10)
        {
            printf("TAT\n");
            continue;
        }
        LL sum=0;int y;
        for(int i=0;i<len;i++)
        {
            sum+=(n[i]-'0');
            if(i!=len-1) sum*=10;
        }
        if(sum==0)
        {
            printf("TAT\n");
            continue;
        }
        if(1<=sum&&sum<=3) y=1;
        else if(4<=sum&&sum<=15) y=2;
        else if(16<=sum&&sum<=255) y=3;
        else if(256<=sum&&sum<=65535) y=4;
        else if(65536<=sum&&sum<=4294967295) y=5;
        else
        {
            printf("TAT\n");
            continue;
        }
        printf("%d\n",y);
    }
    return 0;
}
