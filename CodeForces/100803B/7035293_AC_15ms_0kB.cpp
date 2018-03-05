#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
char in[500],op[100];
int num[100];
int main()
{
    int out,ans1=0,ans2=0,tem=1;
    int ncnt=0,ocnt=0;
    //freopen("test.txt","r",stdin);
    scanf("%s",in);
    scanf("%d",&out);
    int len=strlen(in);
    for(int i=0;i<len;i++)
    {
        if(in[i]>='0'&&in[i]<='9')
        {
            num[ncnt++]=in[i]-'0';
        }
        else
        {
            op[ocnt++]=in[i];
        }
    }
    ans2=num[0];
    for(int i=0;i<ocnt;i++)
    {
        if(op[i]=='*')
        {
            ans2*=num[i+1];
        }
        else
        {
            ans2+=num[i+1];
        }
    }
    for(int i=0;i<ocnt;i++)
    {
        if(op[i]=='*')
        {
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
        }
    }
    for(int i=0;i<len;i++) ans1+=num[i];
    //printf("%d %d\n",ans1,ans2);
    if(ans1==out&&ans2!=out) printf("M\n");
    else if(ans2==out&&ans1!=out) printf("L\n");
    else if(ans1==out&&ans2==ans1) printf("U\n");
    else printf("I\n");
}