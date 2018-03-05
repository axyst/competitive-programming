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
int p,q;
const int MAXN=1200000;
int pal[MAXN];
int pri[MAXN];
char tem1[100];
void Prime()
{
    pri[1]=0;
    for(int i=2;i<MAXN;i++)
    {
        if(!pri[i])
        {
            for(int j=2;j*i<MAXN;j++) pri[i*j]=1;
            pri[i]=pri[i-1]+1;
        }
        else pri[i]=pri[i-1];
    }
}
void Palind()
{
    pal[0]=0;
    for(int i=1;i<MAXN;i++)
    {
        int flag=1;
        int tem=i,s=0;
        while(tem)
        {
            s*=10;
            s+=tem%10;
            tem/=10;
        }
        if(s!=i) flag=0;
        if(flag) pal[i]=pal[i-1]+1;
        else pal[i]=pal[i-1];
    }
}
int main()
{
//freopen("test.txt","r",stdin);
    Prime();
    Palind();
    scanf("%d%d",&p,&q);
    int ans=0;
    for(int i=1;i<MAXN;i++)
    {
        if(q*pri[i]<=p*pal[i]) ans=i;
    }
    if(ans==0) printf("Palindromic tree is better than splay tree\n");
    else printf("%d\n",ans);
    return 0;
}