#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool check(char str[])//美丽为1，否则为0
{
    int num=0;
    int l=strlen(str);
    if(l==1) return 1;
    for(int i=1;i<l;i++) if(str[i]!='0') return 0;
    return 1;
}
char tem2[100050];
int main()
{
    int t=0;
    int nobeau=0;
    int cnt=0;
    scanf("%d",&t);
    if(t==1)
    {
        scanf("%s",&tem2);
        printf("%s\n",tem2);
        return 0;
    }
    while(t--)
    {
        int flag=0;
        char tem[100050];
        scanf("%s",&tem);
        int len=strlen(tem);
        if(tem[0]=='0') {printf("0\n");return 0;}
        if(tem[0]=='1'&&check(tem)) {cnt+=(len-1);continue;}
        for(int j=0;j<len;j++) tem2[j]=tem[j];
        nobeau++;
    }
        if(nobeau>0) printf("%s",tem2);
        else printf("1");
        for(int i=0;i<cnt;i++) printf("0");
        printf("\n");
    return 0;
}
