#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int maxn=2e6+5;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    //freopen("test.txt","r",stdin);
    int n,tmp;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        while(n--)
        {
            cin>>tmp;
            a[tmp]++;
        }
        int tot=0;
        for(int j=0;j<maxn;j++)
        {
            if(a[j]>1)
            {
                a[j+1]+=a[j]/2;
                a[j]%=2;
            }

            if(a[j]&1) tot++;
        }
        cout<<tot<<endl;
    }
    return 0;
}