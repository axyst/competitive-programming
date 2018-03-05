//Maxsum LCS LIS
//背包 区间 树形 数位 记忆化搜索
//状压 插头
//Maxsum O(n)
int a[n];
int maxsum()
{
    int cur=0;int mx=0;
    for(int i=0;i<n;i++)
    {
        if(cur+a[i]>=0) cur+=a[i];
        else cur=0;
        mx=max(mx,cur);
    }
    return mx;
}
//LCS
///O(n^2),a,b start from 1
char a[m];char b[n];int d[n];//(n<m)
int LCS()
{
    for(int i=0;i<=n;i++) d[i]=0;
    for(int i=1;i<=m;i++)
    {
        int lst=0;int len;
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]) len=lst+1;
            else len=max(d[j],d[j-1]);
            lst=d[j];
            d[j]=len;
        }
    }
    return d[n];
}
/*O(nlogn);我们把a序列中的每个元素在b中出现的位置保存起来，再按照降序排列，排列后再代入a的每个对应元素，那就转化为了求这个新的序列的最长上升子序列了。如：a[] = {a, b, c,} b[] = {a,b,c,b,a,d},那么a中的a，b，c在b中出现的位置分别就是
{0,4},{1,3},{2}分别按降序排列后代入a序列就是{4,0,2,3,1},之所以要按照降序排列，目的就是为了让每个元素只取到一次。
接下来的问题就是要求最长升序子序列问题了，也就是求LIS
int a[LEN], b[LEN];
int loc[LEN], n;
void calLoc()
{
    int i;
    for(i = 1; i <= n; i++)
        loc[b[i]] = i;
}
int LIS()
{
    int i, k, l, r, mid;
    a[1] = b[1], k = 1;
    for(i = 2; i <= n; i++)
    {
        if(a[k] < b[i]) a[++k] = b[i];
        else {
            l = 1; r = k;
            while(l <= r)
            {
                mid = ( l + r ) / 2;
                if(a[mid] < b[i])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            a[l] = b[i];
        }
    }
    return k;
}
int main()
{
    int i;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        calLoc();
        for(i = 1; i <= n; i++)
            b[i] = loc[a[i]];
                printf("%d\n", LIS());
    }
    return 0;
}
*/
///LISequence O(nlogn)
int a[n];int g[n];int d[n];
int LIS()
{
    for(int i=0; i<n; i++)
    {
        int j=lower_bound(g,g+n,a[i])-g;
        d[i]=j+1;
        g[j]=a[i];
    }
    return d[n-1];
}
//LISubstring O(n)
int LISB(int n)
{
    dp[0]=1;int mx=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        if(a[i-1]<a[i]&&dp[i-1]+1>dp[i]&&a[i]>a[i-1])
            dp[i]=dp[i-1]+1;
        if(dp[i]>dp[i-1]+1)
            dp[i]=1;
        mx=max(mx,dp[i]);
    }
    return mx;
}
//最大递增子序列的和
int a[maxn];int dp[maxn];
int LISsum()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=a[i];
        for(int j=0;j<i;j++)
            if(a[i]>a[j])
            dp[i]=max(dp[i],dp[j]+a[i]);
        ans=max(ans,dp[i]);
    }
    return ans;
}
//LCIS
int LCIS(int la,int lb)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=la;++i)
    {
        int mx=0;
        for(int j=1;j<=lb;++j)
        {
            if(b[j]<a[i])  {mx=max(mx,dp[j]);}
            if(a[i]==b[j]) {dp[j]=mx+1;}
        }
    }
    int ans=-1;
    for(int i=1;i<=la;++i)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}
