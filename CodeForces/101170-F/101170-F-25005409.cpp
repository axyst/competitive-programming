#include<bits/stdc++.h>

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define rek(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int maxn=1e6+5;

int n;
int lowbit(int x){
    return x & (-x);
}

int f[maxn][21][2],g[maxn][21][2];
int log_2[maxn];
pair<int , int > a[2*maxn];

bool check(int x){
    for (int i=2*n;i>=1;i-=2) {
        if (a[i].first<=x) break;
        if (a[i].first !=a[i-1].first) continue ;
        int l=a[i-1].second,r=a[i].second;
        if (l+1==r) continue;

        l++,r--;
        int k=0;
        if (l>n) {
            k=1;
            l-=n,r-=n;
        }
        if (max(f[l][log_2[r-l+1]][k],g[r][log_2[r-l+1]][k])>x) return false;
    }
    return true;
}
int main()
{
    log_2[1]=0;
    rep(i,2,maxn) log_2[i]=log_2[i/2]+1;
    scanf("%d",&n);
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        f[i][0][0]=g[i][0][0]=x;
        a[i]=make_pair(x,i);
    }
    rep(i,1,n) {
        int x;
        scanf("%d",&x);
        f[i][0][1]=g[i][0][1]=x;
        a[n+i]=make_pair(x,n+i);
    }
    sort(a+1,a+2*n+1);
    int ans=0;
    for (int i=1;i<=2*n;i++){
        if (a[i].first==a[i+1].first&& ((a[i].second>n)^(a[i+1].second>n))){
            ans=max(ans,a[i].first);
        }
    }
    rep(k,0,1)
    rep(j,1,20)
     rep(i,1,n)
     if (i+(1<<(j))-1<=n)
      f[i][j][k]=max(f[i][j-1][k],f[i+(1<<(j-1))][j-1][k]);
    rep(k,0,1)
    rep(j,1,20)
     rep(i,1,n)
     if (i-(1<<(j))+1>=1)
      g[i][j][k]=max(g[i][j-1][k],g[i-(1<<(j-1))][j-1][k]);
    int l=ans-1,r=a[2*n].first;
    while (l+1<r){
        int mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}
close