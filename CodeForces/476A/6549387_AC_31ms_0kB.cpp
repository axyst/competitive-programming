#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(m>n){printf("-1\n");return 0;}
    if(m==n){printf("%d\n",m);return 0;}
    for(int i=1;m*i<=n;i++)
    {
        if(m*i<=n&&m*i*2>=n)
        {
            printf("%d\n",m*i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
