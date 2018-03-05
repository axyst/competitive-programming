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
bool isprime(int a)
{
    if(a<=1) return 0;
    if(a==2||a==3) return 1;
    for(int i=3;i<=sqrt(a);i+=2)
        if(a%i==0) return 0;
    return 1;
}
int main()
{
//freopen("test.txt","r",stdin);
    int n,a,b,c;
    scanf("%d",&n);
    if(isprime(n)) printf("1\n%d\n",n);
    else if(isprime(n-2)) printf("2\n2 %d\n",n-2);
    else if(isprime(n-4)) printf("3\n2 2 %d\n",n-4);
    else
    {
        for(int i=n-6;i>3;i-=2)
            if(isprime(i))
                for(int j=n-i-3;j>3;j-=2)
                    if(isprime(j))
                        for(int k=n-i-j;j>3;j-=2)
                            if(isprime(k))
                                {
                                    a=i,b=j,c=k;
                                    goto l1;
                                }
        l1:printf("3\n%d %d %d\n",a,b,c);
    }
    return 0;
}