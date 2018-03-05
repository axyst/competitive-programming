#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=10000+5;
const double eps=1e-6;
int out[maxn];
struct point
{
    int x;int y;int id;
}pts[maxn];
bool cmp(point a,point b){return a.x<b.x;}
int cmp2(double a,double b)
{
    if(fabs(a-b)<eps) return 0;
    if(a>b) return 1;
    return -1;
}
double cross(int a,int b)
{
    return ((pts[b].y-pts[a].y)*1.0)/((pts[b].x-pts[a].x)*1.0);
}
int main()
{
    ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>pts[i].x>>pts[i].y,pts[i].id=i;
    sort(pts,pts+n,cmp);
    double lw=-INF;int cnt=0;
    for(int i=1;i<n;)
    {
        double tmp=cross(i,i+1);
        int ans=cmp2(tmp,lw);
        if(ans==1)
        {
            lw=tmp;
            cnt=0;
            out[cnt++]=i;
            out[cnt++]=i+1;
        }
        else if(!ans) out[cnt++]=i+1;
        i++;
        while(i<n&&cmp2(cross(i-1,i),cross(i,i+1))>0) i++;
    }
    for(int i=0;i<cnt;i++) cout<<pts[out[i]].id+1<<' ';
    cout<<endl;
    return 0;
}
