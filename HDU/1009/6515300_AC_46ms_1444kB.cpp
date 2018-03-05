#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct
{
    int j;
    int f;
    double va;
}node;
bool cmp(node a, node b)
{
    if(a.va > b.va)
        return true;
    return false;
}
node a[1050];
bool cmp(node a, node b);
int main()
{
    int n,m;
    while(scanf("%d %d",&m,&n)&&(m!=-1||n!=-1))
    {
        double ans=0;
        if(!n)
        {
            printf("%.3f\n",ans);
            continue;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i].j,&a[i].f);
            if(!a[i].f)
            {
                ans+=a[i].j;
                a[i].j=0;
                continue;
            }
            a[i].va=a[i].j*1.0/a[i].f;
        }
        sort(a,a+n,cmp);
        for(int i=0;m>0&&i<n;i++)
        {
            if(m>=a[i].f)
            {
                m-=a[i].f;
                ans+=a[i].j;
            }
            else
            {
                ans+=a[i].va*m;
                break;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
