//博弈 Nim积 sg函数打表 母函数 容斥
//GCD 扩展GCD 中国剩余定理 快速幂 快速乘法 取模平方根 大步小步
//组合数 排列位数 全排列 素数表 欧拉函数 质因子分解
//矩阵 FFT Catalan 生成函数 置换 高斯消元 Lucas定理
//积性函数 莫比乌斯反演
#include<bits/stdc++.h>
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
//std::ios::sync_with_stdio(false);
//freopen("test.txt","r",stdin);

/*
博弈
1. 所有终止状态是P状态
2. 能一步到达P状态的状态为N状态
3. 每一步都将到达N状态的状态为P状态
不能行动=输
打表:从小到大枚举x，检查从x出发所有一步可达的状态中有
没有P状态(必输状态)。若有就是N状态，否则就是P状态

Ferguson:
有两个盒子，一开始其中一个有m个糖而另一个有n个糖。把这样的
状态记为(m, n)。每次走步是将一个盒子清空而把另一个盒子的一些糖拿到被清空的盒
子中，使得两个盒子各至少有一颗糖
m,n都为奇数,P;m,n至少一个为偶数,N

Chomp:
有一个m × n棋盘，每次可以取走一个方格并拿掉它右边和上面的所
有方格。拿到左下角的格子(1, 1)者输
当m=n=1,P;除此之外,先手均有必胜策略

Bash:
只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取1个，最多取m个
n%(m+1)!=0,则先取者肯定获胜

Wythoff:
有两堆石子，一堆有 m 个，另一堆有 n 个。
双方轮流取走一些石子，合法的取法有如下两种：
1. 在一堆石子中取走任意多颗；
2. 在两堆石子中取走相同多的任意颗
第 k 个P状态是
(floor(k*(sqrt(5)+1)*0.5)+k,floor(k*(sqrt(5)+1)*0.5))

Fibonacci:
双方轮流取n个石子，满足以下条件：
1. 先手不能在第一次把所有的石子取完；
2. 之后每次可以取的石子数介于 1 到对手刚取的石子数的 2 倍之间(包含 1 和对手刚取的石子数的 2 倍)
如果 n 是斐波那契数，则P；反之，N。

Nim:
有三堆各若干个物品，两个人轮流从某一堆取任意多的
物品，规定每次至少取一个，多者不限，最后取光者得胜
Bouton定理:XxorYxor...(Nim和)=0,P状态;否则是N状态

奇数偶数游戏:
有n堆火柴，每次你可以任选一堆拿。在任何情况下，你可以拿偶
数根火柴，但不能全部拿走；如果有奇数根火柴，可以全部拿走(也可以拿偶数根火
柴)
g(2k) = k-1,且g(2k -1) = k

Lasker’s Nim游戏:
和Nim游戏类似，但每次可以把一堆分为两个不为空的堆(不
拿走任何火柴)
g(4k+1)=4k+1,g(4k+2)=4k+2,g(4k+3)=4k+4,
g(4k+4)=4k+3

Kayles游戏:
有一堆火柴排成一排。每次可以拿走一根或者连续的两根(必须紧
挨在一起，中间不能有空隙)，最后取的获胜
g(y + z)从x = 72开始,以12为周期循环。

Dawson棋盘游戏:
在一列格子里，双方轮流在格子里划叉，禁止在一个已经有X的
相邻格子里划叉。不能画者输。在一堆的中间划叉相当于取走三个格子以后把它分成
两堆，在边上画X相当于拿掉2个格子或者1个格子。
在最后一个例外x = 51后， SG函数以34为周期循环

经典的翻硬币游戏是这样的：一些硬币排成一列，有的正面朝上，有的反面朝
上。每次可以选择一些硬币翻过来(正面变反面，反面变正面)。为了让游戏不会无
限进行下去，还需附加规定每次翻转的最右边一枚硬币必须是从正面H翻到反面T。这
样，每次操作后“最右边的H”都会左移，最终所有硬币变成T，无法继续移动

Mock Turtle游戏:
每次可以翻转1个、 2个或3个硬币，其中最右边一个必须
是H到T。
从0开始编号，二进制表示中1的个数为奇数的数，称为odious数，
如果x是odious数，则g(x) = 2x，否则g(x) = 2x + 1

Ruler游戏：可以翻任意多枚连续硬币，但最右一枚必须是从H翻到T
从1开始编号，g(x)是能整除x的2的最大整数幂

Acrostic Twins游戏：
每次翻两个硬币，要么同一行，要么同一列，其中右下方的
那个必须由H翻成T
g(x,y)=x xor y

Tartan定理： 如果g1(x)是G1的SG函数， g2(x)是G2的SG函数，则G1 × G2的SG函
数值为： g(x, y)=g1(x),g2(y)的Nim积
*/
//HDU3404 Nim积
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int sg[20][20];
int f(int,int);//声明一下，因为f与g互相嵌套调用
int g(int x, int y)//计算2^x与2^y的nim积
{
    if(sg[x][y] != -1)//查备忘录
    {
        return sg[x][y];
    }
    if(!x)//x==0也就是1与2^y的nim积，等于2^y
    {
        return sg[x][y] = 1<<y;
    }
    if(!y)//同上
    {
        return sg[x][y] = 1<<x;
    }
    int ans=1,k=1,t;
    int x1=x,y1=y;
    while(x||y)//再将x和y分为二进制，这里计算那些普通乘积的(即对应二进制位不同的)
    {
        t = 1<<k;//从此位得到的最终的数2^k
        if((x&1||y&1) && !((x&1)&&(y&1)))//该位不同
        {
            ans *= t;
        }
        x >>= 1;
        y >>= 1;
        k <<= 1;//从此位得到的指数(本身也是2的幂)
    }
    k = 1;
    x = x1;
    y = y1;
    while(x||y)//计算那些相同的fermat 2-power 数，与已得出的数的nim积
    {
        t = 1<<k;
        if((x&1)&&(y&1))//该位相同
        {
            ans = f(ans,t/2*3);
        }
        x >>= 1;
        y >>= 1;
        k <<= 1;//从此位得到的指数(本身也是2的幂)
    }
    return (sg[x1][y1] = ans);
}
int f(int x, int y)//计算二维的nim积
{
    if(!x || !y)return 0;
    if(x == 1)return y;
    if(y == 1)return x;
    int ans = 0;
    for(int i = x,a = 0; i; i>>=1,a++)//完成(将x和y分解后)按分配律计算其积
    {
        if((i&1)==0)continue;//该位(bit)是1才计算，否则跳过
        for(int j = y,b = 0; j; j>>=1,b++)
        {
            if((j&1)==0)continue;
            ans ^= g(a,b);
        }
    }
    return ans;
}
int main()
{
    int x,y,t;
    int n,ans;
    scanf("%d",&t);
    while(t--)
    {
        memset(sg,-1,sizeof(sg));
        scanf("%d",&n);
        ans = 0;
        while(n--)
        {
            scanf("%d%d",&x,&y);
            ans ^= f(x,y);

        }
        puts(ans ? "Have a try, lxhgww." : "Don't waste your time.");
    }
    return 0;
}
/*
Nim 问题：
异或和值为零则后手胜，否则先手胜。
当异或和值为零时，无论你怎么取，异或和值一定变为非零，对手以牙还牙，使异或和值变为零，如此循环，直至对手取完。故此时先手必败（处于必败态）。
当异或和值非零时，总能在某一堆中选取若干个石头，使得异或和值为零（可以自己找几个例子算算），则必胜态总能转移到必败态。
Grundy数
定义：当前状态的Grundy是除任意一步所能转移到的Grundy以外的最小非负整数
理解：本状态可以转移到的状态肯定与本状态相反，而所以找第一个不能转移到的状态就是其Grundy值
对于一个给定的有向无环图，定义关于图的每个顶点的Sprague-Garundy函数g如下：g(x)=mex{ g(y) | y是x的后继 }。
面对由n个游戏组合成的一个游戏时，只需对于每个游戏找出求它的每个局面的SG值的方法，就可以把这些SG值全部看成Nim的石子堆，然后依照找Nim的必胜策略的方法来找这个游戏的必胜策略了（Nim其实就是n个从一堆中拿石子的游戏求SG的变型，总SG=n个sg的异或）
解题模型：
1.把原游戏分解成多个独立的子游戏，则原游戏的SG函数值是它的所有子游戏的SG函数值的异或。
即sg(G)=sg(G1)^sg(G2)^...^sg(Gn)。
2.分别考虑每一个子游戏，计算其SG值。
SG值的计算方法：
1.可选步数为1~m的连续整数，直接取模即可，SG(x)= x % (m+1);
2.可选步数为任意步，SG(x) = x;
3.可选步数为一系列不连续的数，用模板计算。
*/
//sg function
int f[1000]={0,0,1,1};//初始化前4个
int g[500],c[1000];
int main()
{
    int i,j,k,m,n,s;
    for(i=4;i<=1000;i++)
    {
        m=0;
        for(j=1;j<=i/2;j++)
        {
            g[m++]=f[j-1]^f[i-j-1];
        }
        sort(g,g+m);
        for(k=0;;k++)
        if(g[k]!=k)//找其补集的最小值
        {
            f[i]=k;//找到f[i]
            break;
        }
    }
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",c+i);
        s=0;
        for(i=0;i<n;i++)
         s=s^f[c[i]];
        if(s==0)printf("先取者输\n");
        else printf("先取者赢\n");
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=(1<<20);
int sg[maxn];
int vis[23];
void print()
{
    for(int i=0; i<maxn; i++)
    {
        memset(vis,0,sizeof(vis));
        int lst=-1;
        for(int j=0; j<20; j++) //offset
            if(!((i>>j)&1)) lst=j;//destination pos
            else if (~lst)
            {
                vis[sg[i^(1<<j)^(1<<lst)]]=1;//move j to lst
            }
        for(int j=0;;j++)
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
        //printf("%d %d\n",i,sg[i]);
    }
}
int main()
{
    print();
    //freopen("test.txt","r",stdin);
    int t,n,m,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        while(n--)
        {
            scanf("%d",&m);
            int cur=0;//set of current row
            while(m--)
            {
                scanf("%d",&tmp);
                cur^=1<<(20-tmp);
            }
            ans^=sg[cur];//tot ans
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
//母函数
/*
K对应具体问题中物品的种类数。
v[i]表示该乘积表达式第i个因子的权重，对应于具体问题的每个物品的价值或者权重。
n1[i]表示该乘积表达式第i个因子的起始系数，对应于具体问题中的每个物品的最少个数，即最少要取多少个。
n2[i]表示该乘积表达式第i个因子的终止系数，对应于具体问题中的每个物品的最多个数，即最多要取多少个。
P是可能的最大指数。如果要求15元有多少组合，那么P就是15；如果问最小的不能拼出的数值，那么P就是所有钱加起来的和。如果最大无限，则设为INF
last是出现过的组合数中的最大值，最好设为全局变量方便之后遍历a数组
*/
void solve(int a[],int v[],int n1[],int n2[],int K)
{
    a[0]=1;
    int last=0;
    for (int i=0;i<K;i++)
    {
        int last2=min(last+n2[i]*v[i],P);
        memset(b,0,sizeof(int)*(last2+1));
        for (int j=n1[i];j<=n2[i]&&j*v[i]<=last2;j++)
            for (int k=0;k<=last&&k+j*v[i]<=last2;k++)
                b[k+j*v[i]]+=a[k];
        memcpy(a,b,sizeof(int)*(last2+1));
        last=last2;
    }
    //a[i]表示权重i的组合数，结束时a[i]=0说明i无法生成
}
//货币无限的情况
void solve(int a[],int v[],int K,int n)
{
    memset(a,0,sizeof(a));
    a[0]=1;
    for (int i=1;i<=K;i++)
    {
        memset(b,0,sizeof(b));
        for (int j=0;j*v[i]<=n;j++)
            for (int k=0;k+j*v[i]<=n;k++)
                b[k+j*v[i]]+=a[k];
        memcpy(a,b,sizeof(b));
    }
}
//指数型母函数
//HDU1521 有n种物品，并且知道每种物品的数量。要求从中选出m件物品的排列数
int jcs[15];
void jc()
{
    jcs[0]=1;
    for(int i=1;i<=12;i++)
    jcs[i]=jcs[i-1]*i;
}
int main ()
{
     double c1[15],c2[15];
     int c[15];
     int m,n,i,j,k;
     while(~scanf("%d%d",&n,&m))
     {
         for(i=1;i<=n;i++)
         scanf("%d",&c[i]);
         jc();
         for(i=0;i<=n;i++)
         {
            c1[i]=c2[i]=0;
         }
        c1[0]=1.0/jcs[0];
        for(i=1;i<=n;i++)
        {
           for(j=0;j<=m;j++)
           for(k=0;k+j<=m&&k<=c[i];k++)
           c2[k+j]+=c1[j]/jcs[k];
           for(j=0;j<=m;j++)
           c1[j]=c2[j],c2[j]=0;
        }
        printf("%.0f\n",c1[m]*jcs[m]);
    }
    return 0;
}
//容斥
LL solve(LL l,LL r,LL n) //[l,r]内与n互素的数字个数
{
    vector <LL> v;
    for(LL i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)v.push_back(n);
    int m=v.size();
    LL res=0;
    for(int i=1; i<(1<<m); i++)
    {
        int cnt=0;
        LL val=1;
        for(int j=0; j<m; j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                val*=v[j];
            }
        }
        if(cnt&1)res+=r/val-(l-1)/val;
        else res-=r/val-(l-1)/val;
    }
    return r-l+1-res;
}
//HDU 1796 m个元素(m<=20)的集合，问有多少个<n的数能够被集合中的数整除
int main()
{
    LL n,m;while(~scanf("%I64d%I64d",&n,&m))
    {
        n--;LL cnt=1;LL tmp;
        for(int i=0;i<m;i++)
        {
            sl(tmp);
            if(tmp) a[cnt++]=tmp;
        }
        m=cnt-1;LL upper=1<<m;
        LL ans=0;
        for(LL i=1;i<upper;i++)
        {
            LL oe=0;LL lcm=1;
            for(LL j=0;j<m;j++)
            {
                if((i>>j)&1)
                {
                    oe++;
                    lcm=lcm*a[j+1]/gcd(lcm,a[j+1]);
                }
            }
            if(oe&1) ans+=n/lcm;
            else ans-=n/lcm;
        }
        printf("%I64d\n",ans);

    }
    return 0;
}
//GCD
LL gcd(LL a,LL b)
{
    while(b)
    {
        LL t=a%b;
        a=b;
        b=t;
    }
    return a;
}
//extend GCD
//求解一组x,y使得ax+by=gcd(a,b)=d
//a*x+b*y=1 求得x即为a%b的逆元,y即为b%a的逆元
//A,B不互质时，A^B mod C = A^(B mod phi(C)+phi(C))
//费马小定理：如果模P是素数的话,inv(a)=pow(a,p-2)%p
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b) d=a,x=1,y=0;
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    LL d=exgcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-a/b*y;
    return d;
}
LL inv(LL a,LL b)// b is mod
{
    LL ret,dummy;
    exgcd(a,b,ret,dummy);
    return dummy;
}
// get all solution
void shift_solution (int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions (int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return 0;
    a /= g;  b /= g;

    int sign_a = a>0 ? +1 : -1;
    int sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    int lx = max (lx1, lx2);
    int rx = min (rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}
//Chinese remainder
//X mod m[0] = a[0], …, X mod m[i] = a[i],get X
/*
//这个版本似乎有问题，不确定是否是因为负数
LL china()
{
    LL M=1,x=0,y;
    for(int i=0; i<n; i++) M*=m[i];
    for(int i=0; i<n; i++)
    {
        LL w=M/m[i];
        exgcd(m[i],w,x,y);
        x=(x+y*w*a[i])%M;
    }
    return (n+x%M)%M;
}
*/
LL china(LL l, LL r, LL *m, LL *a)
{
    LL lcm = 1;
    for(LL i = l; i <= r; i++)lcm = lcm/gcd(lcm,m[i])*m[i];
    for(LL i = l+1; i <= r; i++)
    {
        LL A = m[l], B = m[i], d, k1, k2, c = a[i]-a[l];
        exgcd(A,B,d,k1,k2);
        if(c%d)return -1;
        LL mod = m[i]/d;
        LL K = ((k1*c/d)%mod+mod)%mod;
        a[l] = m[l]*K + a[l];
        m[l] = m[l]*m[i]/d;
    }
    if(a[l]==0)return lcm;
    return a[l];
}

//fast pow
LL fpow(LL a,LL b)
{
    if(a==0) return 0;
    assert(b>=0);
    LL ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
//fast multi
LL Multi(LL a, LL b)
{
    LL ans = 0;
    while(b)
    {
        if(b & 1)
            ans = (ans+a)%(mod-1);
        b>>=1LL;
        a = (a+a)%(mod-1);
    }
    return ans;
}
//x*x==a(mod n),n是质数,a,n互质
int ModPow(int a,int b,int n)
{
    LL d=1,i=0;
    while(b>=((LL)1<<i)) i++;
    for(--i;i>=0;--i)
    {
        d=d*d%n;
        if(b&(1<<i)) d=d*a%n;
    }
    return d;
}
int ModSqrt(int a,int n)
{
    int b,k,i,x;
    if(n==2) return a%n;
    if(ModPow(a,(n-1)/2,n)==1)
    {
        if(n%4==3) x=ModPow(a,(n+1)/4,n);
        else
        {
            for(b=1;ModPow(b,(n-1)/2,n)==1;b++);
            i=(n-1)/2;k=0;
            do{
                i/=2;
                k/=2;
                if((ModPow(a,i,n)*(LL)ModPow(b,k,n)+1)%n==0) k+=(n-1)/2;
            }while(i%2==0);
            x=(ModPow(a,(i+1)/2,n)*(LL)ModPow(b,k/2,n));
        }
        if(x*2>n) x=n-x;
        return x;
    }
    return -1;
}
//BSGS
//x^y identically equals z(mod p),given x,z,p,get y
struct Hashmap
{
    static const int Ha=999917,maxe=46340;
    int E,lnk[Ha],son[maxe+5],nxt[maxe+5],w[maxe+5];
    int top,stk[maxe+5];
    void clear() {E=0;while (top) lnk[stk[top--]]=0;}
    void Add(int x,int y) {son[++E]=y;nxt[E]=lnk[x];w[E]=inf;lnk[x]=E;}
    bool count(int y)
    {
        int x=y%Ha;
        for (int j=lnk[x];j;j=nxt[j])
            if (y==son[j]) return true;
        return false;
    }
    int& operator [] (int y)
    {
        int x=y%Ha;
        for (int j=lnk[x];j;j=nxt[j])
            if (y==son[j]) return w[j];
        Add(x,y);stk[++top]=x;return w[E];
    }
}f;
int BSGS(int A,int B,int C)
{
    if (C==1) if (!B) return A!=1; else return -1;
    if (B==1) if (A) return 0; else return -1;
    if (A%C==0) if (!B) return 1; else return -1;
    int m=ceil(sqrt(C)),D=1,Base=1;f.clear();
    for (int i=0;i<=m-1;i++)
    {
        f[Base]=min(f[Base],i);
        Base=((LL)Base*A)%C;
    }
    for (int i=0;i<=m-1;i++)
    {
        int x,y,r=exgcd(D,C,x,y);
        x=((LL)x*B%C+C)%C; //扩欧求A^j
        if (f.count(x)) return i*m+f[x];
        D=((LL)D*Base)%C;
    }
    return -1;
}
//组合数
LL combi(LL n,LL m)
{
    if (n==1||m==0||n==m) return dp[n][m]=1;
    if (dp[n][m]) return dp[n][m];
    return dp[n][m]=(combi(n-1,m-1)%mod+combi(n-1,m)%mod+mod)%mod;
}

LL inv[maxn],fac[maxn];//单组数据慢于上面，处理大数据不会爆栈
LL c(LL x,LL y)
{
    fac[0]=1;
    inv[0]=1;
    int up=2e5;
    for (int i=1;i<=up;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=fpow(fac[i],mod-2);
    }
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
//可重复的组合数为H(n,k)=C(n+k-1,k)种
//Stirling公式求n!的位数(n=1时特判)
res=(LL)((log10(sqrt(4.0*acos(0.0)*n))+n*(log10(n)-log10(exp(1.0))))+1);
//从第k到第n位的全排列
void range(int a[],int k,int n)
{
    if(k==n)
    {
        for(int i=1; i<=n; i++)
            printf("%d",a[i]);
        printf("\n");
    }
    for(int i=k; i<=n; i++)
    {
        swap(a[k],a[i]);
        range(a,k+1,n);
        swap(a[k],a[i]);
    }
}
// Given the natural numbers N and K, derive all subsets of size K
bool next_combination(vector<int>& a, int n) {
    int k = (int)a.size();
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] < n - k + i + 1) {
            a[i]++;
            for (int j = i + 1; j < k; j++)
                a[j] = a[j - 1] + 1;
            return true;
        }
    }
    return false;
}
//  Generate all K-combinations in such an order, that adjacent combinations differ exactly by one element
int gray_code (int n) {
    return n ^ (n >> 1);
}

int count_bits (int n) {
    int res = 0;
    for (; n; n >>= 1)
        res += n & 1;
    return res;
}

void all_combinations (int n, int k) {
    for (int i = 0; i < (1 << n); i++) {
        int cur = gray_code (i);
        if (count_bits(cur) == k) {
            for (int j = 0; j < n; j++) {
                if (cur & (1 << j))
                    cout << j + 1;
            }
            cout << "\n";
        }
    }
}
// faster O(N⋅(C_NK))
vector<int> ans;

void gen(int n, int k, int idx, bool rev) {
    if (k > n || k < 0)
        return;

    if (!n) {
        for (int i = 0; i < idx; ++i) {
            if (ans[i])
                cout << i + 1;
        }
        cout << "\n";
        return;
    }

    ans[idx] = rev;
    gen(n - 1, k - rev, idx + 1, false);
    ans[idx] = !rev;
    gen(n - 1, k - !rev, idx + 1, true);
}

void all_combinations(int n, int k) {
    ans.resize(n);
    gen(n, k, 0, false);
}
//prime&euler
//The number of prime numbers less than or equal to n is approximately n/ln n.
// prime list
// O(n)
const int N = 10000000;
int lp[N+1];
vector<int> pr;
lp[2]=2;pr.push_back(2);
for (int i=3; i*i<=N; i+=2) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}
// O(nloglogn)
int n;
int cnt=0;
int prime[maxn];
// char is faster than bool
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
is_prime[2] = true;
for (int i = 3; i * i <= n; i+=2) {
    if (is_prime[i] && (long long)i * i <= n) {
        prime[cnt++] = i;
        for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
}
// count prime(O(sqrt(n)+S) memory)
int count_primes(int n) {
    const int S = 10000;
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}
// euler O(sqrt(n))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
// euler func list
int t;
int cnt=0;
int prime[maxn];
bool vis[maxn];
int phi[maxn];//欧拉函数
void Prime(int n)//求出n以内(<n)所有素数以及所有<n的数的欧拉函数
{//下标从0开始
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2; i*i<n; i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0; j<cnt&&i*prime[j]<n; j++)
        {
            LL k=i*prime[j];
            vis[k]=1;
            if(i%prime[j]==0)
            {
                phi[k]=phi[i]*prime[j];
                break;
            }
            else phi[k]=phi[i]*(prime[j]-1);
        }
    }
}
//直接求phi(n)
int main()
{
    int n,i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=n;
        for(i=2; i*i<=n; i++)
        {
            if(n%i==0)
                sum=sum*(i-1)/i;
            while(n%i==0)
                n/=i;
        }
        if(n>1)
            sum=sum*(n-1)/n;
        printf("%d\n",sum);
    }
    return 0;
}
//****************************************************************
// Miller_Rabin 算法进行素数测试 O(logN)
//速度快，而且可以判断 <2^63的数
//****************************************************************
const int S=100;//随机算法判定次数，S越大，判错概率(2^(-S))越小
//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
long long mult_mod(long long a,long long b,long long c)
{
    a%=c;
    b%=c;
    long long ret=0;
    while(b)
    {
        if(b&1)
        {
            ret+=a;
            ret%=c;
        }
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}
//计算  x^n %c
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    long long tmp=x;
    long long ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}
