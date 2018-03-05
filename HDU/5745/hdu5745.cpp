#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
char s[maxn];
char p[5005];
bitset<maxn>dp[2][3];//两个串，三个状态
bitset<maxn>alp[30];
//dp[i][j][1] = ((dp[i-1][j-1][1] || dp[i-1][j-1][0]) && s[i] == p[j])
//如果两个数组之间需要进行位操作，用bitset替代可以实现常数优化
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n,m;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s%s",s,p);
        for(int i=0;i<26;i++) alp[i].reset();
        for(int i=0;i<2;i++) for(int j=0;j<3;j++) dp[i][j].reset();
        for(int i=0;i<n;i++) alp[s[i]-'a'][i]=1;//[s中当前标号对应的字母][标号]
        dp[0][1]=alp[p[0]-'a'];
        if(m>1) dp[0][2]=alp[p[1]-'a'];
        int cur=0;
        for(int j=1;j<m;j++)
        {
            cur^=1;
            dp[cur][0]=(dp[cur^1][2]<<1)&alp[p[j-1]-'a'];
            dp[cur][1]=((dp[cur^1][0]|dp[cur^1][1])<<1)&alp[p[j]-'a'];
            if(j<m-1) dp[cur][2]=((dp[cur^1][0]|dp[cur^1][1])<<1)&alp[p[j+1]-'a'];
        }
        for(int i=0;i<n;i++)
            if(dp[cur][0][i+m-1]||dp[cur][1][i+m-1]) printf("1");
            else printf("0");
        printf("\n");
    }
    return 0;
}
