#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char x[105];
char y[105];
char z[105];
int main()
{
    scanf("%s",x);
    scanf("%s",y);
    int len=strlen(y);
    bool flag=1;
    for(int i=0;i<len;i++)
    {
        if(x[i]>=y[i]) z[i]=y[i];
        else if(x[i]<y[i])
        {
            flag=0;
            break;
        }
    }
    if(flag) for(int i=0;i<len;i++) printf("%c",z[i]);
    else printf("-1\n");
    return 0;
}