#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dir[4]={-1,1,-3,3};
int main()
{
    int t,ok=1;
    char str[10];
    scanf("%d",&t);
    scanf("%s",str);
        for(int i=0;i<4;i++)
        {
        int j;
        for(j=0;j<t;j++)
        {
            if(str[j]=='0'&&i!=2) break;
            if(str[j]=='0'&&i==2) continue;
            if(str[j]=='8'&&i==3) continue;
            if((str[j]=='1'||str[j]=='4'||str[j]=='7')&&i==0) break;
            if((str[j]=='3'||str[j]=='6'||str[j]=='9')&&i==1) break;
            int tmp=str[j]-'0'+dir[i];
            if(tmp<=0 || tmp>=10) break;
        }
        if(j==t) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
        return 0;

}