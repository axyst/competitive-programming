#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char str[105];
char tmp[105];
int main()
{
    int ans=0;
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int cnt=0;
        for(int j=0;j<len;j++) tmp[j]=str[j];
        if(str[i]=='V') tmp[i]='K';
        else tmp[i]='V';
        for(int j=0;j<len;j++)
        {
            if(tmp[j]=='V'&&tmp[j+1]=='K'&&j+1<len)
            {
                cnt++;
                j++;
            }
        }
        ans=max(ans,cnt);
    }
    int cnt=0;
    for(int j=0;j<len;j++)
    {
        if(str[j]=='V'&&str[j+1]=='K'&&j+1<len)
        {
            cnt++;
            j++;
        }
    }
    ans=max(ans,cnt);
    cout<<ans<<endl;
    return 0;
}