//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t)
{
    long long ret=pow_mod(a,x,n);
    long long last=ret;
    for(int i=1; i<=t; i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}
// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
bool Miller_Rabin(long long n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    long long x=n-1;
    long long t=0;
    while((x&1)==0)
    {
        x>>=1;
        t++;
    }
    for(int i=0; i<S; i++)
    {
        long long a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}
//************************************************
//pollard_rho 算法进行质因数分解 O(N^(1/4)
//************************************************
long long factor[100];//质因数分解结果(刚返回时是无序的)
int tol;//质因数的个数。数组小标从0开始
long long gcd(long long a,long long b)
{
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}
long long Pollard_rho(long long x,long long c)
{
    long long i=1,k=2;
    long long x0=rand()%x;
    long long y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k)
        {
            y=x0;
            k+=k;
        }
    }
}
//对n进行素因子分解
void findfac(long long n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    long long p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}
int main()
{
    long long n;
    while(scanf("%I64d",&n)!=EOF)
    {
        tol=0;
        findfac(n);
        for(int i=0; i<tol; i++)printf("%I64d ",factor[i]);
        printf("\n");
        if(Miller_Rabin(n))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
//matrix
const int N=2;
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
// 二分求和 a^1+..+a^n
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
//FFT O(nlogn)多项式乘法
#include<iostream>
#include<cstdio>
#include<complex>
#include<cmath>
using namespace std;
typedef double lf;
const lf pi=acos(-1);
const int maxn=300005;
complex<lf>a[maxn],b[maxn],c[maxn];
int rev[maxn],n=1;
void init()
{
    for(int i=0; i<n; i++)
        rev[i]=(rev[i>>1]>>1)+((i&1)?(n>>1):0);
}
void fft(complex<lf>*y,int flag)
{
    for(int i=1; i<n; i++)
        if(i<rev[i])
            swap(y[i],y[rev[i]]);
    for(int k=2; k<=n; k<<=1)
    {
        complex<lf>tmp(cos(2*pi/k),flag*sin(2*pi/k));
        for(int i=0; i<n; i+=k)
        {
            complex<lf>x(1,0);
            for(int j=0; j<(k>>1); j++,x*=tmp)
            {
                complex<lf>y0=y[i+j],y1=y[i+j+(k>>1)];
                y[i+j]=y0+x*y1;
                y[i+j+(k>>1)]=y0-x*y1;
            }
        }
    }
}
int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    for(int i=0; i<=n1; i++)
        for(int i=0; i<=n1; i++)
            scanf("%lf",&a[i].real());
    for(int i=0; i<=n2; i++)
        scanf("%lf",&b[i].real());
    while(n<=n1+n2)n<<=1;
    init();
    fft(a,1),fft(b,1);
    for(int i=0; i<n; i++)
        c[i]=a[i]*b[i];
    fft(c,-1);
    for(int i=0; i<=n1+n2; i++)
        printf("%d ",(int)(c[i].real()/n+0.5));
    return 0;
}
//Catalan数
/*The Catalan number Cn is the solution for

Number of correct bracket sequence consisting of n opening and n closing brackets.
The number of rooted full binary trees with n+1 leaves (vertices are not numbered). A rooted binary tree is full if every vertex has either two children or no children.
The number of ways to completely parenthesize n+1 factors.
The number of triangulations of a convex polygon with n+2 sides (i.e. the number of partitions of polygon into disjoint triangles by using the diagonals).
The number of ways to connect the 2n points on a circle to form n disjoint chords.
The number of non-isomorphic full binary trees with n internal nodes (i.e. nodes having at least one son).
The number of monotonic lattice paths from point (0,0) to point (n,n) in a square lattice of size n×n, which do not pass above the main diagonal (i.e. connecting (0,0) to (n,n)).
Number of permutations of length n that can be stack sorted (i.e. it can be shown that the rearrangement is stack sorted if and only if there is no such index i<j<k, such that ak<ai<aj ).
The number of non-crossing partitions of a set of n elements.
The number of ways to cover the ladder 1…n using n rectangles (The ladder consists of n columns, where ith column has a height i).*/
// recursive (O(C^n))
const int MOD;
const int MAX;
int catalan[MAX];
void init() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}
// analytical (O(n))
#include<iostream>
using namespace std;
// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
// nth catalan number
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2*n, n);

    // return 2nCn/(n+1)
    return c/(n+1);
}
//DP O(n^2) 求C3~Cnum+1
int a[1005][1005];
int b[maxn];
void catalan(int num)
{
    int i, j, len, carry, temp;
    a[1][0]=b[1]=1;
    len=1;
    for(i=2; i<=num; i++)
    {
        for(j=0; j<len; j++)
            a[i][j]=a[i-1][j]*(4*(i-1)+2);
        carry=0;
        for(j=0; j<len; j++)
        {
            temp=a[i][j]+carry;
            a[i][j]=temp%10;
            carry=temp/10;
        }
        while(carry)
        {
            a[i][len++]=carry%10;
            carry/=10;
        }
        carry=0;
        for(j=len-1; j>=0; j--)
        {
            temp=carry*10+a[i][j];
            a[i][j]=temp/(i+1);
            carry=temp%(i+1);
        }
        while(!a[i][len-1])
            len--;
        b[i]=len;
    }
}
int main()
{
    catalan(9);
    for(int i=2;i<=9;i++)//C3~C10
    {
        //printf("%d %d\n",i+1,b[i]);
        int len=b[i];
        for(int j=len-1;j>=0;j--) printf("%d",a[i][j]);
        printf("\n");
    }
    return 0;
}
/*
生成函数
Fibonacci数的递推公式是Fn=Fn1+Fn2,边界是F1=F2=1,设它的生成函数是A(x),则
A(x) = F0 + F1x + F2x2 + F3x3 +...
xA(x) = 0 + F0x + F1x2 + F2x3 + ...
x2A(x) = 0 + 0 + F0x2 + F1x3 + ...
第一个等式减去后两个等式，则x2和更高项全部消去，因此有
这样，我们得到了Fn的生成函数

假设有三种水果，苹果只能选不超过3个，香蕉个数必须是4的倍数，桃子只能选2,3,5个
则这个排列组合问题的生成函数是:
(1+x+x^2+x^3)(x^4+x^8+x^12+...)(x^2+x^3+x^5)
选20个水果的组合数就是上式中x^20项的系数
选20个水果的排列数:(1+(1/1!)x+(1/2!)x^2+(1/3!)x^3)((1/4!)x^4+(1/8!)x^8+
(1/12!)x^12+...)((1/2!)x^2+(1/3!)x^3+(1/5!)x^5)
*/
/*
对于一个置换f，若方案s变换到自己，称它为f的不动点。f的不动点数目记为C(f)
Burnside引理:等价类数目为所有C(f)的平均值
Polya 定理
设 G 是 p 个对象的一个置换群，用 k 种颜色去染这 p 个对象，若一种染色方案在群 G 的作
用下变为一种方案，则这两个方案当作是同一种方案，这样的不同染色方案数为：
L=1/|G|*sum(k^c(f)),f属于G
C(f)为循环节 |G|表示群的置换方法数

所有n个元素的循环节就是这些小循环节长度的最小公倍数
找出所有的小循环复杂度为O(n)，因为每个位置最多被遍历一次

对于 n 个位置的手镯，有 n 种旋转置换和 n 种翻转置换
对于旋转置换：
C(fi ) =gcd(n,i),i 表示旋转 i 颗宝石以后。 i=0 时 gcd(n,0)=n
对于翻转置换：
如果 n 为偶数：则有 n/2 个置换C(f)=n/2
如果 n 为奇数：则有 n 个置换C(f)=n/2
*/
// 循环节计数
int count_cycles(Permutation p) {
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != -1) {
            cnt++;
            for (int j = i; p[j] != -1;) {
                int next = p[j];
                p[j] = -1;
                j = next;
            }
        }
    }
    return cnt;
}

