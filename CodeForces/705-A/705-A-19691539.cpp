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
int main()
{
//freopen("test.txt","r",stdin);
    int t,n;
    scanf("%d",&n);
    if(n==1){printf("I hate it\n");return 0;}
    if(n%2==0)
    {
        for(int t=n;t>=1;t--)
        {
            if(t==1) printf("I love it\n");
            else if(t%2==0) printf("I hate that ");
            else if(t%2==1) printf("I love that ");
        }
    }
    if(n%2!=0)
    {
        for(int t=n;t>=1;t--)
        {
            if(t==1) printf("I hate it\n");
            else if(t%2==0) printf("I love that ");
            else if(t%2==1) printf("I hate that ");
        }
    }
    return 0;
}