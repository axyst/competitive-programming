#include<bits/stdc++.h>
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);++(i))
#define mem(n) memset((n),0,sizeof((n)))
#define si(n) scanf("%d",&(n))
#define sl(n) scanf("%I64d",&(n))
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;

char zero[10][10]=
{
".XX.",
"X..X",
"X..X",
"....",
"X..X",
"X..X",
".XX."
};
char one[10][10]=
{
"...X",
"...X",
"...X",
"....",
"...X",
"...X",
"...X"
};
char two[10][10]=
{
".XX.",
"...X",
"...X",
".XX.",
"X...",
"X...",
".XX."
};
char three[10][10]=
{
".XX.",
"...X",
"...X",
".XX.",
"...X",
"...X",
".XX."
};
char four[10][10]=
{
"X..X",
"X..X",
"X..X",
".XX.",
"...X",
"...X",
"...X"
};
char five[10][10]=
{
".XX.",
"X...",
"X...",
".XX.",
"...X",
"...X",
".XX."
};
char six[10][10]=
{
".XX.",
"X...",
"X...",
".XX.",
"X..X",
"X..X",
".XX."
};
char seven[10][10]=
{
".XX.",
"...X",
"...X",
"....",
"...X",
"...X",
"...X"
};
char seven2[10][10]=
{
".XX.",
"...X",
"...X",
"....",
"...X",
"...X",
"...."
};
char eight[10][10]=
{
".XX.",
"X..X",
"X..X",
".XX.",
"X..X",
"X..X",
".XX."
};
char nine[10][10]=
{
".XX.",
"X..X",
"X..X",
".XX.",
"...X",
"...X",
".XX."
};
bool is[11][5];
char inp[50][50];
char tes[50];
int main()
{
    //std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;si(t);
    while(t--)
    {
        rep(i,0,6) scanf("%s",&inp[i]);
        int fir=-1,sec=-1,thi=-1,fou=-1;
        memset(is,0,sizeof(is));

        rep(i,0,6)
        {
            bool hasmid=0;
            rep(j,0,3)
            {
                if(inp[3][2]=='X') hasmid=1;
                if(inp[i][j]!=zero[i][j]) is[0][0]=1;
                if(inp[i][j]!=one[i][j]) is[1][0]=1;
                if(inp[i][j]!=two[i][j]) is[2][0]=1;
                if(inp[i][j]!=three[i][j]) is[3][0]=1;
                if(inp[i][j]!=four[i][j]) is[4][0]=1;
                if(inp[i][j]!=five[i][j]) is[5][0]=1;
                if(inp[i][j]!=six[i][j]) is[6][0]=1;
                if(inp[i][j]!=seven[i][j]) is[7][0]=1;
                if(inp[i][j]!=seven2[i][j]) is[10][0]=1;
                if(inp[i][j]!=eight[i][j]) is[8][0]=1;
                if(inp[i][j]!=nine[i][j]) is[9][0]=1;
            }
            if(!hasmid)
            {
                if(inp[0][1]=='.') is[1][0]=0;
            }
            hasmid=0;
            rep(j,5,8)
            {
                if(inp[3][7]=='X') hasmid=1;
                if(inp[i][j]!=zero[i][j-5]) is[0][1]=1;
                if(inp[i][j]!=one[i][j-5]) is[1][1]=1;
                if(inp[i][j]!=two[i][j-5]) is[2][1]=1;
                if(inp[i][j]!=three[i][j-5]) is[3][1]=1;
                if(inp[i][j]!=four[i][j-5]) is[4][1]=1;
                if(inp[i][j]!=five[i][j-5]) is[5][1]=1;
                if(inp[i][j]!=six[i][j-5]) is[6][1]=1;
                if(inp[i][j]!=seven[i][j-5]) is[7][1]=1;
                if(inp[i][j]!=seven2[i][j-5]) is[10][1]=1;
                if(inp[i][j]!=eight[i][j-5]) is[8][1]=1;
                if(inp[i][j]!=nine[i][j-5]) is[9][1]=1;
            }
            if(!hasmid)
            {
                if(inp[0][6]=='.') is[1][1]=0;
            }
            hasmid=0;
            rep(j,12,15)
            {
                if(inp[3][13]=='X') hasmid=1;
                if(inp[i][j]!=zero[i][j-12]) is[0][2]=1;
                if(inp[i][j]!=one[i][j-12]) is[1][2]=1;
                if(inp[i][j]!=two[i][j-12]) is[2][2]=1;
                if(inp[i][j]!=three[i][j-12]) is[3][2]=1;
                if(inp[i][j]!=four[i][j-12]) is[4][2]=1;
                if(inp[i][j]!=five[i][j-12]) is[5][2]=1;
                if(inp[i][j]!=six[i][j-12]) is[6][2]=1;
                if(inp[i][j]!=seven[i][j-12]) is[7][2]=1;
                if(inp[i][j]!=seven2[i][j-12]) is[10][2]=1;
                if(inp[i][j]!=eight[i][j-12]) is[8][2]=1;
                if(inp[i][j]!=nine[i][j-12]) is[9][2]=1;
            }
            if(!hasmid)
            {
                if(inp[0][13]=='.') is[1][2]=0;
            }
            hasmid=0;
            rep(j,17,20)
            {
                if(inp[3][18]=='X') hasmid=1;
                if(inp[i][j]!=zero[i][j-17]) is[0][3]=1;
                if(inp[i][j]!=one[i][j-17]) is[1][3]=1;
                if(inp[i][j]!=two[i][j-17]) is[2][3]=1;
                if(inp[i][j]!=three[i][j-17]) is[3][3]=1;
                if(inp[i][j]!=four[i][j-17]) is[4][3]=1;
                if(inp[i][j]!=five[i][j-17]) is[5][3]=1;
                if(inp[i][j]!=six[i][j-17]) is[6][3]=1;
                if(inp[i][j]!=seven[i][j-17]) is[7][3]=1;
                if(inp[i][j]!=seven2[i][j-17]) is[10][3]=1;
                if(inp[i][j]!=eight[i][j-17]) is[8][3]=1;
                if(inp[i][j]!=nine[i][j-17]) is[9][3]=1;
            }
            if(!hasmid)
            {
                if(inp[0][18]=='.') is[1][3]=0;
            }
        }
        rep(j,0,10)
        {
            if(!is[j][0]&&j!=10) fir=j;
            if(!is[j][0]&&j==10) fir=7;
            if(!is[j][1]&&j!=10) sec=j;
            if(!is[j][1]&&j==10) sec=7;
            if(!is[j][2]&&j!=10) thi=j;
            if(!is[j][2]&&j==10) thi=7;
            if(!is[j][3]&&j!=10) fou=j;
            if(!is[j][3]&&j==10) fou=7;
        }
        if(fir==-1) fir=4;
        if(sec==-1) sec=4;
        if(thi==-1) thi=4;
        if(fou==-1) fou=4;
        printf("%d%d:%d%d\n",fir,sec,thi,fou);

    }
    return 0;
}