#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
//#include<set>
using namespace std;
int cnt[10];
int main()
{
    long long q;
    while(scanf("%I64d",&q)!=EOF)
    {
    memset(cnt,0,sizeof(cnt));
    if(q==0){printf("10\n");continue;}
    if(q==1){printf("1\n");continue;}
    int len=0;
    for(int i=9;i>=2;i--)
    {
        while(q%i==0)
        {
            cnt[i]++;
            len++;
            q/=i;
        }
    }
    if(q>=10){printf("-1\n");continue;}
    //for(int i=2;i<=9;i++) printf("%d %d\n",i,cnt[i]);
    if(len==0) {printf("-1\n");continue;}
    int now=2;
    while(1)
    {
        while(cnt[now]>0)
        {
            printf("%d",now);
            cnt[now]--;
            len--;
        }
        now++;
        if(now>9) break;
        if(len<=0) break;
    }
    printf("\n");
    }
    return 0;
}
