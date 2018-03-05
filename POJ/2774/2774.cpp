#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#define LL long long
using namespace std;
#define ull unsigned long long
const ull B = 1e8+37;    //hash
const int MAXN = 100000+5;
char base[MAXN],check[MAXN],tmp[MAXN];
ull bhash[MAXN],power[MAXN];

int OK(int n,int m,int len)
{
  int pos=m-len+1;
  ull chash=0,tem=0;
  for(int i=0;i<len;i++)
    tem=tem*B+base[i];
  bhash[0]=tem;
  for(int i=0;i+len<=n;i++)
    bhash[i+1]=bhash[i]*B+base[i+len]-base[i]*power[len];
  sort(bhash,bhash+n-len+1);
  for(int i=0;i<len;i++)
    chash=chash*B+check[i];
  for(int k=0;k<pos;k++)
  {
    if(binary_search(bhash,bhash+n-len+1,chash))
        return 1;
    chash=chash*B+check[k+len]-check[k]*power[len];
  }
  return 0;
}

int solve()
{
  int n=strlen(base),m=strlen(check);
  if(n<m)
  {
    swap(n,m);
    strcpy(tmp,base);
    strcpy(base,check);
    strcpy(check,tmp);
  }
  int l=0,r=m,mid;
  while(l<r)
  {
    mid=l+(r-l+1)/2;
    if(OK(n,m,mid))l=mid;
    else r=mid-1;
  }
  return l;
}

int main()
{
  //freopen("test.txt","r",stdin);
  power[0]=1;
  for(int i=1;i<MAXN;i++)
    power[i]=power[i-1]*B;//hash power
  while(scanf("%s%s",base,check)!=EOF)
  {
    printf("%d\n",solve());
  }
  return 0;
}