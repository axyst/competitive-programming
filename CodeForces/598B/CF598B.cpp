#include<bits/stdc++.h>
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
char str[maxn];
char trans[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    scanf("%s",str);
    int t;si(t);
    while(t--)
    {
        int a,b,c;
        si(a);si(b);si(c);
        for(int i=b-1;i>=a-1;i--)
        {
            int cur=a-1+((i+c-a+1)%(b-a+1));
            trans[cur]=str[i];
        }
        for(int i=a-1;i<=b-1;i++)
            str[i]=trans[i];
    }
    printf("%s\n",str);
    return 0;
}