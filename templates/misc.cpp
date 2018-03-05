//二分 hash BFS/DFS STL 基数排序 第k个元素
//分数类
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1005;const int MOD=1e9+7;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long LL;
//二分
int len;
int a[]= {1,2,3,3,4,5};
int upperbound(int key)
{
    int l=0,r=len-1;
    //cout<<l<<' '<<r<<endl;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(key>=a[mid]) l=mid+1;
        else r=mid;
    }
    return l;
}
int lowerbound(int key)
{
    int l=0,r=len-1;
    //cout<<l<<' '<<r<<endl;
    while(l<r)
    {
        int mid=l+(r+1-l)/2;
        if(key>=a[mid]) l=mid;
        else r=mid-1;
    }
    return l;
}
//hash
LL DJBhash(char str[])
{
    int len=strlen(str);
    LL hasher=5381;
    for(int i=0; i<len; i++)
        hasher=((hasher<<5)+hasher)+str[i];
    return hasher;
}
LL doublehash(int id,char* str)
{
	LL mod,pow=1,ans=0;
	if(id==1)
		mod=1000000000+7;
	else
		mod=1000000000+9;
	int n=strlen(str);
	for(int i=n-1;i>=0;i--)
	{
		LL character=str[i]-'A'+1;
		ans+=(character*pow)%mod;
		pow=(pow*59)%mod;
	}
	return ans%mod;
}
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
};
//d-BFS
bool doubleBFS(int a,int b)
{
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    queue<int>q1,q2;
    q1.push(a);
    q2.push(b);
    while(!q1.empty()||!q2.empty())
    {
        int s1=q1.size();
        int s2=q2.size();
        while(s1--)
        {
            int fr=q1.front();
            q1.pop();
            if(!vis1[fr])
            {
                vis1[fr]=1;
                q.push(get_next(fr));
            }
        }
        while(s2--)
        {
            //...
        }
    }
}
//DFS
void dfs(int cur,int fa)
{
    father[cur]=fa;
    sons[cur]=1;
    int sz=g[cur].size();
    rep(i,0,sz-1)
    {
        int son=g[cur][i].first;
        if(fa==son) continue;
        dfs(son,cur);
        sons[cur]+=sons[son];
    }
}
//STL&others
getline(istream &in,string &s);
gets(char*);
vector<int> ivec(10,1);
for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
{
    *iter=2; //使用 * 访问迭代器所指向的元素
}
multimap<int,char*>::iterator i,iend;
iend=m.end();
for(i=m.begin();i!=iend;i++)
{
    cout<<(*i).second<<"的价钱是"
    <<(*i).first<<"元/斤\n";
}
do{

}while(next_permutation(a,a+n));

//堆
vector<int>v;make_heap(v.begin(),v.end());//可以在第三个参数传入greater<int>()得到最小堆
sort_heap(v.begin(),v.end());//排序之后就不再是一个合法的heap了
pop_heap(v.begin(),v.end());v.pop_back();
v.push_back(1);push_heap(v.begin(),v.end());

nth_element(start, start+n, end);/*方法可以使第n大元素处于第n位置
（从0开始,其位置是下标为 n的元素），并且比这个元素小的元素都排在这个元素之前，
比这个元素大的元素都排在这个元素之后，但不能保证他们是有序的，
*/
rotate(begin,middle,end);//比如将串“ABCDEFG”以D为中心旋转，就相当将该串向左循环移位，直到第一个元素为D为止
remove_if(a.begin(),a.end(),cmp)//删除容器内符合条件的元素，不符合条件的元素依次往前走，返回结束位
abs();fabs();llabs();//return int;return float;return long long
//基数排序
#define base (1<<16)
int n,a[maxn],t[maxn],bucket[base+2];//a是原数组,n是元素个数，升序排列
void RadixSort(int n,int a[],int t[],int bucket[])
{
    int k,i,j;
    for(j=0;j<base;j++) bucket[i]=0;
    for(k=base-1,i=0;i<2;i++,k<<=16)
    {
        for(j=0;j<n;j++) bucket[a[j]&k]++;
        for(j=1;j<base;j++) bucket[j]+=bucket[j-1];
        for(j=n-1;j>=0;j--) t[--bucket[a[j]&k]]=a[j];
        for(j=0;j<n;j++) a[j]=t[j];
    }
}
//kth smallest
int select(int a[],int l,int r,int k)
{
    if(l==r) return a[l];
    int x=a[l+rand()%(r-l+1)],i=l,j=r;
    i--;j++;
    while(i<j)
    {
        while(a[++i]<x);while(a[--j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    if(j==r) j--;i=j-l+1;
    if(k<=i) return select(a,l,j,k);
    else return select(a,j+1,r,k-i);
}
//分数类
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
        if(f.a==0) cout<<0;
        else if(f.b==1) cout<<f.a;
        else cout<<f.a<<'/'<<f.b;
        return out;
    }
};