///背包
int t;//循环次数
int cnt=0;
int volume;int dp[MAXN];
//完全背包 O(VN)
void cpack()
{
    for(int i=0;i<n;i++)
    {
        //for(int j=c[i];j<=v;j++)
            //dp[i]=max(dp[i],dp[i-c[j]]+v[j]);
        cpack(c[i],v[i]);
    }
}
void cpack(int cost,int value)
{
    for(int i=cost;i<=volume;i++)
        dp[i]=min(dp[i],dp[i-cost]+value);
}
//01背包 O(VN)
void zopack()
{
    for(int i=0;in;i++)
    {
        //for(int j=v;j>=c[i];j--)
            //dp[i]=max(dp[i],dp[i-c[j]]+v[j]);
        zopack(c[i],v[i]);
    }
}
void zopack(int cost,int value)
{
    for(int i=volume;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]+value);
}
//多重背包 O(V*sum(logMi)),Mi is ith amount
void mpack()
{
    for(int i=0;i<n;i++)
    {
        mpack(c[i],v[i],m[i]);
    }
}
void mpack(int cost,int value,int num)
{
    if(cost*num>=volume)
    {
        cpack(cost,value);
        return;
    }
    for(int k=1;k<num;k*=2)
    {
        zopack(k*cost,k*value);
        num-=k;
    }
    zopack(num*cost,num*value);
}
//当问题是“每种有若干件的物品能否填满给定容量的背包”，只须考虑填满背包的
//可行性，不需考虑每件物品的价值时，多重背包问题同样有 O(V N) 复杂度的算法。
//最终 F[N][0 . . . V ] 便是多重背包可行性问题的答案
void mpack(int cost,int value,int num)
{
    for(int i=1;i<=volume;i++) dp[0][i]=-1;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=volume;j++)
            if(dp[i-1][j]>=0) dp[i][j]=m[i];
            else dp[i][j]=-1;
        for(int j=0;j<=volume-c[i];j++)
            if(dp[i][j]>0) d[i][j+c[i]]=max(dp[i][j+c[i]],dp[i][j]-1);
    }

}
//二维背包，其他情况下类推即可
void zopack(int cost1,int cost2,int value)
{
    for(int i=volume1;i>=cost1;i--)
        for(int j=volume2;j>=vost2;j--)
        dp[i][j]=max(dp[i][j],dp[i-cost1][j-cost2]+value);
}
//有时，“二维费用”的条件是以这样一种隐含的方式给出的：最多只能取 U 件物品。
//分组背包
//物品被划分为 K 组，每组中的物品互相冲突，最多选一件
void gpack()
{
    for(int kk=1;kk<=k;kk++)
    {
        for(int i=v;i<=0;i--)
            for(int j=0;j<size[k];j++)
            dp[i]=max(dp[i],dp[i-c[j]]+w[j]);
    }
}
//依赖背包
//物品 i 依赖于物品 j，表示若选物品 i，则必须选物品 j
#include<stdio.h>
#include<algorithm>
#include <iostream>
using namespace std;
const int maxn=1000+10;
int w[maxn],b[maxn];
int f[maxn];
int max(int a,int b)
{
    return a>b? a:b;
}
int main()
{
    int n,v;
    int i,j,k;
    int t1,t2;
    while(scanf("%d%d",&n,&v)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&w[i],&b[i]);
        }
        memset(f,0,sizeof(f));
        for(i=1; i<=n; i++)
            if(b[i]==i)//找出主件
            {
                memset(c,0,sizeof(c));
                for(t2=1; t2<=n; t2++) //对附件进行01背包处理，使得在相同体积下得到的价值最大
                    if(b[t2]==i&&b[t2]!=t2)
                    {
                        for(t1=v-1; t1>=0; t1--)
                            if(t1-1>=0)
                                c[t1]=max(c[t1],c[t1-1]+w[t2]);
                    }
                c[v]=c[v-1]+w[i];
                for(j=v; j>=0; j--)
                    for(k=1; k<=v; k++) //此时看作相当于"V件物品"，每件”物品体积“相当为'k',"价值为"，c[k-1]+w[i],(i为主件)
                    {
                        if(j-k>=0)
                            f[j]=max(f[j],f[j-k]+w[i]+c[k-1]);
                    }
            }
        printf("%d\n",f[v]);
    }
    return 0;
}
/*
泛化物品
在背包容量为 V 的背包问题中，泛化物品是一个定义域为 0 . . . V中的整数的函数 h，当分配给它的费用为 v 时，能得到的价值就是 h(v)
对于 0. . .V 中的每一个整数 v，可以求得费用v 分配到 h 和 l 中的最大价值 f(v)。也即
f(v) = max{h(k) + l(v ? k) | 0 ≤ k ≤ v}
*/
/*
可以不装满：初始化时DP全设为0即可（设为INF代表未装物品的该状态不可接受）
输出字典序最小的最优方案
先把物品编号做 x ← N + 1 - x 的变换，在输出方案时再
变换回来。在做完物品编号的变换后，可以按照前面经典的转移方程来求值。只是在输
出方案时要注意，如果 F [i, v] = F [i - 1, v] 和 F [i, v] = F [i - 1][v - Ci] + Wi 都成立，
应该按照后者来输出方案，即选择了物品 i，输出其原来的编号 N - 1 - i
求方案数：将状态转移方程中的 max 改成 sum
求最优方案数：初始化g为0,如果dp[v]=dp[v],g[v]+=g[v];dp[v]=dp[v-c[i]],g[v]+=g[v-c[i]]
*/
//第k大解
int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
        int n,m,i,j,k,p,a[33],b[33];
         scanf("%d%d%d",&n,&m,&k);
         for(i=0;i<n;i++)
             scanf("%d",&w[i]);
         for(i=0;i<n;i++)
             scanf("%d",&c[i]);
         memset(dp,0,sizeof(dp));
         for(i=0;i<n;i++)
         {
             for(j=m;j>=c[i];j--)
             {
                 for(p=1;p<=k;p++)
                 {
                     a[p]=dp[j-c[i]][p]+w[i]; //在dp[i]=max(dp[j],dp[j-c[i]]+w[i])中产生后续优解，小的为次优
                     b[p]=dp[j][p];
                 }
                 a[p]=b[p]=-1;
                 int x,y,z;
                 x=y=z=1;
                 while(z<=k&&(a[x]!=-1||b[y]!=-1))//产生分歧后找到其中最大的k的保留
                 {
                     if(a[x]>b[y])
                     {
                         dp[j][z]=a[x];
                             x++;
                     }
                     else
                     {
                         dp[j][z]=b[y];
                             y++;
                     }
                     if(dp[j][z]!=dp[j][z-1])//去掉重复了的优解
                        z++;
                 }
             }
         }
         printf("%d\n",dp[m][k]);
     }
     return 0;
}
///区间DP-石子归并
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
int dp[N][N],sum[N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a[N];sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        int i,j,l,k;
        for(l = 2; l <= n; ++l)
        {
            for(i = 1; i <= n - l + 1; ++i)
            {
                j = i + l - 1;
                dp[i][j] = 2100000000;
                for(k = i; k < j; ++k)
                {
                    dp[i][j] = std::min(dp[i][j],dp[i][k] + dp[k + 1][j] + sum[j] - sum[i-1]);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
///树形DP
struct node
{
    int v;
    int next;
}tree[MAXN];
int vis[MAXN],head[MAXN],dp[MAXN][2];
int ptr,n;
void init()
{
    ptr=0;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
}
void addedge(int x,int y)//y is x's son
{
    tree[ptr]=(node){y,head[x]};
    head[x]=ptr++;
}
void treedp(int cur)
{
    vis[cur]=1;
    for(int i=head[cur];i!=-1;i=tree[i].next)
    {
        int v=tree[i].v;
        if(!vis[v])
        {
            treedp(v);
            dp[cur][1]+=dp[v][0];
            dp[cur][0]+=max(dp[v][1],dp[v][0]);
        }
    }
}
int main()
{
    int n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=1;i<=n;i++) scanf("%d",&dp[i][1]);
        while(scanf("%d%d",&a,&b),a+b)
        {
            addedge(a,b);
            addedge(b,a);
        }
        treedp(1);
        printf("%d\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}
///数位DP
int dfs(int i, int s, bool e) {
    if(i==-1) return s==target_s;
    if(!e && ~f[i][s]) return f[i][s];
    int res = 0;
    int u = e?num[i]:9;
    for(int d = first?1:0; d <= u; ++d)
       res += dfs(i-1, new_s(s, d), e&&d==u);
   return e?res:f[i][s]=res;
}
其中：
f为记忆化数组；
i为当前处理串的第i位（权重表示法，也即后面剩下i+1位待填数）；
s为之前数字的状态（如果要求后面的数满足什么状态，也可以再记一个目标状态t之类，for的时候枚举下t）；
e表示之前的数是否是上界的前缀（即后面的数能否任意填）。
for循环枚举数字时，要注意是否能枚举0，以及0对于状态的影响，有的题目前导0和中间的0是等价的，但有的不是，对于后者可以在dfs时再加一个状态变量z，表示前面是否全部是前导0，也可以看是否是首位，然后外面统计时候枚举一下位数。It depends.
于是关键就在怎么设计状态。当然做多了之后状态一眼就可以瞄出来
。
注意：
不满足区间减法性质的话（如hdu 4376），不能用solve(r)-solve(l-1)，状态设计会更加诡异。
//不能有连续的6和2
int dp[7][3];
int digit[7];
int todigit(int n)
{
    int len=0;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    digit[len]=0;
    return len-1;
}
int dfs(int pos,int status,int limit)
{
    if(pos<0) return status!=2;
    if(!limit&&~dp[pos][status]) return dp[pos][status];
    int ans=0;
    int len=limit?digit[pos]:9;
    for(int i=0;i<=len;i++)
    {
        int ts=status;
        if(i==4) ts=2;
        else if(ts==0&&i==6) ts=1;
        else if(ts==1&&i==2) ts=2;
        else if(ts==1&&i!=2&&i!=6) ts=0;
        ans+=dfs(pos-1,ts,limit&&i==len);
    }
    return limit?ans:dp[pos][status]=ans;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)&&a+b)
    {
        memset(dp,-1,sizeof(dp));
        int ans=dfs(todigit(b),0,1)-dfs(todigit(a-1),0,1);
        printf("%d\n",ans);
    }
    return 0;
}
//记忆化搜索 HDU 1428
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=55;
const int INF=0x3f3f3f3f;
int a[MAXN][MAXN];
int dis[MAXN][MAXN];
long long dp[MAXN][MAXN];
int n;
bool used[MAXN][MAXN];

struct Node
{
    int x,y;
    int d;
    friend bool operator < (Node a,Node b)
    {
        return a.d>b.d;
    }
};
priority_queue<Node>q;

void init()
{
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    Node tmp,now;
    tmp.x=n;
    tmp.y=n;
    tmp.d=a[n][n];
    q.push(tmp);
    dis[n][n]=a[n][n];
    used[n][n]=true;
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        if(tmp.x>1 && !used[tmp.x-1][tmp.y])
        {
            now.x=tmp.x-1;
            now.y=tmp.y;
            now.d=tmp.d+a[now.x][now.y];
            q.push(now);
            dis[now.x][now.y]=now.d;
            used[now.x][now.y]=true;
        }
        if(tmp.x<n && !used[tmp.x+1][tmp.y])
        {
            now.x=tmp.x+1;
            now.y=tmp.y;
            now.d=tmp.d+a[now.x][now.y];
            q.push(now);
            dis[now.x][now.y]=now.d;
            used[now.x][now.y]=true;
        }
        if(tmp.y>1 && !used[tmp.x][tmp.y-1])
        {
            now.x=tmp.x;
            now.y=tmp.y-1;
            now.d=tmp.d+a[now.x][now.y];
            q.push(now);
            dis[now.x][now.y]=now.d;
            used[now.x][now.y]=true;
        }
        if(tmp.y<n && !used[tmp.x][tmp.y+1])
        {
            now.x=tmp.x;
            now.y=tmp.y+1;
            now.d=tmp.d+a[now.x][now.y];
            q.push(now);
            dis[now.x][now.y]=now.d;
            used[now.x][now.y]=true;
        }
    }
}

long long solve(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=0;
    if(x>1&&dis[x][y]>dis[x-1][y])dp[x][y]+=solve(x-1,y);
    if(x<n&&dis[x][y]>dis[x+1][y])dp[x][y]+=solve(x+1,y);
    if(y>1&&dis[x][y]>dis[x][y-1])dp[x][y]+=solve(x,y-1);
    if(y<n&&dis[x][y]>dis[x][y+1])dp[x][y]+=solve(x,y+1);
    return dp[x][y];

}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
          {
              scanf("%d",&a[i][j]);
              dp[i][j]=-1;
          }
        dp[n][n]=1;
        init();
        printf("%I64d\n",solve(1,1));
    }
    return 0;
}
//状态压缩
#include <cstdio>
#include <cstring>
using namespace std;
#define mod 100000000
int M,N,top = 0;
int state[600],num[110];
int dp[20][600];
int cur[20];
inline bool ok(int x)
{
    if(x&x<<1)return 0;
    return 1;
}
void init()
{
    top = 0;
    int total = 1 << N;
    for(int i = 0; i < total; ++i)
    {
        if(ok(i))state[++top] = i;
    }
}
inline bool fit(int x,int k)
{
    if(x&cur[k])return 0;
    return 1;
}
inline int jcount(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x&=(x-1);
    }
    return cnt;
}

