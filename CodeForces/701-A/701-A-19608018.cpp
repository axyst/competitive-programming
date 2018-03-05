#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#define LL long long
using namespace std;
struct st
{
    int bef;
    int aft;
}card[105];
bool cmp(st a,st b)
{
    return a.aft<b.aft;
}
int main()
{
//freopen("test.txt","r",stdin);
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&card[i].aft);
        card[i].bef=i;
    }
    sort(card+1,card+1+n,cmp);
    //for(int i=1;i<=n;i++) printf("%d %d\n",card[i].bef,card[i].aft);
    for(int i=1;i<=n/2;i++) printf("%d %d\n",card[i].bef,card[n-i+1].bef);
    return 0;
}