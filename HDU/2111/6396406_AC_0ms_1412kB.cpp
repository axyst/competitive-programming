#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct tele
{
    int pi;
    int mi;
    //int va;
}tv[200];
bool cmp(tele a,tele b)
{
    return a.pi>b.pi;
}
int main()
{
    int v,n;
    while (scanf("%d",&v)!=EOF)
    {
        if(v==0) return 0;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
        scanf("%d%d",&tv[i].pi,&tv[i].mi);
        //tv[i].va=tv[i].pi/tv[i].mi;
        }
        sort(tv,tv+n,cmp);
        for(int i=0;i<n&&v>0;i++)
        {
            if(v>=tv[i].mi)
            {
                v-=tv[i].mi;
                ans+=tv[i].mi*tv[i].pi;
            }
            else{
                    ans+=tv[i].pi*v;
                    v=0;
                }

        }
        printf("%d\n",ans);
    }
    return 0;
}