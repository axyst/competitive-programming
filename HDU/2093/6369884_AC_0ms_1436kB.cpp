#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct student
{
    char na[15];
    int score=0;
    int num=0;
}stu[1010],tem;
int main()
{
int n,m,cnt=0;
scanf("%d%d",&n,&m);
while(scanf("%s",stu[cnt].na)!=EOF)
//while(scanf("%s",stu[++cnt].na)&&cnt<6)
{
    for(int i=0;i<n;i++)
    {
        int ti,fa=0;
        scanf("%d(%d)",&ti,&fa);
        stu[cnt].score+=fa*m;
        if(ti>0) {stu[cnt].score+=ti;stu[cnt].num++;}
    }
    cnt++;
}
for(int i=0;i<cnt-1;i++)
{
    for(int j=0;j<cnt-1-i;j++)
    {
        if(stu[j].num<stu[j+1].num)
        {
            tem=stu[j];
            stu[j]=stu[j+1];
            stu[j+1]=tem;
        }
        else if(stu[j].num==stu[j+1].num&&stu[j].score>stu[j+1].score)
        {
            tem=stu[j];
            stu[j]=stu[j+1];
            stu[j+1]=tem;
        }
        else if(stu[j].num==stu[j+1].num&&stu[j].score==stu[j+1].score&&strcmp(stu[j].na,stu[j+1].na)>0)
        {
            tem=stu[j];
            stu[j]=stu[j+1];
            stu[j+1]=tem;
        }
    }
}
for(int i=0;i<cnt;i++)
{
    printf("%-10s",stu[i].na);
    printf(" %2d",stu[i].num);
    printf(" %4d\n",stu[i].score);
}
}