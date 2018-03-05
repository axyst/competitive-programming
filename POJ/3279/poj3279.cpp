#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
typedef long long LL;
const int INF=0x3f3f3f3f;
int pic[20][20];
int fli[20][20];
int use[20][20];
int pri[20][20];
int m,n,ans,cnt;
void flip(int i,int j)
{
    //cout<<i<<' '<<j<<endl;
    cnt++;
    use[i][j]=1;
    fli[i][j]=!fli[i][j];
    fli[i-1][j]=!fli[i-1][j];
    fli[i+1][j]=!fli[i+1][j];
    fli[i][j-1]=!fli[i][j-1];
    fli[i][j+1]=!fli[i][j+1];
}
void solve(int u)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        fli[i][j]=pic[i][j];
    }
    memset(use,0,sizeof(use));
    cnt=0;
    for(int j=0;j<n;j++)
        if((u>>j)&1) flip(1,j+1);
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n;j++)
        if(fli[i-1][j]) flip(i,j);
    for(int j=1;j<=n;j++) if(fli[m][j]) return;
    if(ans>cnt)
    {
        ans=cnt;
        //cout<<cnt<<endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            pri[i][j]=use[i][j];
        }
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(scanf("%d%d",&m,&n)==2)
    {
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            scanf("%d",&pic[i][j]);
        ans=INF;
        int up=1<<n;
        for(int u=0;u<up;u++) solve(u);
        if(ans==INF) printf("IMPOSSIBLE\n");
        else
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d",pri[i][j]);
                if(j!=n) printf(" ");
            }
            printf("\n");
        }

    }
    return 0;
}