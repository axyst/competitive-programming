#include<bits/stdc++.h>
#define rep(i,a) for(int i=0;i<a;i++)
#define rel(i,a) for(int i=1;i<=a;i++)
using namespace std;
typedef long long LL;
int s[5000];
//int s2[5000];
int main()
{
    int n,k,cnt=0;
    //int cnt2=0;
    scanf("%d%d",&n,&k);
    rep(i,n)
    {
        scanf("%d",&s[i]);
        //s2[i]=s[i];
    }
    for(int i=1;i<n;i++)
        if(s[i-1]<=k&&k-s[i-1]-s[i]>0)
        {
            cnt+=(k-s[i-1]-s[i]);
            s[i]=k-s[i-1];
        }
    //if(cnt<cnt2)
    //{
        printf("%d\n",cnt);
        rep(i,n) printf("%d ",s[i]);
    /*}
    else
    {
        printf("%d\n",cnt2);
        rep(i,n) printf("%d ",s2[i]);
    }*/
    return 0;
}