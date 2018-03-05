#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100+5;
int num[maxn];
int in[maxn];
int main()
{
    int n,k,tmp;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) num[i]=i+1;
    int id=0;int len=n;
    while(k--)
    {
        scanf("%d",&tmp);
        id=(id+tmp)%len;
        printf("%d ",num[id]);
        for(int i=id;i<len;i++)
            num[i]=num[i+1];
        len--;
    }
    return 0;
}
