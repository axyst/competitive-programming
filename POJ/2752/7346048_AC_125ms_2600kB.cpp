#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
typedef long long LL;
using namespace std;
const int MAXN=400000+15;
int next[MAXN];
int ans[MAXN];
char str[MAXN];
int main()
{
    while(scanf("%s",str+1)!=EOF)
    {
        int len=strlen(str+1);
        int j=0;
        for(int i=2;i<=len;i++)
        {
            while(j>0&&str[j+1]!=str[i]) j=next[j];
            if(str[j+1]==str[i]) j++;
            next[i]=j;
        }
        //for(int i=0;i<len;i++) printf("%d ",next[i]);
        int tmp=next[len];
        j=0;
        if(tmp!=0) ans[j++]=tmp;
        for(int i=next[tmp];i>0;i=next[i]) ans[j++]=i;
        for(int i=j-1;i>=0;i--) printf("%d ",ans[i]);
        printf("%d\n",len);
    }
    return 0;
}