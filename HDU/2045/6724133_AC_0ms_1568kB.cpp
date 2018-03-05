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
long long a[100];
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    a[1]=3,a[2]=6,a[3]=6;
    for(int i=4;i<=50;i++) a[i]=a[i-1]+2*a[i-2];
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",a[n]);
    }
    return 0;
}