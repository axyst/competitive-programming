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
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN=1005;
const int MOD=1e9+7;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
//叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
//点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
//绕原点旋转角度B（弧度值），后x,y的变化
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
};
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
//两直线相交求交点
//第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
//只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};
//两点间距离
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
//判断线段相交
bool inter(Line l1,Line l2)
{
    return
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
        sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
//判断直线和线段相交
bool Seg_inter_line(Line l1,Line l2) //判断直线l1和线段l2是否相交
{
    return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
}
//点到直线距离
//返回为result,是点到直线最近的点
Point PointToLine(Point P,Line L)
{
    Point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    result.x = L.s.x + (L.e.x-L.s.x)*t;
    result.y = L.s.y + (L.e.y-L.s.y)*t;
    return result;
}
//点到线段的距离
//返回点到线段最近的点
Point NearestPointToLineSeg(Point P,Line L)
{
    Point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t >= 0 && t <= 1)
    {
        result.x = L.s.x + (L.e.x - L.s.x)*t;
        result.y = L.s.y + (L.e.y - L.s.y)*t;
    }
    else
    {
        if(dist(P,L.s) < dist(P,L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
}
//计算多边形面积
//点的编号从0~n-1
double CalcArea(Point p[],int n)
{
    double res = 0;
    for(int i = 0; i < n; i++)
        res += (p[i]^p[(i+1)%n])/2;
    return fabs(res);
}
//*判断点在线段上
bool OnSeg(Point P,Line L)
{
    return
        sgn((L.s-P)^(L.e-P)) == 0 &&
        sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
        sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
//*判断点在凸多边形内
//点形成一个凸包，而且按逆时针排序（如果是顺时针把里面的<0改为>0）
//点的编号:0~n-1
//返回值：
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inConvexPoly(Point a,Point p[],int n)
{
    for(int i = 0; i < n; i++)
    {
        if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
        else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
    }
    return 1;
}
//*判断点在任意多边形内
//射线法， poly[]的顶点数要大于等于3,点的编号0~n-1
//返回值
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inPoly(Point p,Point poly[],int n)
{
    int cnt;
    Line ray,side;
    cnt = 0;
    ray.s = p;
    ray.e.y = p.y;
    ray.e.x = -100000000000.0;//-INF,注意取值防止越界
    for(int i = 0; i < n; i++)
    {
        side.s = poly[i];
        side.e = poly[(i+1)%n];
        if(OnSeg(p,side))return 0;
//如果平行轴则不考虑
        if(sgn(side.s.y - side.e.y) == 0)
            continue;
        if(OnSeg(side.s,ray))
        {
            if(sgn(side.s.y - side.e.y) > 0)cnt++;
        }
        else if(OnSeg(side.e,ray))
        {
            if(sgn(side.e.y - side.s.y) > 0)cnt++;
        }
        else if(inter(ray,side))
            cnt++;
    }
    if(cnt % 2 == 1)return 1;
    else return -1;
}
//判断凸多边形
//允许共线边
//点可以是顺时针给出也可以是逆时针给出
//点的编号1~n-1
bool isconvex(Point poly[],int n)
{
    bool s[3];
    memset(s,false,sizeof(s));
    for(int i = 0; i < n; i++)
    {
        s[sgn( (poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]) )+1] = true;
        if(s[0] && s[2])return false;
    }
    return true;
}
/*
* 求凸包， Graham算法
* 点的编号0~n-1
* 返回凸包结果Stack[0~top-1]为凸包的编号
*/
const int MAXN = 1010;
Point plist[MAXN];
int Stack[MAXN],top;
//相对于plist[0]的极角排序
bool _cmp(Point p1,Point p2)
{
    double tmp = (p1-plist[0])^(p2-plist[0]);
    if(sgn(tmp) > 0)return true;
    else if(sgn(tmp) == 0 && sgn(dist(p1,plist[0]) - dist(p2,plist[0])) <= 0)
        return true;
    else return false;
}
void Graham(int n)
{
    Point p0;
    int k = 0;
    p0 = plist[0];
//找最下边的一个点
    for(int i = 1; i < n; i++)
    {
        if( (p0.y > plist[i].y) || (p0.y == plist[i].y && p0.x > plist[i].x) )
        {
            p0 = plist[i];
            k = i;
        }
    }
    swap(plist[k],plist[0]);
    sort(plist+1,plist+n,_cmp);
    if(n == 1)
    {
        top = 1;
        Stack[0] = 0;
        return;
    }
    if(n == 2)
    {
        top = 2;
        Stack[0] = 0;
        Stack[1] = 1;
        return ;
    }
    Stack[0] = 0;
    Stack[1] = 1;
    top = 2;
    for(int i = 2; i < n; i++)
    {
        while(top > 1 &&sgn((plist[Stack[top-1]]-plist[Stack[top-2]])^(plist[i]-plist[Stack[top-2]])) <=0)
            top--;
        Stack[top++] = i;
    }
}
//平面最近点对
Point p[MAXN];
Point tmpt[MAXN];
bool cmpxy(Point a,Point b)
{
    if(a.x != b.x)return a.x < b.x;
    else return a.y < b.y;
}
bool cmpy(Point a,Point b)
{
    return a.y < b.y;
}
double Closest_Pair(int left,int right)
{
    double d = inf;
    if(left == right)return d;
    if(left + 1 == right)
        return dist(p[left],p[right]);
    int mid = (left+right)/2;
    double d1 = Closest_Pair(left,mid);
    double d2 = Closest_Pair(mid+1,right);
    d = min(d1,d2);
    int k = 0;
    for(int i = left; i <= right; i++)
    {
        if(fabs(p[mid].x - p[i].x) <= d)
            tmpt[k++] = p[i];
    }
    sort(tmpt,tmpt+k,cmpy);
    for(int i = 0; i <k; i++)
    {
        for(int j = i+1; j < k && tmpt[j].y - tmpt[i].y < d; j++)
        {
            d = min(d,dist(tmpt[i],tmpt[j]));
        }
    }
    return d;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmpxy);
        printf("%.2lf\n",Closest_Pair(0,n-1)/2);
    }
    return 0;
}
//平面最远点对(旋转卡壳)
///距离的平方
int dist2(Point a,Point b)
{
    return (a-b)*(a-b);
}
///******二维凸包， int***********
Point glist[MAXN];
int gstack[MAXN],gtop;

///旋转卡壳，求两点间距离平方的最大值
int rotating_calipers(Point p[],int n)
{
    int ans = 0;
    Point v;
    int cur = 1;
    for(int i = 0; i < n; i++)
    {
        v = p[i]-p[(i+1)%n];
        while((v^(p[(cur+1)%n]-p[cur])) < 0)
            cur = (cur+1)%n;
        ans = max(ans,max(dist2(p[i],p[cur]),dist2(p[(i+1)%n],p[(cur+1)%n])));
    }
    return ans;
}

///旋转卡壳计算平面点集最大三角形面积
int rotating_calipers3(Point p[],int n)
{
    double ans = 0;
    Point v;
    for(int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        int k = (j+1)%n;
        while(j != i && k != i)
        {
            ans = max(ans,abs((p[j]-p[i])^(p[k]-p[i])));
            while( ((p[i]-p[j])^(p[(k+1)%n]-p[k])) < 0 )
                k = (k+1)%n;
            j = (j+1)%n;
        }
    }
    return ans;
}
Point ppp[MAXN];
/*
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n == -1)break;
        for(int i = 0; i < n; i++)glist[i].input();
        Graham(n);
        for(int i = 0; i < gtop; i++)ppp[i] = glist[gstack[i]];
        printf("%.2f\n",(double)rotating_calipers3(ppp,gtop)/2);
    }
    return 0;
}
*/
//过三点求圆心坐标
Point waixin(Point a,Point b,Point c)
{
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;
    double d = a1*b2 - a2*b1;
    return Point(a.x + (c1*b2 - c2*b1)/d, a.y + (a1*c2 -a2*c1)/d);
}


//通过两点，确定直线方程
void Get_equation(Point p1,Point p2,double &a,double &b,double &c)
{
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = p2.x*p1.y - p1.x*p2.y;
}
//求交点
Point Intersection(Point p1,Point p2,double a,double b,double c)
{
    double u = fabs(a*p1.x + b*p1.y + c);
    double v = fabs(a*p2.x + b*p2.y + c);
    Point t;
    t.x = (p1.x*v + p2.x*u)/(u+v);
    t.y = (p1.y*v + p2.y*u)/(u+v);
    return t;
}
Point tp[110];
void Cut(double a,double b,double c,Point p[],int &cnt)
{
    int tmp = 0;
    for(int i = 1; i <= cnt; i++)
    {
//当前点在左侧，逆时针的点
        if(a*p[i].x + b*p[i].y + c < eps)tp[++tmp] = p[i];
        else
        {
            if(a*p[i-1].x + b*p[i-1].y + c < -eps)
                tp[++tmp] = Intersection(p[i-1],p[i],a,b,c);
            if(a*p[i+1].x + b*p[i+1].y + c < -eps)
                tp[++tmp] = Intersection(p[i],p[i+1],a,b,c);
        }
    }
    for(int i = 1; i <= tmp; i++)
        p[i] = tp[i];
    p[0] = p[tmp];
    p[tmp+1] = p[1];
    cnt = tmp;
}
double V[110],U[110],W[110];
int n;
const double INF = 100000000000.0;
Point pts[110];
bool solve(int id)
{
    pts[1] = Point(0,0);
    pts[2] = Point(INF,0);
    pts[3] = Point(INF,INF);
    pts[4] = Point(0,INF);
    pts[0] = pts[4];
    pts[5] = pts[1];
    int cnt = 4;
    for(int i = 0; i < n; i++)
        if(i != id)
        {
            double a = (V[i] - V[id])/(V[i]*V[id]);
            double b = (U[i] - U[id])/(U[i]*U[id]);
            double c = (W[i] - W[id])/(W[i]*W[id]);
            if(sgn(a) == 0 && sgn(b) == 0)
            {
                if(sgn(c) >= 0)return false;
                else continue;
            }
            Cut(a,b,c,p,cnt);
        }
    if(sgn(CalcArea(p,cnt)) == 0)return false;
    else return true;
}
/*
int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%lf",&V[i],&U[i],&W[i]);
        for(int i = 0; i < n; i++)
        {
            if(solve(i))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
*/
