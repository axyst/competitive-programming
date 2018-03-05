#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
    int num[4];
    int step;
};
queue<node> q[2];//开两个队列，分别从两头进行搜索
int vis[2][10][10][10][10];//队列名+数字
int ansnum[4];
int ans;
void init()
{
    ans=-1;
    memset(vis,-1,sizeof(vis));
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
}
bool istrue(node x,int i)
{
    if(vis[1^i][x.num[0]][x.num[1]][x.num[2]][x.num[3]]!=-1)//另一队列已经搜索过这个数
        return 1;
    return 0;
}
bool judge(node x,int i)
{
    if(vis[i][x.num[0]][x.num[1]][x.num[2]][x.num[3]]!=-1)//已经搜索过这个数
        return 0;
    return 1;
}
node change(node a,int b)
{
    a.step++;
    if(b<4)//0 1 2 3 +
    {
        if(a.num[b]==9) a.num[b]=1;
        else a.num[b]++;
    }
    else if(b<8)//4 5 6 7 -
    {
        if(a.num[b%4]==1) a.num[b%4]=9;
        else a.num[b%4]--;
    }
    else//8 9 10 swap
    {
        int tmp;
        b%=4;
        tmp=a.num[b];
        a.num[b]=a.num[b+1];
        a.num[b+1]=tmp;
    }
    return a;
}
void bfs(int j)//参数为队列名
{
    node now,next;
    if(ans!=-1||q[j].empty()) return;
    int first=q[j].front().step;
    while(!q[j].empty()&&q[j].front().step==first)//直到队列为空或者次数改变
    {
        now=q[j].front();
        q[j].pop();
        if(istrue(now,j))//头尾搜到一起，结束搜索
        {
            ans=vis[j][now.num[0]][now.num[1]][now.num[2]][now.num[3]]+vis[1^j][now.num[0]][now.num[1]][now.num[2]][now.num[3]];
            return;
        }
        for(int i=0;i<11;i++)
        {
            next=change(now,i);//换数字
            if(judge(next,j))
            {
                vis[j][next.num[0]][next.num[1]][next.num[2]][next.num[3]]=next.step;
                q[j].push(next);
            }
        }
    }
}
void db_bfs()
{
    while(ans==-1)//每轮进行两次bfs
    {
        bfs(0);
        bfs(1);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();//ans,vis,q的初始化
        int a,b;
        node now0,now1;//把输入转化为node
        scanf("%d %d",&a,&b);
        for(int i=3;i>=0;i--)
        {
            now0.num[i]=a%10;
            now1.num[i]=b%10;
            a/=10;
            b/=10;
        }
        now0.step=0;//node分别加入两个队列
        q[0].push(now0);
        vis[0][now0.num[0]][now0.num[1]][now0.num[2]][now0.num[3]]=0;
        now1.step=0;
        q[1].push(now1);
        vis[1][now1.num[0]][now1.num[1]][now1.num[2]][now1.num[3]]=0;
        db_bfs();
        printf("%d\n",ans);
    }
    return 0;
}