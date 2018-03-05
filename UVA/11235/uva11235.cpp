#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
int a[maxn];int num[maxn];int Left[maxn];int Right[maxn];
int d[maxn][20];
void RMQ_init(const vector<int>& A)
{
    int n=A.size();
    for(int i=0;i<n;i++) d[i][0]=A[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(d[L][k],d[R-(1<<k)+1][k]);
}
int main()
{
    freopen("test.txt","r",stdin);
    int n,q;
    while(scanf("%d%d",&n,&q)==2&&n)
    {
        for(int i=0;i<n;i++) scanf("%d",a+i);
        a[n]=a[n-1]+1;
        int l=0;vector<int>counts;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>a[i-1])
            {
                counts.push_back(i-l);
                for(int j=l;j<i;j++)
                {
                    num[j]=counts.size()-1;
                    Left[j]=l;
                    Right[j]=i-1;
                }
                l=i;
            }
        }

        RMQ_init(counts);
        int a,b,ans;
        while(q--)
        {
            scanf("%d%d",&a,&b);a--,b--;
            if(num[a]==num[b]) ans=b-a+1;
            else
            {
                ans=max(b-Left[b]+1,Right[a]-a+1);
                if(num[a]+1<num[b]) ans=max(ans,RMQ(num[a]+1,num[b]-1));
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
