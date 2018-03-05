#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int x[205],y[205],z[205];
int xv[205],yv[205],zv[205];
int vis[205][205][205];
struct sq
{
    int x;int y;int z;
};
int dx[]={-1,1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,-1,1};
int n;
int compress(int *ori,int *val,int n)
{
    memcpy(val,ori,sizeof(int)*n);//x to xv
    val[n]=-1;//outer air
    sort(val,val+n+1);
    int m=unique(val,val+n+1)-val;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(ori[i]==val[j]) {ori[i]=j;break;}
    return m;
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<2*n;i+=2)
        {
            scanf("%d%d%d%d%d%d",x+i,y+i,z+i,x+i+1,y+i+1,z+i+1);
            x[i+1]+=x[i],y[i+1]+=y[i],z[i+1]+=z[i];
        }
        int xn=compress(x,xv,2*n);
        int yn=compress(y,yv,2*n);
        int zn=compress(z,zv,2*n);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<2*n;i+=2)
        for(int j=x[i];j<x[i+1];j++)
        for(int k=y[i];k<y[i+1];k++)
        for(int l=z[i];l<z[i+1];l++)
        {
            vis[j][k][l]=1;
        }

        vis[0][0][0]=-1;
        queue<sq>q;
        sq stp;stp.x=0;stp.y=0;stp.z=0;
        q.push(stp);

        while(!q.empty())
        {
            sq fr=q.front();
            q.pop();

            for(int i=0;i<6;i++)
            {
                int nx=fr.x+dx[i];int ny=fr.y+dy[i];int nz=fr.z+dz[i];
                if(nx<0||ny<0||nz<0||nx>=xn||ny>=yn||nz>=zn||vis[nx][ny][nz]) continue;
                vis[nx][ny][nz]=-1;
                sq nxt;nxt.x=nx;nxt.y=ny;nxt.z=nz;
                q.push(nxt);
            }
        }
        LL vol=0,area=0;
        for(int i=1;i<xn-1;i++)
        for(int j=1;j<yn-1;j++)
        for(int k=1;k<zn-1;k++)
        {
            int sx=xv[i+1]-xv[i],sy=yv[j+1]-yv[j],sz=zv[k+1]-zv[k];
            if(vis[i][j][k]!=-1) vol+=(LL)sx*sy*sz;//no air here
            for(int l=0;l<6;l++)
            {
                if(vis[i][j][k]!=-1&&vis[i+dx[l]][j+dy[l]][k+dz[l]]==-1)//is surface
                {
                    int yy=dy[l]?sx*sz:sx*sy;
                    area+=dx[l]?sy*sz:yy;
                }
            }
        }
        printf("%lld %lld\n",area,vol);
    }
    return 0;
}
