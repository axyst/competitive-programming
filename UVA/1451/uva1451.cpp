#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
int a[maxn],s[maxn],p[maxn];
char str[maxn];
int comave(int i1,int j1,int i2,int j2)
{
    return (s[j1]-s[i1-1])*(j2-i2+1)-(s[j2]-s[i2-1])*(j1-i1+1);
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,n,l;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&l);s[0]=0;
        scanf("%s",str+1);
        for(int i=1;i<=n;i++)
        {
            a[i]=str[i]-'0';
            s[i]=a[i]+s[i-1];
        }
        int left=1,right=l;
        int i=0,j=0;
        for(int t=l;t<=n;t++)
        {
            while(j-i>1&&comave(p[j-2],t-l,p[j-1],t-l)>=0) j--;
            p[j++]=t-l+1;
            while(j-i>1&&comave(p[i],t,p[i+1],t)<=0) i++;
            int compare=comave(p[i],t,left,right);
            if(compare>0||compare==0&&t-p[i]<right-left)
            {
                left=p[i];
                right=t;
            }
        }
        printf("%d %d\n",left,right);
    }
    return 0;
}
