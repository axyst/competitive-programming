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
char str[10][130];
char tem[7][6];
char one[7][6]=
{
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.'
};
char two[7][6]=
{
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'x','x','x','x','x','.',
'x','.','.','.','.','.',
'x','.','.','.','.','.',
'x','x','x','x','x','.'
};
char three[7][6]=
{
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'x','x','x','x','x','.'
};
char four[7][6]=
{
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.'
};
char five[7][6]=
{
'x','x','x','x','x','.',
'x','.','.','.','.','.',
'x','.','.','.','.','.',
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'x','x','x','x','x','.'
};
char six[7][6]=
{
'x','x','x','x','x','.',
'x','.','.','.','.','.',
'x','.','.','.','.','.',
'x','x','x','x','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','x','x','x','x','.'
};
char seven[7][6]=
{
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.'
};
char eight[7][6]=
{
'x','x','x','x','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','x','x','x','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','x','x','x','x','.'
};
char nine[7][6]=
{
'x','x','x','x','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','x','x','x','x','.',
'.','.','.','.','x','.',
'.','.','.','.','x','.',
'x','x','x','x','x','.'
};
char zero[7][6]=
{
'x','x','x','x','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','.','.','.','x','.',
'x','x','x','x','x','.'
};
char add[7][6]=
{
'.','.','.','.','.',
'.','.','x','.','.',
'.','.','x','.','.',
'x','x','x','x','x',
'.','.','x','.','.',
'.','.','x','.','.',
'.','.','.','.','.'
};
int check(char a[7][6])
{
    if(a[0][4]=='.') return 10;
    else if(a[0][0]=='.') return 1;
    else if(a[0][3]=='.') return 4;
    else if(a[6][0]=='.'&&a[3][0]=='.') return 7;
    else if(a[2][0]=='x'&&a[2][4]=='.'&&a[5][0]=='x'&&a[5][4]=='x') return 6;
    else if(a[3][0]=='x'&&a[3][4]=='x'&&a[5][0]=='x'&&a[5][4]=='x'&&a[3][2]=='x') return 8;
    else if(a[3][0]=='x'&&a[3][4]=='x'&&a[5][0]=='x'&&a[5][4]=='x'&&a[3][2]=='.') return 0;
    else if(a[2][0]=='.'&&a[2][4]=='x'&&a[5][0]=='x'&&a[5][4]=='.') return 2;
    else if(a[2][0]=='.'&&a[2][4]=='x'&&a[5][0]=='.'&&a[5][4]=='x') return 3;
    else if(a[2][0]=='x'&&a[2][4]=='.'&&a[5][0]=='.'&&a[5][4]=='x') return 5;
    else if(a[2][0]=='x'&&a[4][4]=='x'&&a[5][0]=='.'&&a[5][4]=='x') return 9;

}
int out[50];
int main()
{
    //freopen("test5.txt","r",stdin);
    while(scanf("%s",str[0])!=EOF)
    {
        int len=strlen(str[0]);
        for(int i=1;i<7;i++) scanf("%s",&str[i]);
        LL first=0,second=0;
        int cnt=0,time=len/6+1;
        //for(int i=0;i<7;i++) printf("%s\n",str[i]);
        while(time--)
        {
            for(int i=0;i<7;i++)
            {
                for(int j=0;j<5;j++)
                {
                    tem[i][j]=str[i][j+cnt];
                    //printf("%c",tem[i][j]);
                }
                //printf("\n");
            }
            first*=10;
            int now=check(tem);
            if(now==10) break;
            first+=now;
            //printf("%d\n",first);
            cnt+=6;
        }
        cnt+=6;
        //printf("%d\n",cnt);
        time=len/6+1;
        int k=0;
        while(k+cnt<=len)
        {
            for(int i=0;i<7;i++)
            {
                for(k=0;k<5;k++)
                {
                    tem[i][k]=str[i][k+cnt];
                    //printf("%c",tem[i][j]);
                }
                //printf("\n");
            }
            second*=10;
            int now=check(tem);
            if(now==10) break;
            second+=now;
            //printf("%d\n",second);
            cnt+=6;
        }
        first/=10;
        //printf("%I64d %I64d\n",first,second);
        first+=second;
        //printf("%I64d\n",first);
        int number=0;
        while(first>0)
        {
            out[number++]=first%10;
            first/=10;
        }
        for(int last=0;last<7;last++)
        {
            for(int i=number-1;i>=0;i--)
            {
                int print=out[i];
                if(i!=0)
                {
                    if(print==1) for(int p=0;p<6;p++) printf("%c",one[last][p]);
                    if(print==2) for(int p=0;p<6;p++) printf("%c",two[last][p]);
                    if(print==3) for(int p=0;p<6;p++) printf("%c",three[last][p]);
                    if(print==4) for(int p=0;p<6;p++) printf("%c",four[last][p]);
                    if(print==5) for(int p=0;p<6;p++) printf("%c",five[last][p]);
                    if(print==6) for(int p=0;p<6;p++) printf("%c",six[last][p]);
                    if(print==7) for(int p=0;p<6;p++) printf("%c",seven[last][p]);
                    if(print==8) for(int p=0;p<6;p++) printf("%c",eight[last][p]);
                    if(print==9) for(int p=0;p<6;p++) printf("%c",nine[last][p]);
                    if(print==0) for(int p=0;p<6;p++) printf("%c",zero[last][p]);
                }
                else
                {
                    if(print==1) for(int p=0;p<5;p++) printf("%c",one[last][p]);
                    if(print==2) for(int p=0;p<5;p++) printf("%c",two[last][p]);
                    if(print==3) for(int p=0;p<5;p++) printf("%c",three[last][p]);
                    if(print==4) for(int p=0;p<5;p++) printf("%c",four[last][p]);
                    if(print==5) for(int p=0;p<5;p++) printf("%c",five[last][p]);
                    if(print==6) for(int p=0;p<5;p++) printf("%c",six[last][p]);
                    if(print==7) for(int p=0;p<5;p++) printf("%c",seven[last][p]);
                    if(print==8) for(int p=0;p<5;p++) printf("%c",eight[last][p]);
                    if(print==9) for(int p=0;p<5;p++) printf("%c",nine[last][p]);
                    if(print==0) for(int p=0;p<5;p++) printf("%c",zero[last][p]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
