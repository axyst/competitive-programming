#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=105;
int G[maxn][maxn],color[maxn],diff[maxn];
int d[maxn][maxn<<1],teamno[maxn];
int n,cc;
vector<int>team[maxn][2];
bool dfs(int u,int c)
{
    //color of current people
    color[u]=c;
    //add current people to team
    team[cc][c-1].push_back(u);
    //for each other people who are not connected with this people
    for(int i=0;i<n;i++)
    {
        if(i==u||(G[u][i]&&G[i][u])) continue;
        //if they have same color,it is not bi-graph
        if(color[u]==color[i]&&color[i]>0) return 0;
        //if the other person have no color and coloring it to opposite
        //color fails,it is not bi-graph
        if(!color[i]&&!dfs(i,3-c)) return 0;
    }
    //otherwise,is bi-graph
    return 1;
}
bool build_graph()
{
    //reset color and cc
    memset(color,0,sizeof(color));cc=0;
    //for each people
    //if this people don't have color,cc++ after doing these:
    for(int i=0;i<n;i++)
    {
        if(!color[i])
        {
            //clear teams of this cc
            team[cc][0].clear();
            team[cc][1].clear();
            //if coloring this person to 0 doesn't work,return false
            if(!dfs(i,1)) return 0;
            //calculate difference of cc
            diff[cc]=team[cc][0].size()-team[cc][1].size();
            cc++;
        }
    }
    //return true
    return 1;
}
void print(int ans)
{
    vector<int>team1,team2;
    //for each cc
    for(int i=cc-1;i>=0;i--)
    {
        //determine if ans-=difference or ans+=difference,and flag
        int flag=1;
        if(d[i][ans-diff[i]+n]){flag=0,ans-=diff[i];}
        else ans+=diff[i];
        //for each team 1 and 2 of cc,push persons of team depending on flag,into it
        for(int j=0;j<team[i][flag].size();j++)
            team1.push_back(team[i][flag][j]);
        for(int j=0;j<team[i][flag^1].size();j++)
            team2.push_back(team[i][flag^1][j]);
    }
    //print people of team 1 and 2
    printf("%d",team1.size());
    for(int i=0;i<team1.size();i++) printf(" %d",team1[i]+1);
    printf("\n");
    printf("%d",team2.size());
    for(int i=0;i<team2.size();i++) printf(" %d",team2[i]+1);
    printf("\n");

}
void dp()
{
    //reset d
    memset(d,0,sizeof(d));d[0][n]=1;
    //for each cc
    //for each n+person number(positive or minus)
    for(int i=0;i<cc;i++)
        for(int j=-n;j<=n;j++)
    //if dp isn't 0,update the two next dp
        if(d[i][j+n])
    {
        d[i+1][j+n+diff[i]]=1;
        d[i+1][j+n-diff[i]]=1;
    }

    //for each person number,if dp of this cc and it exists,print this
    //person number and its negative value
    for(int i=0;i<=n;i++)
        if(d[cc][i+n]){print(i);return;}
        else if(d[cc][-i+n]){print(-i);return;}
}
int main()
{
    //freopen("test.txt","r",stdin);
    int t,tmp;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++)
            while(scanf("%d",&tmp)&&tmp) G[i][tmp-1]=1;
        if(n==1||!build_graph()) printf("No solution\n");
        else dp();
        if(t) printf("\n");
    }
    return 0;
}
