#define LOCAL

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e7+5;
const int mod=1e9+7;
unsigned x,y,z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
unsigned a[maxn];
int b[105];int pos[105];
bool cmp(int x,int y){return b[x]<b[y];}
unsigned out[105];
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif
    int ks=1;int m,n;
    while(scanf("%d%d%u%u%u",&n,&m,&x,&y,&z)==5)
    {
        for(int i=0;i<n;i++) a[i]=rng61();
        for(int i=0;i<m;i++)
        {
            scanf("%d",b+i);
            pos[i]=i;
        }
        sort(pos,pos+m,cmp);
        pos[m]=m;b[m]=n;
        for(int i=m-1;i>=0;i--)
        {
            int pi=pos[i];int pi1=pos[i+1];
            if(b[pi]==b[pi1])
            {
                out[pi]=out[pi1];continue;
            }
            nth_element(a,a+b[pi],a+b[pi1]);//按第b[pi]大元素划分
            out[pi]=a[b[pi]];
        }
        printf("Case #%d:",ks++);
        for(int i=0;i<m;i++) printf(" %u",out[i]);
        printf("\n");
    }
    return 0;
}
