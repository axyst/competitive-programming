#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1005;
char pic[maxn][maxn];
int row[maxn];int col[maxn];
int guardr[maxn];int guardc[maxn];
int main()
{
    //freopen("test.txt","r",stdin);
    int t,n,m;scanf("%d",&t);
    while(t--)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(guardr,0,sizeof(guardr));
        memset(guardc,0,sizeof(guardc));
        scanf("%d%d",&n,&m);
        LL num=0;
        for(int i=1;i<=n;i++) scanf("%s",pic[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            if(pic[i][j]=='G')
            {
                guardr[i]=j;guardc[j]=i;
            }
            else
            {
                row[i]++;col[j]++;num++;
            }
        LL ans=0,cnt=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            ans+=(i*cnt-sum)*row[i];//累加的方法数
            cnt+=row[i];//这行可以走的格子数
            sum+=row[i]*i;//总共可以走的格子数
        }
        cnt=sum=0;
        for(int i=1;i<=m;i++)
        {
            ans+=(i*cnt-sum)*col[i];
            cnt+=col[i];
            sum+=col[i]*i;
        }
        ans*=2;//路线有向方法翻倍
        LL bef=0,aft=0;
        for(int i=1;i<=n;i++)
        {
            if(!guardr[i]) bef=aft=0;
            else
            {
                bef=(guardr[i-1]&&guardr[i-1]<guardr[i])*bef+guardr[i]-1;
                //从左数这行守卫的位置;上一行最右的守卫在这一行的左边，则累加
                aft=(guardr[i-1]>guardr[i])*aft+m-guardr[i];
                //从右数这行守卫的位置;上一行最右的守卫在这一行的右边，则累加
                ans+=bef*aft*4;//走对角线2种方法;路线有向
            }
        }
        bef=aft=0;
        for(int i=1;i<=m;i++)
        {
            if(!guardc[i]) bef=aft=0;
            else
            {
                bef=(guardc[i-1]&&guardc[i-1]<guardc[i])*bef+guardc[i]-1;
                aft=(guardc[i-1]>guardc[i])*aft+n-guardc[i];
                ans+=bef*aft*4;
            }
        }
        printf("%.4f\n",(double)ans/(double)(num*num));
    }
    return 0;
}
