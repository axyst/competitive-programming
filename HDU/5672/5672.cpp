#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e6+15;
char str[maxn];
int counts[50];
int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        memset(counts,0,sizeof(counts));
        scanf("%s",str);
        scanf("%d",&k);
        int len=strlen(str);
        int l=0,r=0;
        int cnt=0;LL ans=0;
        while(l<=r&&l<len)
        {
            while(cnt<k&&r<len)
            {
                counts[str[r]-'a']++;
                if(counts[str[r]-'a']==1) cnt++;
                r++;
            }
            if(cnt==k)ans+=(len-r+1);
            if(counts[str[l]-'a']==1) cnt--;
            counts[str[l]-'a']--;
            l++;
        }
        printf("%I64d\n",ans);
    }
}