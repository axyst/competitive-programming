#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int vis[10][10][10][10];
int prime[1500];
struct node
{
    int num[4];
    int step;
}in,out;
int cnt=0;
void printprime()
{
    //prime[0]=2;
    //prime[1]=3;
    for(int i=1001;i<9999;i+=2)
    {
        int flag=1;
        for(int j=3;j*j<=i;j++)if(i%j==0) {flag=0;break;}
        if(flag)prime[cnt++]=i;
    }
}
bool isprime(int str[])
{
    int a=str[0]*1000+str[1]*100+str[2]*10+str[3];
    for(int i=0;i<cnt;i++) if(prime[i]==a) return 1;
    return 0;
}
bool check(node a,node b)
{
    for(int i=0;i<4;i++)
        if(a.num[i]!=b.num[i]) return 0;
    return 1;
}
int bfs(node a,node b)
{
    memset(vis,0,sizeof(vis));
    queue<node>q;
    node u;
    vis[a.num[0]][a.num[1]][a.num[2]][a.num[3]]=1;
    q.push(a);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        //if(check(u,b)) return u.step;
        for(int i=0;i<4;i++)
            for(int j=0;j<=9;j++)
            {
                node next=u;
                if(i==3&&j%2==0||u.num[i]==j) continue;
                next.num[i]=j;
                if(isprime(next.num)&&!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]])
                {
                    //for(int i=0;i<4;i++) printf("%d",next.num[i]);
                    //printf("\n");
                    //printf("%d%d%d%d\n",next.num[0],next.num[1],next.num[2],next.num[3]);
                    next.step=u.step+1;
                    vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]=1;
                    q.push(next);
                }
                if(check(next,b)) return next.step;

            }
        if(check(u,b)) return u.step;
    }
    return -1;
}

int main()
{
    printprime();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int aa,bb;
        in.step=0;
        scanf("%d %d",&aa,&bb);
        for(int i=3;i>=0;i--)
        {
            in.num[i]=aa%10;
            out.num[i]=bb%10;
            aa/=10;
            bb/=10;
        }
        int ans=bfs(in,out);
        if(ans!=-1) printf("%d\n",ans);
        else printf("Impossible\n");
    }
    return 0;
}
/*
int main()
{
    printprime();
    for(int i=0;i<20;i++) printf("%d\n",prime[i]);
}
*/