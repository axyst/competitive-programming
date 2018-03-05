/*
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int in[200000];
int main()
{
    int n,m,q,out;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    sort(in,in+n);
    while(m--)
    {
        scanf("%d",&q);
        if(in[n-1]<=q){printf("%d\n",n);continue;}
        else out=upper_bound(in,in+n,q)-in;
        printf("%d\n",out);
    }
}
*/
#include <stdio.h>
#include <algorithm>
const int maxn = 500005;

using namespace std;

int s[maxn];
int n;

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &s[i]);
        }
        sort(s+1, s+n+1);
        int j = n/2 + 1;
        int ans = 0;
        for (int i = 1; i <= n>>1 && j <= n;)
        {
            if (s[j] >= 2*s[i])
            {
                ans++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        printf("%d\n", n-ans);
    }
    return 0;
}