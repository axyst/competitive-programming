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
using namespace std;
int a[55];
int main()
{
//freopen("test.txt","r",stdin);
int n,m,ans=2001;
scanf("%d%d",&n,&m);
for(int i=0;i<m;i++) scanf("%d",&a[i]);
sort(a,a+m);
//for(int i=0;i<m;i++) printf("%d\n",a[i]);
for(int i=0;i+n<=m;i++) ans=min(ans,a[i+n-1]-a[i]);
printf("%d\n",ans);
return 0;
}