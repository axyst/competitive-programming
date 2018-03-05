#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
char val[17];
map<string,double>mp;
int main()
{
    int t,c,n;scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d%d",&c,&n);
        for(int i=0;i<c;i++)
        {
            double tmp;
            scanf("%s%lf",val,&tmp);
            string s=val;
            mp[s]=tmp;
        }
        mp["JD"]=1;
        double sum=0;
        for(int i=0;i<n;i++)
        {
            double tmp;
            scanf("%lf%s",&tmp,val);
            string s=val;
            sum+=1.0*tmp*mp[s];
        }
        printf("%.6lf\n",sum);
    }
    return 0;
}
