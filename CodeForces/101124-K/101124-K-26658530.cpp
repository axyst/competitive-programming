#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

string s1,s2;

int Trans_second()
{
    int sums;
    int h=((s1[0]-'0')*10+s1[1]-'0')*3600;
    int m=((s1[3]-'0')*10+s1[4]-'0')*60;
    int s=(s1[6]-'0')*10+s1[7]-'0';
    return sums=h+m+s;
}

int Trans_speed()
{
    int sp=0;
    for(int i=9;i<s1.length();i++)
    {
        sp=sp*10+(s1[i]-'0');
        //printf("sp=%d\n",sp);
    }
    return sp;
}

int main()
{
    double ans=0;
    int last_sec=0;
    int last_speed=0;
    while(getline(cin,s1))
    {
        //cout<<s1<<endl;
        int sec=Trans_second();

        if(s1.length()>8)
        {
            int t=(sec-last_sec);
            double sp=(double)last_speed/3.6;
            ans=ans+sp*t;
            last_speed=Trans_speed();
            //printf("last_speed=%d\n",last_speed);
        }
        else
        {

            int t=(sec-last_sec);
            //printf("sec=%d last_sec=%d t=%d\n",sec,last_sec,t);
            double sp=(double)last_speed/3.6;
            //printf("sp=%lf\n",sp);
            ans=ans+sp*t;
            for(int i=0;i<8;i++)
                printf("%c",s1[i]);
            printf(" %.2lf km\n",(ans/1000));
        }

        last_sec=sec;
    }
    return 0;
}