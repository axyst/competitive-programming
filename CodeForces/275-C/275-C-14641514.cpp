#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
long long a[100099];
set<long long> save;
int main()
{
    int n,k;
    long long ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(save.count(a[i])==0)
        {
        ans++;
        save.insert(a[i]*k);
        }
    }
    printf("%I64d\n",ans);
}