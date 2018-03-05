#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct tele
{
    int s;
    int e;
}tv[200];
bool cmp(tele a,tele b)
{
    if(a.e!=b.e) return a.e<b.e;
}
int main()
{
    int n;
    while (scanf("%d",&n)){
            int ans=0,now=0;
    if(n==0) return 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&tv[i].s,&tv[i].e);
    }
    sort(tv,tv+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(tv[i].s>=now) {now=tv[i].e;ans++;}
    }
    printf("%d\n",ans);
    }
    return 0;
}