int main()
{
    while(scanf("%d%d",&M,&N)!= EOF)
    {
        init();
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= M; ++i)
        {
            cur[i] = 0;
            int num;
            for(int j = 1; j <= N; ++j)
            {
                scanf("%d",&num);
                if(num == 0)cur[i] +=(1<<(N-j));
            }
        }
        for(int i = 1; i <= top; i++)
        {
            if(fit(state[i],1))
            {
                dp[1][i] = 1;
            }
        }
        for(int i = 2; i <= M; ++i)
        {
            for(int k = 1; k <= top; ++k)
            {
                if(!fit(state[k],i))continue;
                for(int j = 1; j <= top ; ++j)
                {
                    if(!fit(state[j],i-1))continue;
                    if(state[k]&state[j])continue;
                    dp[i][k] = (dp[i][k] +dp[i-1][j])%mod;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= top; ++i)
        {
            ans = (ans + dp[M][i])%mod;
        }
        printf("%d\n",ans);
    }
}
//插头DP
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[2][1<<11];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),(n||m))
	{
		int total=1<<m;
		int pre=0,now=1;
		memset(dp[now],0,sizeof(dp[now]));
		dp[now][0]=1;

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
		{
			swap(now,pre);
			memset(dp[now],0,sizeof(dp[now]));

			for(int S=0;S<total;S++) if( dp[pre][S] )
			{
				dp[now][S^(1<<j)]+=dp[pre][S];
				if( j && S&(1<<(j-1)) && !(S&(1<<j)) )
					dp[now][S^(1<<(j-1))]+=dp[pre][S];
			}
		}

		printf("%lld\n",dp[now][0]);
	}
}
