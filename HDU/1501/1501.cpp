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
using namespace std;
/*
最优子结构分析：如果AB可以组成C，那么C最后一个字母e必定是 A 或 B 的最后一个字母。
C去除最后一位，问题就变成 A-1和B 或者 A和B-1 是否可以构成 C-1。
状态转移方程： 用dp[i][j] 表示 表示A前 i 位 和B 前j 位是否可以组成 C的前i+j位　　　　　　　　
　　　　　　　　dp[i][j]=(dp[i-1][j]&&a[i]==c[i+j])||(dp[i][j-1]&&b[j]==c[i+j])
*/
char a[205],b[205],c[410];
int dp[205][205];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int x=1;x<=n;x++)
    {
        memset(dp,0,sizeof(dp));
        a[0]='0';
        b[0]='0';
        c[0]='0';
        scanf("%s%s%s",a+1,b+1,c+1);
        int la=strlen(a)-1,lb=strlen(b)-1,lc=strlen(c);
        for(int i=1;i<=la;i++) if(a[i]==c[i]) dp[i][0]=1;
        for(int i=1;i<=lb;i++) if(b[i]==c[i]) dp[0][i]=1;
        for(int i=1;i<=la;i++)
            for(int j=1;j<=lb;j++)
                dp[i][j]=(dp[i-1][j]&&a[i]==c[i+j])||(dp[i][j-1]&&b[j]==c[i+j]);
        printf("Data set %d: ",x);
        if(dp[la][lb]==1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}