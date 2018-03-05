#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct tele
{
    int dps;
    int hp;
}tv[200];
bool cmp(tele a,tele b)
{
    return (double(a.dps)/double(a.hp))>(double(b.dps)/double(b.hp));
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0,time=0;
        for(int i=0;i<n;i++) scanf("%d%d",&tv[i].dps,&tv[i].hp);
        sort(tv,tv+n,cmp);
        for(int i=0;i<n;i++)
        {
            time+=tv[i].hp;
            ans+=tv[i].dps*time;
        }
        printf("%d\n",ans);
    }
}