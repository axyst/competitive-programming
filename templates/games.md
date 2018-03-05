[视频教程](https://www.bilibili.com/video/av9114486/?t=2807)  
[kuangbin博客](http://www.cnblogs.com/kuangbin/archive/2011/08/28/2156426.html)

## Bash Game(巴什博奕)
> 只有一堆n个物品，两个人轮流从这堆物品中取物，规
定每次至少取一个，最多取m个。最后取光者得胜。

- n=（m+1）r+s：先取者要拿走s个物品，如果后取者拿走
k（≤m)个，那么先取者再拿走m+1-k个，结果剩下（m+1）（r-1）个，以后保持这样的
取法，那么先取者肯定获胜。总之，要保持给对手留下（m+1）的倍数，就能最后获胜。

```
if (m >= n || (n % (m+1) != 0)
    printf("先手胜")；
else
    printf("后手胜")；
```

### [博弈论PN点](http://m.blog.csdn.net/lh__huahuan/article/details/44653457)   
1、定义P-position和N-position：其中P代表Previous，N代表Next。直观的说，上一次move的人有必胜策略的局面是P-position，也就是“先手必败”，现在轮到move的人有必胜策略的局面是N-position，也就是“先手可保证必胜”。

（1）.无法进行任何移动的局面（也就是terminal position）是P-position；

（2）.可以移动到P-position的局面是N-position；

（3）.所有移动都导致N-position的局面是P-position。

2、P/N状态有如下性质：

（1）、若面临末状态者为获胜则末状态为胜态否则末状态为必败态。
（2）、一个局面是胜态的充要条件是该局面进行某种决策后会成为必败态。
（3）、一个局面是必败态的充要条件是该局面无论进行何种决策均会成为胜态
3、P点： 即必败点，某玩家位于此点，只要对方无失误，则必败；

   N点： 即必胜点，某玩家位于此点，只要自己无失误，则必胜。
- 例题：  
[hdu 1846 Brave Games](http://acm.hdu.edu.cn/showproblem.php?pid=1846)  
[hdu 2249 Public Sale](http://acm.hdu.edu.cn/showproblem.php?pid=2149)  
[hdu 2188](http://acm.hdu.edu.cn/showproblem.php?pid=2188)  
[hdu 2147 PN分析](http://acm.hdu.edu.cn/showproblem.php?pid=2147)

## Fibonaci's Game(斐波那契博弈)
> 有一堆个数为n的石子，游戏双方轮流取石子，满足：  
（1）先手不能在第一次把所有石子取完
（2）之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含2倍）

- 特点：规则动态化，取石子数量可变
- 结论：如果n不是斐波那契数，则先手胜，如果n是斐波那契数，则后手胜。

- 例题：[hdu 2516 取石子游戏](http://acm.hdu.edu.cn/showproblem.php?pid=2516)

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long llong;
llong f[60];

void Prepare_Fib()
{
    f[0] = 0;
    f[1] = 1;
    for (int i=2; i<=60; ++i)
        f[i] = f[i-1] + f[i-2];
}

int main()
{
    Prepare_Fib();

    llong n;
    while (scanf("%lld", &n) != EOF && n)
    {
        int i;
        for (i=1; i<=60; ++i)
        {
            if (n < f[i])
                break;
        }

        if (n == f[i-1])
            printf("Second win\n");
        else
            printf("First win\n");
    }
    return 0;
}

```

## Wythoff Game(威佐夫博弈)
> 有两堆各若干个物品，两个人轮流从某一堆或同
时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

- 结论：开始为奇异局势，后手胜，非奇异局势，先手胜
- 如何判断是否是奇异局势：前几个奇异局势是：（0，0）、（1，2）、（3，5）、（4，7）、（6，
10）、（8，13）、（9，15）、（11，18）、（12，20）  
ak =[k（1+√5）/2]，bk= ak + k  （k=0，1，2，…,n 方括号表示取整函数)。由于2/（1+√5）=（√5-1）/2，可以先求出j=[a（√5-1）/2]，若a=[
j（1+√5）/2]，那么a = aj，bj = aj + j，若不等于，那么a = aj+1，bj+1 = aj+1+ j + 1，若都不是，那么就不是奇异局势。然后再按照上述法则进行，一定会遇到奇异局势。
- 例题：[poj 1067 取石子游戏](http://poj.org/problem?id=1067)
```
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        if (a > b)
            swap(a, b);

        int c = (int) ((b - a) * ((sqrt(5.0)+1)/2));  //b-a为k
        if (a == c)
            puts("0");
        else
            puts("1");
    }
    return 0;
}

```

## Nim Game(尼姆博弈)
> 有三堆(或者是n堆）各若干个物品，两个人轮流从某一堆取任意多的
物品，规定每次至少取一个，多者不限，最后取光者得胜。

- 奇异局势：（0，0，0），（0，n，n），（1，2，3）
当所有数异或为0时为奇异局势
- 结论：  
奇异局势——后手胜
非奇异局势——先手胜
- 如何拿：（先手要使非奇异-->奇异）  
非奇异局势（a，b，c）:假设 a < b
< c,我们只要将 c 变为 a（+）b,即可,因为有如下的运算结果: a（+）b（+）(a（+）
b)=(a（+）a)（+）(b（+）b)=0（+）0=0。要将c 变为a（+）b，只要从 c中减去 c-（
a（+）b）即可。

- 例题：[hdu 1850](http://acm.hdu.edu.cn/showproblem.php?pid=1850)

```
#include<cstdio>
#include<iostream>
using namespace std;

int a[105];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n)
    {
        int sum_or = 0;
        for (int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            sum_or ^= a[i];
        }

        if (sum_or == 0)  //奇异局势
            puts("0");
        else
        {
            int cnt = 0;
            for (int i=1; i<=n; i++)
            {
                int temp = sum_or ^ a[i]; //和a[i]异或抵消，剩下temp个石子即由非奇异-->奇异
                if (temp < a[i])
                    cnt++;
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}

```
## 取石子游戏

1. 今有若干堆火柴，两人依次从中拿取，规定每次只能从一堆中取若干根， 可将一堆全取走，但不可不取，最后取完者为胜，求必胜的方法。 
- 定义：若所有火柴数异或为0，则该状态被称为利他态，用字母T表示；否则， 为利己态，用S表示。
- 【结论】：S态必胜，T态必败。

2. 今有若干堆火柴，两人依次从中拿取，规定每次只能从一堆中取若干根， 可将一堆全取走，但不可不取，最后取完者为负，求必胜的方法。
- 定义：若一堆中仅有1根火柴，则被称为孤单堆。若大于1根，则称为充裕堆。
- 定义：T态中，若充裕堆的堆数大于等于2，则称为完全利他态，用T2表示；若充裕堆的堆数等于0，则称为部分利他态，用T0表示。
 
- 孤单堆的根数异或只会影响二进制的最后一位，但充裕堆会影响高位（非最后一位）。一个充裕堆，高位必有一位不为0，则所有根数异或不为0。故不会是T态。
- 【结论】：  
必输态有：  T2,S0   
必胜态：    S2,S1,T0.

- 例题：[hdu 1907](http://acm.hdu.edu.cn/showproblem.php?pid=1907)
- 【题目大意】：John和Brother在n堆里拿糖果，拿到最后一个的输，判断谁赢
```
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);

        int sum_or = 0;  //判断是T态还是S态
        int chongyu = 0; //判断充裕堆的数量
        int x;
        while (n--)
        {
            scanf("%d", &x);
            if (x > 1)
                chongyu++;
            sum_or ^= x;
        }

        if (((sum_or == 0) && (chongyu >= 2)) ||((sum_or != 0) && (chongyu == 0)))
            printf("Brother\n");
        else
            printf("John\n");

    }
    return 0;
}

```


## 公平组合博弈
 【定义】：  
 （1）两人参与。  
 
（2）游戏局面的状态集合是有限。  

（3）对于同一个局面，两个游戏者的可操作集合完全相同  

（4）游戏者轮流进行游戏。  

（5）当无法进行操作时游戏结束，此时不能进行操作的一方算输。

（6）无论游戏如何进行，总可以在有限步数之内结束。

## SG函数
> SG值：一个点的SG值就是一个不等于它的后继点的SG的且大于等于零的最小整数。
后继点：也就是按照题目要求的走法（比如取石子可以取的数量，方法）能够走一步达到的那个点。

[具体过程和SG值详解](http://m.blog.csdn.net/strangedbly/article/details/51137432)

首先定义mex(minimal excludant)运算，这是施加于一个集合的运算，表示最小的不属于这个集合的非负整数。例如
mex{0,1,2,4}=3、mex{2,3,5}=0、mex{}=0。
对于一个给定的有向无环图，定义关于图的每个顶点的Sprague-Grundy函数g如下：g(x)=mex{ g(y) | y是x的后继},这里的g（x）即
sg[x]。

例如：取石子问题，有1堆n个的石子，每次只能取{1，3,4}个石子，先取完石子者胜利，那么各个数的SG值为多少？  

sg[0]=0，f[]={1,3,4},  

x=1时，可以取走1-f{1}个石子，剩余{0}个，mex{sg[0]}={0}，故sg[1]=1;  

x=2时，可以取走2-f{1}个石子，剩余{1}个，mex{sg[1]}={1}，故sg[2]=0；  

x=3时，可以取走3-f{1,3}个石子，剩余{2,0}个，mex{sg[2],sg[0]}={0,0}，故sg[3]=1;  

x=4时，可以取走4-f{1,3,4}个石子，剩余{3,1,0}个，mex{sg[3],sg[1],sg[0]}={1,1,0},故sg[4]=2;  

x=5时，可以取走5-f{1,3,4}个石子，剩余{4,2,1}个，mex{sg[4],sg[2],sg[1]}={2,0,1},故sg[5]=3；

以此类推.....

   x         0  1  2  3  4  5  6  7  8....

sg[x]      0  1  0  1  2  3  2  0  1....

计算从1-n范围内的SG值。

f(存储可以走的步数，f[0]表示可以有多少种走法)

f[]需要从小到大排序

1. 可选步数为1~m的连续整数，直接取模即可，SG(x) = x % (m+1);
2. 可选步数为任意步，SG(x) = x;
3. 可选步数为一系列不连续的数，用getSG()计算

- 模板1（SG打表）
```
//f[]：可以取走的石子个数  
//sg[]:0~n的SG函数值  
//hash[]:mex{}  
int f[N];//可以取走的石子个数  
int sg[N];//0~n的SG函数值  
int Hash[N];  

void getSG(int n){  
    memset(sg,0,sizeof(sg));  
    for(int i = 1; i <= n; i++){  
        memset(Hash,0,sizeof(Hash));  
        for(int j = 1; f[j] <= i; j++)  
            Hash[sg[i-f[j]]] = 1;  
        for(int j = 0; j <= n; j++){    //求mes{}中未出现的最小的非负整数  
            if(Hash[j] == 0){  
                sg[i] = j;  
                break;  
            }  
        }  
    }  
}  
```

- 模板2（dfs）
```
//注意 S数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍  
//n是集合s的大小 S[i]是定义的特殊取法规则的数组  
int s[N],sg[N],n;  
bool vis[N];  
int dfs_SG(int x){  
    if(sg[x] != -1)  
        return sg[x];  
    memset(vis,0,sizeof(vis));  
    for(int i = 0; i < n; ++i){  
        if(x >= s[i]){  
            dfs_SG(x-s[i]);  
            vis[sg[x-s[i]]] = 1;  
        }  
    }  
    for(int i = 0;; ++i){  
        if(!vis[i]){  
            e = i;  
            return sg[x] = i;  
        }  
    }  
}  
```

- [hdu 1847](http://acm.hdu.edu.cn/showproblem.php?pid=1847)
```
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int bin[15];  //Ààfº¯Êý
int sg[1005];

int mex(int x)
{
    if (sg[x] != -1)
        return sg[x];

    bool vis[1005];
    memset(vis, false, sizeof(vis));

    for (int i=0; i<=10; ++i)
    {
        int temp = x - bin[i];
        if (temp < 0)
            break;

        sg[temp] = mex(temp);
        vis[sg[temp]] = true;
    }

    for (int i=0; ; ++i)
        if (!vis[i])
        {
            sg[x] = i;
            break;
        }
    return sg[x];
}

int main()
{
    bin[0] = 1;
    for (int i=1; i<=10; ++i)
        bin[i] = 2 * bin[i-1];

    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(sg, -1, sizeof(sg));

        if (mex(n))
            printf("Kiki\n");
        else
            printf("Cici\n");
    }
    return 0;
}

```
