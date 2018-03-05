#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int a[110];
int b[110];
int visa[110];
int visb[110];
int main()
{
    memset(visa,0,sizeof(visa));
    memset(visb,0,sizeof(visb));
    int n,m,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    //while(1)
    //{
    //int out1=0,out2=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visa[i]&&!visb[j])
                //if(a[i]-b[j]<=1||b[j]-a[i]<=1)
                if(a[i]==b[j]||a[i]==b[j]-1||a[i]==b[j]+1)
                    {
                        ans++;
                        visa[i]=1;
                        visb[j]=1;
                        break;
                    }
    //for(int i=0;i<n;i++) if(visa[i]) {out1=1;break;}
    //for(int i=0;i<m;i++) if(visb[i]) {out2=1;break;}
    //if(!out1||!out2) break;
    //}
    printf("%d\n",ans);
    return 0;
}