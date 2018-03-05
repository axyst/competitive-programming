/*
看了代码仓库，如果换是我，大概直接把color写point里了，然后在排序时多写一堆代码……
第一次接触这种扫描，先把点按相对角度排序，枚举左端点，然后维护右区间直到两区间的对应点张成一条直线
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1005;
struct point
{
    int x,y;double rad;
}midp[maxn],p[maxn];
int n,color[maxn];
bool xmul(point a,point b)
{
    return a.x*b.y-a.y*b.x>=0;
}
bool cmp(point a,point b)
{
    return a.rad<b.rad;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)&&n)
    {
        if(n<=2)
        {
            printf("2\n");
            continue;
        }
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&midp[i].x,&midp[i].y,color+i);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                p[cnt].x=midp[j].x-midp[i].x;
                p[cnt].y=midp[j].y-midp[i].y;
                if(color[j])p[cnt].x=-p[cnt].x,p[cnt].y=-p[cnt].y;
                p[cnt].rad=atan2(p[cnt].y,p[cnt].x);
                cnt++;
            }
            sort(p,p+cnt,cmp);
            int l=0,r=0,num=2;
            while(l<cnt)
            {
                if(l==r){r=(r+1)%cnt;num++;continue;}
                while(r!=l&&xmul(p[l],p[r])){r=(r+1)%cnt;num++;}
                l++;
                num--;
                ans=max(ans,num);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
