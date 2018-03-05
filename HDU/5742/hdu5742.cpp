#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
int gcd(int a,int b)
{
    while(b>0)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int a[105];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int t,n,m,t1,t2;scanf("%d",&t);
    while(t--)
    {
        memset(a,-1,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&t1,&t2);
            a[t1]=t2;
        }
        t1=0;
        for(int i=n;i>=3;i--)
        {
            if(a[i]==-1) a[i]=t1;
            t1=a[i];
        }
        if(a[1]==-1) a[1]=100;
        if(a[2]==-1) a[2]=a[1];
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];

        //cout<<a[1]+a[2]<<' '<<sum<<endl;
        int div=gcd(a[1]+a[2],sum);
        printf("%d/%d\n",(a[1]+a[2])/div,sum/div);
    }
    return 0;
}