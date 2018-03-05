#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rel(i,n) for(int (i)=1;(i)<=(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
const int INF = 0x3f3f3f3f;const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long MAXN=1e5+5;const long long MOD=1e8+7;
typedef vector<int> vci; typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
const double PI=3.1415926535897932384626;
const double eps=1e-6;
char op[10];
int main()
{
    cin>>op;
    if(op[0]=='a'||op[0]=='h')
    {
        if(op[1]=='1'||op[1]=='8')
        {
            cout<<"3"<<endl;
            return 0;
        }
        else
        {
            cout<<"5"<<endl;
            return 0;
        }
    }
    else if(op[1]=='1'||op[1]=='8')
    {
        cout<<"5"<<endl;
        return 0;
    }
    else
    {
        cout<<"8"<<endl;
        return 0;
    }
}