#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
char str[1005];
char rev[1005];
int d[1005][1005];
int main()
{
    //freopen("test.txt","r",stdin);
    while(~scanf("%s",str+1))
    {
        memset(d,0,sizeof(d));
        int len=strlen(str+1);
        for(int i=1;i<=len;i++)
            rev[len-i+1]=str[i];
        for(int i=1;i<=len;i++)
            for(int j=1;j<=len;j++)
        {
            if(str[i]==rev[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
        printf("%d\n",len-d[len][len]);

    }
    return 0;
}
