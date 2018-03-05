#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
int n,m;
while(1)
{
    scanf("%d%d",&n,&m);
    if(n==0&&m==0) break;
    float root=n*n-4*m;
    int x=sqrt(root);
    if(root>=0&&root-x*x==0) printf("Yes\n");
    else printf("No\n");
}
return 0;
}