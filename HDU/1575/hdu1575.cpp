#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
typedef long long ll;
const int inf=0x3f3f3f3f;
const LL mod=9973;
const int maxn=1e3+5;
int N;LL K;
typedef struct Matrix
{
    LL m[13][13];
    void init()
    {
        memset(m,0,sizeof(m));
        for(int i=0; i<N; i++)
            m[i][i]=1;
    }
    void let(int a,int b,int c,int d)
    {
		m[0][0]=a,m[0][1]=b,m[1][0]=c,m[1][1]=d;
	}
	void let()
	{
	    for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%I64d",&m[i][j]);
	}
    Matrix operator *(Matrix &tmp)
    {
        Matrix res;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                {
                    res.m[i][j]=0;
                    for(int k=0;k<N;++k)
                    {
                        res.m[i][j]+=(m[i][k]*tmp.m[k][j])%mod;
                        res.m[i][j]%=mod;
                    }
                }
        return res;
    }
    Matrix operator -(Matrix &tmp)
    {
    	Matrix res;
    	for(int i=0;i<N;++i)
    	    for(int j=0;j<N;++j)
    	    	res.m[i][j]=(m[i][j]-tmp.m[i][j]+mod)%mod;
    	return res;
    }
};
Matrix pow(Matrix a,LL n)
{
    Matrix res;
    res.init();
    while(n)
    {
        if(n&1)
            res=res*a;
        n>>=1;
        a=a*a;
    }
    return res;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;si(t);
    Matrix mt;
    while(t--)
    {
        si(N);sl(K);
        mt.let();
        mt=pow(mt,K);
        LL ans=0;
        for(int i=0;i<N;i++)
            {
                ans+=mt.m[i][i];
                ans%=mod;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
