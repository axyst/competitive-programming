#include<bits/stdc++.h>

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
const int maxn=3e5+6;

bool coal[maxn],iron[maxn];
vector<int>a[maxn];
queue<int>q;
int rount[maxn][20];
int n,m,k;
int min_c[maxn],min_i[maxn],dis[maxn];
void solve(){
    while (!q.empty()) q.pop();
    rep(i,1,n) if (coal[i]) q.push(i);
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=0;i<a[x].size();i++)
        if (min_c[a[x][i]]>min_c[x]+1){
            min_c[a[x][i]]=min_c[x]+1;
            q.push(a[x][i]);
        }
    }
    rep(i,1,n) if (iron[i]) q.push(i);
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=0;i<a[x].size();i++)
        if (min_i[a[x][i]]>min_i[x]+1){
            min_i[a[x][i]]=min_i[x]+1;
            q.push(a[x][i]);
        }
    }
    rep(i,1,n) dis[i]=maxn;
    dis[1]=0;
    q.push(1);
     while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=1;i<=rount[x][0];i++)
        if (dis[rount[x][i]]>dis[x]+1){
            dis[rount[x][i]]=dis[x]+1;
            q.push(rount[x][i]);
        }
    }
    int ans=maxn;
    rep(i,1,n) ans=min(ans,dis[i]+min_i[i]+min_c[i]);
    if (ans!=maxn) printf("%d\n",ans);else printf("impossible\n");
}
int main()
{
    rep(i,1,n) a[i].clear();
    scanf("%d%d%d",&n,&m,&k);
    memset(coal,0,sizeof(coal));
    memset(iron,0,sizeof(iron));
    rep(i,1,m) {
        int x;
        scanf("%d",&x);
        coal[x]=1;
    }
    rep(i,1,k) {
        int x;
        scanf("%d",&x);
        iron[x]=1;
    }
    rep(i,1,n){
        scanf("%d",&rount[i][0]);
        rep(j,1,rount[i][0]) scanf("%d",&rount[i][j]);
        rep(j,1,rount[i][0]) a[rount[i][j]].push_back(i);
        min_c[i]=maxn;
        min_i[i]=maxn;
    }
    rep(i,1,n) {
        if (coal[i]) min_c[i]=0;
        if (iron[i]) min_i[i]=0;
    }
    solve();
    return 0;
}