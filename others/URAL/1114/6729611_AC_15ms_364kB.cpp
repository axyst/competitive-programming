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
/*
设使用i个红球，j个蓝球
ans=(c n,1 + c n+1,2 +...+ c n+i-1,i)*(c n,1 + c n+1,2 +...+ c n+j-1,j)
*/
int main()
{
//freopen("test.txt","r",stdin);
    int n,a,b,c;
    scanf("%d%d%d",&n,&a,&b);
    c=max(a,b);
    n--;
    unsigned long long ans=1,tmp=1,sum=1;
    for(int i=1;i<=c;i++)
    {
        tmp=tmp*(n+i)/i;
        sum+=tmp;
        if(i==a) ans*=sum;
        if(i==b) ans*=sum;
    }
    cout<<ans<<endl;
return 0;
}
