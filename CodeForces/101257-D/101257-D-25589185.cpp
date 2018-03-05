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
const int MAXN=1e5+5;const long long MOD=10007;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int main()
{
  LL n,x,y;
  scanf("%I64d%I64d%I64d",&n,&x,&y);
  long long  l=0;long long r=INFL;
  while (r-l>1)
  {
    long long mid=(l+r)/2;
    if (mid/x+mid/y>=n) r=mid;
    else l=mid;
  }
  printf("%I64d\n",r);
}