#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int n,k,mod;
struct matrix
{
    int m[64][64];
};
matrix multi(matrix a,matrix b)
{
    matrix tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tmp.m[i][j]=0;
            for(int z=0;z<n;z++)
            {
                if(!a.m[i][z]||!b.m[z][j]) continue;
                tmp.m[i][j]=(tmp.m[i][j]+a.m[i][z]*b.m[z][j])%mod;
            }
        }
    }
    return tmp;
}
matrix fastmod(matrix use,int x)
{
    matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<n;i++)ans.m[i][i]=1;
    while(x)
    {
        if(x&1) ans=multi(ans,use);
        use=multi(use,use);
        x>>=1;
    }
    return ans;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t1,t2,t3;
    while (scanf("%d%d%d",&t1,&t2,&t3)!=EOF)
    {
    n=t1,k=t2,mod=t3;//维数,次数,模
    matrix base,out;
    memset(base.m,0,sizeof(base.m));
    memset(out.m,0,sizeof(out.m));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&base.m[i][j+n]);
            out.m[i+n][j+n]=base.m[i][j+n];
        }
    for(int i=0;i<n;i++)
        out.m[i][i]=out.m[i+n][i]=1;
    n*=2;
    out=fastmod(out,k);
    base=multi(base,out);
    for(int i=0;i<n/2;i++)
    {
        printf("%d",base.m[i][0]);
        for(int j=1;j<n/2;j++)
            printf(" %d",base.m[i][j]);
        printf("\n");
    }
    }
    return 0;
}