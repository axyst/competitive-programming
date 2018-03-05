#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100010;
int st[20][maxn];
map<int,LL>vis;
int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
void RMQ_init(int n)
{
    for(int i=1;i<=n;i++) scanf("%d",&st[0][i]);
    for(int i=1;i<18;i++)
        for(int j=1;j<=n;j++)
            if(j+(1<<i)-1>n) continue;
            else st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return gcd(st[k][L],st[k][R-(1<<k)+1]);
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,n;scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        scanf("%d",&n);
        RMQ_init(n);
        vis.clear();
        for(int i=1;i<=n;i++)
        {
            int cur=st[0][i],j=i;
            while(j<=n)
            {
                int Left=j,Right=n;
                while(Left<Right)
                {
                    int mid=(Left+Right+1)/2;
                    if(RMQ(i,mid)==cur) Left=mid;
                    else Right=mid-1;
                    //cout<<Left<<' '<<Right<<endl;
                }
                vis[cur]+=(Left-j+1);
                j=Left+1;
                cur=RMQ(i,j);
            }
        }
        printf("Case #%d:\n",ks);
        int q,l,r;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            int qu=RMQ(l,r);
            printf("%d %I64d\n",qu,vis[qu]);
        }

    }
    return 0;
}