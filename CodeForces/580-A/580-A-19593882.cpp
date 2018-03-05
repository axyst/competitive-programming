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
using namespace std;
int main()
{
//freopen("test.txt","r",stdin);
    int n,ans=1,a,now=0,bef=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a>=bef) now++;
        else now=1;
        bef=a;
        ans=max(ans,now);
    }
    printf("%d\n",ans);
return 0;
}