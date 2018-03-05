#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
class Fraction
{
    public:
    int a,b;//numerator/denominator
    int sgn(int x){return (x>0?1:-1);}
    Fraction():a(0),b(1){}
    Fraction(int x):a(x),b(1){}
    Fraction(int x,int y)
    {
        int m=gcd(abs(x),abs(y));
        a=x/m*sgn(y);
        b=(a?abs(y/m):1);
    }
    Fraction operator+(Fraction f)
    {
        int m=gcd(b,f.b);
        return Fraction(f.b/m*a+b/m*f.a,b/m*f.b);
    }
    Fraction operator-(Fraction f)
    {
        int m=gcd(b,f.b);
        return Fraction(f.b/m*a-b/m*f.a,b/m*f.b);
    }
    Fraction operator*(Fraction f)
    {
        int m1=gcd(abs(a),f.b);
        int m2=gcd(b,abs(f.a));
        return Fraction((a/m1)*(f.a/m2),(b/m2)*(f.b/m1));
    }
    Fraction operator/(Fraction f)
    {
        return (*this)*Fraction(f.b,f.a);
    }
    friend ostream &operator<<(ostream &out,Fraction f)
    {
        //if(f.a==0) cout<<0;
        //else if(f.b==1) cout<<f.a;
        //else
        cout<<f.a<<' '<<f.b;
        return out;
    }
};
int a[10];int b[10];
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;si(t);
    for(int ks=1;ks<=t;ks++)
    {
        int n;si(n);
        for(int i=1;i<=n;i++) si(a[i]);
        for(int i=1;i<=n;i++) si(b[i]);
        Fraction tmp(b[n],a[n]);
        for(int i=n-1;i>=1;i--)
        {
            Fraction upper(b[i]);
            Fraction add(a[i]);
            add=add+tmp;
            add=upper/add;
            tmp=add;
        }
        //Fraction up(b[1]);
        //tmp=up/tmp;
        cout<<"Case #"<<ks<<": "<<tmp<<endl;
    }
    return 0;
}