//高斯消元
#define eps 1e-9
const int maxn=220;
double a[maxn][maxn],x[maxn];//方程的左边的矩阵和等式右边的值，求解之后x存的就是结果
int equ,var;//方程数和未知数个数
/*
*返回0表示无解， 1表示有解
*/
int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0; k<equ&&col<var; k++,col++)
    {
        max_r=k;
        for(i=k+1; i<equ; i++)
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
        if(k!=max_r)
        {
            for(j=col; j<var; j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1; j<var; j++)a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0; i<equ; i++)
            if(i!=k)
            {
                x[i]-=x[k]*a[i][k];
                for(j=col+1; j<var; j++)a[i][j]-=a[k][j]*a[i][col];
                a[i][col]=0;
            }
    }
    return 1;
}
//求C(n,m)%p
long long F[100010];
void init(long long p)
{
    F[0] = 1;
    for(int i = 1;i <= p;i++)
        F[i] = F[i-1]*i % (1000000007);
}
long long inv(long long a,long long m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
long long Lucas(long long n,long long m,long long p)
{
    long long ans = 1;
    while(n&&m)
    {
        long long a = n%p;
        long long b = m%p;
        if(a < b)return 0;
        ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
        n /= p;
        m /= p;
    }
    return ans;
}
//积性函数 gcd(a,b)=1,s(a*b)=s(a)*s(b)
//hdu 1452 求2014的x次方的所有因子的和,输出%29后的值
int main()
{
//gcd(a,b)=1,s(a*b)=s(a)*s(b)
//s(p^n)=1+p+p^2+...+p^n= (p^(n+1)-1) /(p-1)
//2004=2^2*3*167
//s(2004^X)) = (s(2^2X))) * (s(3^X))) * (s(167^X)))
//=(2^(2X+1)-1)* (3^(X+1)-1)/2  *(22^(X+1)-1)/21 (because 167%29=22)
    int inv2=inv(29,2)%mod;
    int inv21=inv(29,21)%mod;
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int a=(fpow(2,2*n+1)-1)%mod;
        int b=(fpow(3,n+1)-1)*inv2%mod;
        int c=(fpow(22,n+1)-1)*inv21%mod;
        printf("%d\n",a*b*c%mod);
    }
    return 0;
}
//d|n:d能整除n,例:1|n for every n
//莫比乌斯反演
//f(x) = sigma{g(d)}其中x % d == 0，则g(x) = sigma{mu(d) * f(x/d)}
//f(x) = sigma{g(d)}其中d % x == 0，则g(x) = sigma{mu(d/x) * f(d)}
//HDU 1695 x 属于 [1,b] ，y属于[1,d]  求有多少对(x,y)满足gcd(x,y)==k
bool vis[maxn];int prime[maxn],mu[maxn];int cnt;
void Init()
{
    memset(prime,0,sizeof(prime));
    memset(mu,0,sizeof(mu));
    memset(vis,0,sizeof(vis));
    mu[1] = 1;
    cnt = 0;
    for(int i=2; i<maxn; i++)
    {
        if(!vis[i])
        {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<cnt&&i*prime[j]<maxn; j++)
        {
            vis[i*prime[j]] = 1;
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];
            else
            {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
}
void getMu()
{
    for(int i=1; i<maxn; ++i)
    {
        int target=i==1?1:0;
        int delta=target-mu[i];
        mu[i]=delta;
        for(int j=2*i; j<maxn; j+=i)
            mu[j]+=delta;
    }
}
// F(d):有多少对(x,y)满足 gcd(x,y)== d,F(x)=(b/x)*(d/x)
// f(d):有多少对(x,y)满足 gcd(x,y)== d的倍数, f(1)= mu(1)*F(1)+ mu(2)*F(2)+……mu(min(m,n))*F(min(m,n))
int main()
{
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    LL ans1=0,ans2=0;
    for(int i=1; i<=min(b,d); i++)
        ans1+=(LL)mu[i]*(b/i)*(d/i);
    for(int i=1; i<=min(b,d); i++)
        ans2+=(LL)mu[i]*(min(b,d)/i)*(min(b,d)/i);//重复计算的情况
    cout<<ans1-ans2/2<<endl;
    return 0;
}
//校验三角形数：如果n=(sqrt(s*x+1)-1)/2为整数,那么x是第n个三角形数
// 原根 (g that g^k≡a(modn), a∈[1,n-1]
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}