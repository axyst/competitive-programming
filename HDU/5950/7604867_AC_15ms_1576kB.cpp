#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long N=7;const long long MOD=2147493647;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
//http://blog.csdn.net/queuelovestack/article/details/52973038
typedef struct node
{
    LL m[N][N];
    void Init()
    {
        memset(m,0,sizeof(m));
        for(int i=0;i<N;i++)
            m[i][i]=1;
    }
}matrix;
matrix mul(matrix a,matrix b)//矩阵乘法
{
    matrix ans;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            ans.m[i][j]=0;
            for(int k=0;k<N;k++)
                ans.m[i][j]+=(a.m[i][k]*b.m[k][j])%MOD;
            ans.m[i][j]%=MOD;
        }
    return ans;
}
matrix pow(matrix a,int n)//求a^n
{
    matrix ans;
    ans.Init();
    while(n)
    {
        if(n%2)
            ans=mul(ans,a);
        n/=2;
        a=mul(a,a);
    }
    return ans;
}
int main()
{
    int t;
    matrix ans,base;
    scanf("%d",&t);
    LL n,a,b;
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&n,&a,&b);
        memset(ans.m,0,sizeof(ans.m));
        ans.m[0][0]=a%MOD;ans.m[1][0]=b%MOD;ans.m[2][0]=81;ans.m[3][0]=27;ans.m[4][0]=9;ans.m[5][0]=3;ans.m[6][0]=1;//n=1
        base.m[0][0]=0;base.m[0][1]=1;base.m[0][2]=0;base.m[0][3]=0;base.m[0][4]=0;base.m[0][5]=0;base.m[0][6]=0;
        base.m[1][0]=2;base.m[1][1]=1;base.m[1][2]=1;base.m[1][3]=0;base.m[1][4]=0;base.m[1][5]=0;base.m[1][6]=0;
        base.m[2][0]=0;base.m[2][1]=0;base.m[2][2]=1;base.m[2][3]=4;base.m[2][4]=6;base.m[2][5]=4;base.m[2][6]=1;
        base.m[3][0]=0;base.m[3][1]=0;base.m[3][2]=0;base.m[3][3]=1;base.m[3][4]=3;base.m[3][5]=3;base.m[3][6]=1;
        base.m[4][0]=0;base.m[4][1]=0;base.m[4][2]=0;base.m[4][3]=0;base.m[4][4]=1;base.m[4][5]=2;base.m[4][6]=1;
        base.m[5][0]=0;base.m[5][1]=0;base.m[5][2]=0;base.m[5][3]=0;base.m[5][4]=0;base.m[5][5]=1;base.m[5][6]=1;
        base.m[6][0]=0;base.m[6][1]=0;base.m[6][2]=0;base.m[6][3]=0;base.m[6][4]=0;base.m[6][5]=0;base.m[6][6]=1;
        ans=mul(pow(base,n-1),ans);
        LL out=ans.m[0][0];
        printf("%I64d\n",out);
    }
    return 0;
}
