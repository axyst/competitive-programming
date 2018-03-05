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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=1e5+5;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
int fil[55][55];
int n;
void dfs(int row,int col,int cur)
{
    fil[row][col]=cur;
    int nr,nc;
    if(row<=1) nr=n;
    else nr=row-1;
    if(col>=n) nc=1;
    else nc=col+1;
    if(!fil[nr][nc]) dfs(nr,nc,cur+1);
    else
    {
        if(row>=n) nr=1;
        else nr=row+1;
        if(!fil[nr][col]) dfs(nr,col,cur+1);
    }
}
int main()
{
    scanf("%d",&n);
    memset(fil,0,sizeof(fil));
    dfs(1,n/2+1,1);
    rel(i,n)
    {
        rel(j,n) printf("%d ",fil[i][j]);
        printf("\n");
    }
    return 0;
}