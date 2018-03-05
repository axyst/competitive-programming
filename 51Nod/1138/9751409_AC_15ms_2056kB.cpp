#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=100005;
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;//n=sum(x,y)=x+x+1+..+x+y-1=yx+y*(y-1)/2
    while(scanf("%d",&n)==1)//x=(sum-y*(y-1)/2)/y
    {
        int div=sqrt(2*n)+1;
        bool flag=0;
        for(int y=div;y>=2;y--)
        {
            int f=2*y;
            int a=2*n+y-y*y;//a:sum*2-y*(y-1)
            if(a%f==0&&a/f)
            {
                flag=1;
                printf("%d\n",a/f);//x
            }
        }
        if(!flag) printf("No Solution\n");
    }
    return 0;
}
