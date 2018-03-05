#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int h[1000005];
int main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a);
        h[a]=1;
    }
    int des=1;
    for(int i=0;i<k;i++)
    {
        if(h[des]) break;
        scanf("%d%d",&b,&c);
        if(des==c) des=b;
        else if(des==b) des=c;
    }
    printf("%d\n",des);
    return 0;
}