#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int N=2;
LL mod;
struct Matrix
{
    LL m[2][2];
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
    Matrix operator *(Matrix tmp)
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
    Matrix operator -(Matrix tmp)
    {
    	Matrix res;
    	for(int i=0;i<N;++i)
    	    for(int j=0;j<N;++j)
    	    	res.m[i][j]=(m[i][j]-tmp.m[i][j]+mod)%mod;
    	return res;
    }
    Matrix operator +(Matrix tmp)
    {
    	Matrix res;
    	for(int i=0;i<N;++i)
    	    for(int j=0;j<N;++j)
    	    	res.m[i][j]=(m[i][j]+tmp.m[i][j])%mod;
    	return res;
    }
    Matrix operator +(LL n)
    {
        Matrix res;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;++j)
                if(i==j) res.m[i][j]=(m[i][j]+n)%mod;
                else res.m[i][j]=m[i][j];
        return res;
    }
};
Matrix operator ^(Matrix a,LL n)
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
Matrix gsum(Matrix a,LL n)
{
    if(n==1) return a;
    if(n&1)
    {
        Matrix t1=a^n;
        Matrix t2=gsum(a,n-1);
        return t1+t2;
    }
    Matrix t1=gsum(a,n/2);
    Matrix t2=a^(n/2);t2=t2+1;
    return t1*t2;
}
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL kk,bb,nn;
    Matrix fib;fib.let(1,1,1,0);
    while(~scanf("%I64d%I64d%I64d%I64d",&kk,&bb,&nn,&mod))
    {
        Matrix mk=fib^kk;Matrix mb=fib^bb;
        Matrix mksum=gsum(mk,nn-1)+(mk^0);
        Matrix ans=(mb)*mksum;
        printf("%I64d\n",ans.m[0][1]);
    }
    return 0;
}
