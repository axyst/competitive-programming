#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100000+5;
char str[maxn];
int a[maxn];
int mk[maxn];
int main()
{
    scanf("%s",str);int len=strlen(str);
    for(int i=0;i<len;i++) a[i]=str[i]-'0';
    int tot=0;int zero=0;int one=0;int two=0;int flag=0;
    for(int i=0;i<len;i++)
    {
        tot=(tot+a[i])%3;
        if(!a[i]) zero++;
        else if(a[i]%3==1) one++;
        else if(a[i]%3==2) two++;
    }
    if(tot==1)
    {
        if(one&&!(one==1&&two>1&&a[1]==0&&a[0]%3==1))
        {
            flag=1;
            for(int i=len-1;i>=0;i--)
            if(flag&&a[i]%3==1)
            {
                mk[i]=1;
                flag--;
            }
        }
        else if(two>1)
        {
            flag=2;
            for(int i=len-1;i>=0;i--)
            if(flag&&a[i]%3==2)
            {
                mk[i]=1;
                flag--;
            }
        }
    }
    else if(tot==2)
    {
        if(two&&!(two==1&&one>1&&a[1]==0&&a[0]%3==2))
        {
            flag=1;
            for(int i=len-1;i>=0;i--)
            if(flag&&a[i]%3==2)
            {
                mk[i]=1;
                flag--;
            }
        }
        else if(one>1)
        {
            flag=2;
            for(int i=len-1;i>=0;i--)
            if(flag&&a[i]%3==1)
            {
                mk[i]=1;
                flag--;
            }
        }
    }
    int cnt=0;
    for(;(a[cnt]==0||mk[cnt]!=0)&&cnt<len;) cnt++;
    if(cnt==len&&!zero) printf("-1\n");
    else if(cnt==len) printf("0\n");
    else for(int i=cnt;i<len;i++)
        if(!mk[i]) printf("%c",str[i]);
    return 0;
}
