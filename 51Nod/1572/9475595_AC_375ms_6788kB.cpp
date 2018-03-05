#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int x[30];int y[30];
int n,m,k;
int mp[1005][1005];
char pic[1005];
int op[maxn];
int times[maxn];
char tmp[25];
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",pic+1);
        for(int j=1;j<=m;j++)
            if(pic[j]=='#') mp[i][j]=1;
            else if(pic[j]!='.')
            {
                int id=pic[j]-'A';
                x[id]=i,y[id]=j;
            }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        mp[i][j]+=(mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]);
    scanf("%d",&k);
    int ten;
    for(int i=1;i<=k;i++)
    {
        scanf("%s",tmp);
        if(tmp[0]=='N') op[i]=0;
        else if(tmp[0]=='S') op[i]=1;
        else if(tmp[0]=='E') op[i]=3;
        else if(tmp[0]=='W') op[i]=2;
        scanf("%d",times+i);
        //cout<<op[i]<<' '<<times[i]<<endl;
    }
    bool flag=0;
    for(int j=0;j<26;j++)
        if(x[j])
        {
            int xx=x[j],yy=y[j];
            bool ok=1;
            for(int i=1;i<=k;i++)
            {
                if(op[i]==0)
                {
                    int nx=xx-times[i];
                    if(nx<=0||yy<=0||nx>n||yy>m){ok=0;break;}
                    if(mp[nx-1][yy-1]+mp[xx][yy]-mp[nx-1][yy]-mp[xx][yy-1])
                        {ok=0;break;}
                    xx-=times[i];
                }
                else if(op[i]==1)
                {
                    int nx=xx+times[i];
                    if(nx<=0||yy<=0||nx>n||yy>m){ok=0;break;}
                    if(mp[xx-1][yy-1]+mp[nx][yy]-mp[xx-1][yy]-mp[nx][yy-1])
                        {ok=0;break;}
                    xx+=times[i];
                }
                else if(op[i]==2)
                {
                    int ny=yy-times[i];
                    if(xx<=0||ny<=0||xx>n||ny>m){ok=0;break;}
                    if(mp[xx-1][ny-1]+mp[xx][yy]-mp[xx-1][yy]-mp[xx][ny-1])
                        {ok=0;break;}
                    yy-=times[i];
                }
                else if(op[i]==3)
                {
                    int ny=yy+times[i];
                    if(xx<=0||ny<=0||xx>n||ny>m){ok=0;break;}
                    if(mp[xx-1][yy-1]+mp[xx][ny]-mp[xx-1][ny]-mp[xx][yy-1])
                        {ok=0;break;}
                    yy+=times[i];
                }
            }
            if(!ok) continue;
            printf("%c",j+'A');
            flag=1;
        }
    if(!flag)
    {
        printf("no solution");
    }
    printf("\n");
    return 0;
}
