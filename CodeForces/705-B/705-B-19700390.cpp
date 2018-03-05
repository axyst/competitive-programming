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
const int MAXN=1e6+5;
int a[MAXN];
using namespace std;
int main()
{
//freopen("test.txt","r",stdin);
    int n,now=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(now==1)
        {
            if(a[i]%2==1)
            {
                printf("2\n");
                now=1;
            }
            if(a[i]%2==0)
            {
                printf("1\n");
                now=2;
            }
            continue;
        }
        if(now==2)
        {
            if(a[i]%2==1)
            {
                printf("1\n");
                now=2;
            }
            if(a[i]%2==0)
            {
                printf("2\n");
                now=1;
            }
        }
    }
}