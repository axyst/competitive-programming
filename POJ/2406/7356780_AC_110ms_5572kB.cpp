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
const int MAXN=100000005;
int next[MAXN];
char str[MAXN];
int main()
{
    while(scanf("%s",str+1)!=EOF)
    {
        if(str[1]=='.') return 0;
        int len=strlen(str+1);
        int j=0;
        for(int i=2;i<=len;i++)
        {
            while(j>0&&str[j+1]!=str[i]) j=next[j];
            if(str[j+1]==str[i]) j++;
            next[i]=j;
        }
        //for(int i=0;i<len;i++) printf("%d ",next[i]);
        if(len%(len-next[len])==0) printf("%d\n",len/(len-next[len]));
        else printf("1\n");
    }
    return 0;
}
