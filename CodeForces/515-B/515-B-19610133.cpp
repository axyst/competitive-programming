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
bool boy[105];
bool girl[105];
int main()
{
//freopen("test.txt","r",stdin);
    memset(boy,0,sizeof(boy));
    memset(girl,0,sizeof(girl));
    int n,m,b,g,tem;
    scanf("%d%d%d",&n,&m,&b);
    for(int i=0;i<b;i++)
    {
        scanf("%d",&tem);
        boy[tem]=1;
    }
    scanf("%d",&g);
    for(int i=0;i<g;i++)
    {
        scanf("%d",&tem);
        girl[tem]=1;
    }
    for(int i=0;i<=10000;i++)
        if(boy[i%n]||girl[i%m]) boy[i%n]=1,girl[i%m]=1;
    int flag=0;
    for(int i=0;i<n;i++)
        if(!boy[i]){flag=1;break;}
    if(!flag)
        for(int i=0;i<m;i++)
            if(!girl[i]){flag=1;break;}
    if(!flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}