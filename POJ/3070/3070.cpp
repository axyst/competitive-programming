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
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(LL (i)=0;(i)<(LL)(n);++(i))
#define rel(i,n) for(LL (i)=1;(i)<=(LL)(n);++(i))
#define rer(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))
#define reu(i,l,u) for(LL (i)=(LL)(l);(i)<(LL)(u);++(i))
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=1e6+5;const long long MOD=10000;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.14159265;
const double eps=1e-7;
#define N 2
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
matrix mul(matrix a,matrix b)
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
int mpow(matrix a,int n)
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
    return ans.m[0][1];
}
int main()
{
    matrix one;
    one.m[0][0]=one.m[0][1]=one.m[1][0]=1;
    one.m[1][1]=0;
    int n;
    while(scanf("%d",&n)&&n!=-1)
        printf("%d\n",mpow(one,n));
    return 0;
}