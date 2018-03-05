#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 500+5;
char c[maxn][maxn];
int n,k,m,vis[maxn][maxn];
long long x,y,z;
long long ans = 0;
int dirx[4] = {0,-1,0,1};
int diry[4] = {1,0,-1,0};

struct node{
    LL x0,y0,z0;
    node(){}
    node(LL a,LL b,LL c):x0(a),y0(b),z0(c){}
};
queue<node> q;

void dfs(){
    while(!q.empty()){
        node v = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            LL midx = v.x0+dirx[i];
            LL midy = v.y0+diry[i];
            LL midz = v.z0-1;
            if(midx>=1 && midx<=n && midy <=m && midy >=1 && midz>=0
               && c[midx][midy] == '.'){
                if(vis[midx][midy] < midz ){
                    if(vis[midx][midy] == -1){ 
                        ans++;
                    }
                    vis[midx][midy]  = midz;
                    q.push(node(midx,midy,midz));
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    ans=  0;
    for(int i=0;i<505;i++){
        for(int j=0;j<505;j++){
            vis[i][j] = -1;
        }
    }
    FOR(i,1,n){
        scanf("%s",c[i]+1);
    }
    FOR(i,1,k){
        scanf("%I64d%I64d%I64d",&x,&y,&z);
        if(z>vis[x][y]){
            ans++;
            q.push(node(x,y,z));
            vis[x][y] = z;
        }
    }
    dfs();
    printf("%I64d\n",ans);
    return 0;
}
close